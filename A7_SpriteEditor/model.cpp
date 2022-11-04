#include "model.h"
#include "frame.h"

model::model()
{
    //get FrameSize from view
    Frame newFrame(frameSize);
    frames.append(newFrame);

}

void model::addFrame(){
    Frame newFrame(frameSize);
    frames.append(newFrame);
}



void model::removeFrame(Frame removedFrame){
    frames.removeOne(removedFrame);
}

void model::swapFrame(Frame frame, Frame otherFrame){

    Frame *tempFrame = &frame;
    int otherFrameIndex = frames.indexOf(otherFrame);
    frames.replace(frames.indexOf(frame), otherFrame);
    frames.replace(otherFrameIndex, *tempFrame);

}

void model::load(){

}

void model::save(){

}
