#include "model.h"
#include "frame.h"
#include <QJsonObject>
#include <QJsonArray>

Model::Model(QObject *parent)
    : QObject{parent}
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

    QVector<Frame> newFrames;

    int size = otherProject.value("height").toInt();
    QJsonArray projectFrames = otherProject.value("frames").toArray();

    for (const QJsonValue& value : projectFrames) {
    }

    // Now overwrite the original model with a new one
    // frames = newFrames;
    frameSize = size;
    activeFramePointer = 0;
}

// Slot that will send a signal back to the view with this project converted to Json
void Model::retrieveJsonProject() {
    QJsonObject root;
    root.insert("height", frameSize);
    root.insert("width", frameSize);
    root.insert("numberOfFrames", frames.size());

    QJsonObject frameArr;
    for (int i = 0; i < frames.size(); i++) {

        // Add frame numbers (frame0, frame1, etc.)
        QString itemName = "frame";
        frameArr.insert(itemName.append(QString::number(i)), frames[i].getJsonArray());
    }

    root.insert("frames", frameArr);

    emit saveProject(root);
}
