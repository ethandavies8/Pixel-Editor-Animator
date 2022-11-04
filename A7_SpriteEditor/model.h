#ifndef MODEL_H
#define MODEL_H

#include <QVector>



class model
{
public:
    model();

private:
    QVector<int> frames;
  //  frame activeFrame;
    void addFrame(int frame);
    void swapFrame(int frame1, int frame2);
    void removeFrame(int frame);
    void load();
    void save();
    //AnimationWindow
    //ToolBar
    //ColorPallette
    //GridEditor
};

#endif // MODEL_H
