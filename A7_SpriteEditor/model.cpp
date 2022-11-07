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
