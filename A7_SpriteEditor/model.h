#ifndef MODEL_H
#define MODEL_H

#include <QVector>
#include "frame.h"


class model
{
public:
    model();

private:
    QVector<Frame> frames;
    int activeFramePointer = 0;
    int frameSize = 16;
    void addFrame();
    void swapFrame(Frame frame, Frame otherFrame);
    void removeFrame(Frame removedFrame);
    void load();
    void save();
    //AnimationWindow
    //ToolBar
    //ColorPallette
    //GridEditor
};

#endif // MODEL_H
