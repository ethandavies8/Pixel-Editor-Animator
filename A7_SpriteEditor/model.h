#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "frame.h"

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(int spriteSize, QObject *parent = nullptr);
    virtual ~Model();

signals:
    void saveProject(QJsonObject& thisProject);

public slots:
    void loadProject(QJsonObject& otherProject);
    void retrieveJsonProject();

private:
    QVector<Frame> frames;
    int activeFramePointer = 0;
    int frameSize;
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
