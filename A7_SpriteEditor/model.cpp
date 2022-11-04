#include "model.h"

model::model()
{


}

void model::addFrame(int frame){
    frames.append(frame);
}

void model::removeFrame(int frame){
    frames.removeOne(frame);
}

void model::swapFrame(int frame, int otherFrame){

    int *tempFrame = &frame;
    int otherFrameIndex = frames.indexOf(otherFrame);
    frames.replace(frames.indexOf(frame), otherFrame);
    frames.replace(otherFrameIndex, *tempFrame);

}

void model::load(){

}

void model::save(){

}
