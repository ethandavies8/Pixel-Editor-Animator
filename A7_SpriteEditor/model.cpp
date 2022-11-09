#include "model.h"
#include "frame.h"
#include "qpixmap.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QImage>

Model::Model(int spriteSize, QObject *parent)
    : QObject{parent}
    , frameSize(spriteSize)
{
    //get FrameSize from view
    Frame newFrame(frameSize);
    frames.append(newFrame);
}

//Testing this branch
Model::~Model() {}

void Model::addFrame(){
    Frame newFrame(frameSize);
    frames.append(newFrame);
}

void Model::removeFrame(int removedFrameIndex){
    frames.removeAt(removedFrameIndex);
}

void Model::swapFrame(int frameIndex, int otherFrameIndex){

    Frame tempFrame = frames.at(frameIndex);
    frames.replace(frameIndex, otherFrameIndex);
    frames[otherFrameIndex] = tempFrame;
    sendPreviewArray();
}

void Model::sendPreviewArray(){
    QVector<QPixmap> preview;
    for(int i = 0; i < frames.size(); i++){
        preview.append(frameToPixmap(frames.at(i)));
    }
    emit previewUpdate(preview);
}


void Model::receivePixelClick(int row, int col){
    if(currentTool == eraser){
        setPixel(row, col, Pixel{255,255,255,0});
    }
    else{
        setPixel(row, col, currentColor);
    }

}

void Model::setPixel(int row, int col, Pixel pixel){
    int x = 0;
    int y = 0;
    //adjust starting location of for loop
    if(brushSize == 3){
        x = -1;
        y = -1;
    }
    for(int i = 0; i < brushSize; i++){
       for(int j = 0; j < brushSize; j++){
          frames[activeFramePointer].setPixel(row + i + x, col + j + y, pixel);
       }
    }
    emit frameEditorUpdate(frames.at(activeFramePointer));
    sendPreviewArray();
}

QPixmap Model::frameToPixmap(Frame frame){
    QImage image(frameSize, frameSize, QImage::Format_ARGB32);
    QColor color;
    for(int i = 0; i < frameSize; i++){
       for(int j = 0; j < frameSize; j++){
          color = QColor(frame.getPixel(i, j).red, frame.getPixel(i, j).green, frame.getPixel(i, j).blue, frame.getPixel(i, j).alpha);
          image.setPixelColor(j, i, color);
       }
    }
    QPixmap result(QPixmap::fromImage(image));
    return result;
}

void Model::updateBrushSize(int brushSize){
    this->brushSize = brushSize;
}

void Model::changeTool(Tool tool){
    currentTool = tool;
}

void Model::updateCurrentColor(Pixel pixel){
    currentColor = pixel;
}

// Slot that reads a Json Object and replaces this project with it
void Model::loadProject(QJsonObject& otherProject) {

    QJsonArray frameArray = otherProject.value("frames").toArray();
    QVector<Frame> newFrames;

    int size = otherProject.value("height").toInt();

    for (const QJsonValue& frameVal : frameArray) {
        QJsonArray rows = frameVal.toArray();
        Frame loadFrame(size);

        // Go through each pixel and draw the frame
        for (int rowNum = 0; rowNum < size; rowNum++) {
            QJsonArray columns = rows[rowNum].toArray();
            for (int colNum = 0; colNum < size; colNum++) {
                QJsonArray pixel = columns[colNum].toArray();
                Pixel pixelValue = {pixel[0].toInt(),
                                pixel[1].toInt(),
                                pixel[2].toInt(),
                                pixel[3].toInt()};
                loadFrame.setPixel(colNum, rowNum, pixelValue);
            }
        }
        // Add the frame to a new list
        newFrames.push_back(loadFrame);
    }

    // Now overwrite the original model with a new one
    frames = newFrames;
    frameSize = size;
    activeFramePointer = 0;
}

// Slot that will send a signal back to the view with this project converted to Json
void Model::retrieveJsonProject() {
    QJsonObject root;
    root.insert("height", frameSize);
    root.insert("width", frameSize);
    root.insert("numberOfFrames", frames.size());

    QJsonObject framesObject;
    for (int i = 0; i < frames.size(); i++) {

        // Add frame numbers (frame0, frame1, etc.)
        QString itemName = "frame";
        framesObject.insert(itemName.append(QString::number(i)), frames[i].getJsonArray());
    }

    root.insert("frames", framesObject);

    emit saveProject(root);
}

int Model::getFrameSize() {
    return frameSize;
}
