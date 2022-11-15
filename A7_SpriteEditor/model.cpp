#include "model.h"
#include "frame.h"
#include "qpixmap.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QImage>
#include <QTimer>
#include <QPixmap>

Model::Model(int spriteSize, QObject *parent)
    : QObject{parent}, frameSize(spriteSize), playingAnimation(false)
{
     //get FrameSize from view
    Frame newFrame(frameSize);
    frames.append(newFrame);
}

// Testing this branch
Model::~Model() {}

//slot to add a blank new frame
void Model::addFrame()
{
    Frame newFrame(frameSize);
    frames.append(newFrame);
    activeFramePointer = frames.length() - 1;
    updateView();
}


// Slot to duplicate selected frame
void Model::duplicateFrame() {
    frames.append(frames[activeFramePointer]);
    activeFramePointer = frames.length() - 1;
    updateView();
}

//slot to remove current frame
void Model::removeFrame()
{
    frames.removeAt(activeFramePointer);
    if(activeFramePointer == frames.length()){
        activeFramePointer--;
    }
    sendPreviewArray();
    updateView();
}

//helper method for emitting signals to update the view
void Model::updateView(){
    emit sendNumberOfFrames(frames.length());
    sendPreviewArray();
    emit frameEditorUpdate(frames[activeFramePointer]);
    emit sendFrameIndex(activeFramePointer);
}

//SLot for updating active frame pointer
void Model::updateCurrentFramePointer(int index)
{
    activeFramePointer = index;
    emit frameEditorUpdate(frames.at(activeFramePointer));
}

//Slot for swapping the frame at the passed frameIndex with the current active frame
void Model::swapFrame(int frameIndex, int otherFrameIndex)
{
    frames.swapItemsAt(frameIndex, otherFrameIndex);
    activeFramePointer = otherFrameIndex;
    updateView();
}

//helper method which builds the current frames vector into a vector of pixmaps and updates the view
void Model::sendPreviewArray()
{
    QVector<QPixmap> preview;
    for (int i = 0; i < frames.size(); i++)
    {
        preview.append(frameToPixmap(frames.at(i)));
    }
    emit previewUpdate(preview);
}

//slot to update pixels
void Model::receivePixelClick(int row, int col)
{
    if (currentTool == eraser)
    {
        setPixel(row, col, Pixel{255, 255, 255, 0});
    }
    else
    {
        setPixel(row, col, currentColor);
    }
}

//Helper which sets the pixels of the current frame depending on brush size and emits a signal of the current frame to the view
void Model::setPixel(int row, int col, Pixel pixel)
{
    int x = 0;
    int y = 0;
    // adjust starting location of for loop
    if (brushSize == 3)
    {
        x = -1;
        y = -1;
    }
    for (int i = 0; i < brushSize; i++)
    {
        for (int j = 0; j < brushSize; j++)
        {
            frames[activeFramePointer].setPixel(row + i + x, col + j + y, pixel);
        }
    }

    emit frameEditorUpdate(frames[activeFramePointer]);
    sendPreviewArray();
}

//Helper method to convert frames to images and then pixmaps
QPixmap Model::frameToPixmap(Frame frame)
{
    QImage image(frameSize, frameSize, QImage::Format_ARGB32);
    QColor color;
    for (int i = 0; i < frameSize; i++)
    {
        for (int j = 0; j < frameSize; j++)
        {
            color = QColor(frame.getPixel(i, j).red, frame.getPixel(i, j).green, frame.getPixel(i, j).blue, frame.getPixel(i, j).alpha);
            image.setPixelColor(j, i, color);
        }
    }
    QPixmap result(QPixmap::fromImage(image));
    return result;
}

//Slot to update brush
void Model::updateBrushSize(int brushSize)
{
    this->brushSize = brushSize;
}

//Slot to change tool
void Model::changeTool(Tool tool)
{
    currentTool = tool;
}

//Slot to update currentColor
void Model::updateCurrentColor(Pixel pixel)
{
    currentColor = pixel;
}

// Slot that reads a Json Object and replaces this project with it
void Model::loadProject(QJsonObject &otherProject)
{
    QJsonObject projectFrames = otherProject.value("frames").toObject();
    QString key = "frame";
    key.append(QString::number(0)); // Get first frame
    QVector<Frame> newFrames;

    int size = otherProject.value("height").toInt();

    // Get frames by their names (frame0, frame1, frame2, etc.)
    // There must be at least one frame named "frame0"
    for (int frameNumber = 1; projectFrames.contains(key); frameNumber++)
    {

        // Go through current frame and make a new frame from the pixels
        QJsonArray rows = projectFrames.value(key).toArray();
        Frame loadFrame(size);

        // Go through each pixel and draw the frame
        for (int rowNum = 0; rowNum < size; rowNum++)
        {
            QJsonArray columns = rows[rowNum].toArray();
            for (int colNum = 0; colNum < size; colNum++)
            {
                QJsonArray pixel = columns[colNum].toArray();
                Pixel pixelValue = {pixel[0].toInt(),
                                    pixel[1].toInt(),
                                    pixel[2].toInt(),
                                    pixel[3].toInt()};
                loadFrame.setPixel(colNum, rowNum, pixelValue);
            }
        }

        // Add the frame to a new list of frames
        newFrames.push_back(loadFrame);

        // Reset key for next frame
        key = "frame";
        key.append(QString::number(frameNumber));
    }

    // Now overwrite the original model with a new one
    frames = newFrames;
    frameSize = size;
    currentColor = {0, 0, 0, 255};
    currentTool = brush;
    activeFramePointer = 0;
    brushSize = 1;
    fps = 1;
    animationFrame = 0;
    playingAnimation = false;

    // Tell the window to reset for the load
    emit resetView(frameSize, (int)frames.length());
}

// Slot that will send a signal back to the view with this project converted to Json
void Model::retrieveJsonProject()
{
    QJsonObject root;
    root.insert("height", frameSize);
    root.insert("width", frameSize);
    root.insert("numberOfFrames", frames.size());

    QJsonObject framesObject;
    for (int i = 0; i < frames.size(); i++)
    {

        // Add frame numbers (frame0, frame1, etc.)
        QString itemName = "frame";
        framesObject.insert(itemName.append(QString::number(i)), frames[i].getJsonArray());
    }

    root.insert("frames", framesObject);

    emit saveProject(root);
}

// Slot to send signals to update the view on reset
void Model::updateResettedView() {
    emit frameEditorUpdate(frames[activeFramePointer]);
    sendPreviewArray();
}

//Public getter for setting up the view
int Model::getFrameSize()
{
    return frameSize;
}


void Model::returnNumberOfFrames() {
    emit sendNumberOfFrames(frames.length());
}

//SLot for play/pause button clicked
void Model::playPauseClicked()
{
    playingAnimation = !playingAnimation;
    frameAnimation();
}

// Function starts a timer for frame animation
void Model::frameAnimation()
{
    QTimer::singleShot((1000/fps), this, &Model::animationUpdate);
}

//Signal to the view of the new frame for the animation
void Model::animationUpdate(){

    // Do not update the animation if it isn't playing
    if (!playingAnimation)
        return;

    if(animationFrame == frames.size())
        animationFrame = 0;

    emit updateFrameAnimation(frameToPixmap(frames[animationFrame]));
    animationFrame++;
    frameAnimation();
}

//Slot for fps changes
void Model::fpsUpdate(int updatedFPS)
{
    fps = updatedFPS;
}
