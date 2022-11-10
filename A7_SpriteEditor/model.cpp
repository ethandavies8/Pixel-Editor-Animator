#include "model.h"
#include "frame.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QPixmap>

Model::Model(int spriteSize, QObject *parent)
    : QObject{parent}
    , frameSize(spriteSize)
    , playingAnimation(false)
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

//void model::removeFrame(Frame removedFrame){
//    frames.removeOne(removedFrame);
//}

//void model::swapFrame(Frame frame, Frame otherFrame){

//    Frame *tempFrame = &frame;
//    int otherFrameIndex = frames.indexOf(otherFrame);
//    frames.replace(frames.indexOf(frame), otherFrame);
//    frames.replace(otherFrameIndex, *tempFrame);
//}


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
          setPixel(row + i + x, col + j + y, pixel);
       }
    }
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
void Model::playPauseClicked(){
    playingAnimation = !playingAnimation;
    frameAnimation();
}
void Model::frameAnimation(){
    if(playingAnimation){
        for(int i = 0; i < frames.size(); i++){
            //QTimer::singleShot((1000/fps)*(i+1), this, &Model::updateFrameAnimation(frames[i]));
        }
        QTimer::singleShot(1000*frames.size()/fps+1000/fps, this, &Model::frameAnimation);
    }
}
void Model::fpsUpdate(int updatedFPS){
    fps = updatedFPS;
}
