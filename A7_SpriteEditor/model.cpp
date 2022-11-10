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

void Model::addFrame()
{
    Frame newFrame(frameSize);
    frames.append(newFrame);
}

// Slot to duplicate selected frame
void Model::duplicateFrame() {
    frames.append(frames[activeFramePointer]);
}

void Model::removeFrame(int removedFrameIndex)
{
    frames.removeAt(removedFrameIndex);
}

void Model::updateCurrentFramePointer(int index)
{
    activeFramePointer = index;
    emit frameEditorUpdate(frames.at(activeFramePointer));
}

void Model::swapFrame(int frameIndex, int otherFrameIndex)
{

    Frame tempFrame = frames.at(frameIndex);
    frames.replace(frameIndex, otherFrameIndex);
    frames[otherFrameIndex] = tempFrame;
    sendPreviewArray();
}

void Model::sendPreviewArray()
{
    QVector<QPixmap> preview;
    for (int i = 0; i < frames.size(); i++)
    {
        preview.append(frameToPixmap(frames.at(i)));
    }
    emit previewUpdate(preview);
}

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

void Model::updateBrushSize(int brushSize)
{
    this->brushSize = brushSize;
}

void Model::changeTool(Tool tool)
{
    currentTool = tool;
}

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
    currentColor = {0, 0, 0, 0};
    currentTool = brush;
    activeFramePointer = 0;
    brushSize = 1;

    // Tell the window to reset for the load
    emit resetView(frameSize);
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

int Model::getFrameSize()
{
    return frameSize;
}

void Model::returnNumberOfFrames() {
    emit sendNumberOfFrames(frames.length());
}
void Model::playPauseClicked()
{
    playingAnimation = !playingAnimation;
    frameAnimation();
}
void Model::frameAnimation()
{
    if (playingAnimation)
    {
        for (int i = 0; i < frames.size(); i++)
        {
             QTimer::singleShot((1000/fps)*(i+1), this, &Model::animationUpdate);
        }
        QTimer::singleShot(1000 * frames.size() / fps + 1000 / fps, this, &Model::frameAnimation);
    }
}
void Model::animationUpdate(){
    if(animationFrame == frames.size())
        animationFrame = 0;

    emit updateFrameAnimation(frameToPixmap(frames[animationFrame]));
    animationFrame++;
}
void Model::fpsUpdate(int updatedFPS)
{
    fps = updatedFPS;
}
