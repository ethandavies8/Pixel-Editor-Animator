#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "frame.h"

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    virtual ~Model();

signals:

public slots:
//    void replaceProject(QJsonObject& loadedProject);

private:
    QVector<Frame> frames;
    int activeFramePointer = 0;
    int frameSize = 16;
    void addFrame();
//    void swapFrame(Frame frame, Frame otherFrame);
//    void removeFrame(Frame removedFrame);
//    void load();
//    void save();
//    //AnimationWindow
//    //ToolBar
//    //ColorPallette
//    //GridEditor
};

#endif // MODEL_H
