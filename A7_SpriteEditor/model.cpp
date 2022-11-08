#include "model.h"
#include "frame.h"
#include <QJsonObject>
#include <QJsonArray>

Model::Model(int spriteSize, QObject *parent)
    : QObject{parent}
    , frameSize(spriteSize)
{
    //get FrameSize from view
    Frame newFrame(frameSize);
    frames.append(newFrame);
}

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
