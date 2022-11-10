#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "frame.h"
#include <QPixmap>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(int spriteSize, QObject *parent = nullptr);
    virtual ~Model();

signals:
    void saveProject(QJsonObject& thisProject);
    void updateFrameAnimation(QPixmap);

public slots:
    void loadProject(QJsonObject& otherProject);
    void retrieveJsonProject();
    void receivePixelClick(int row, int col);
    void updateCurrentColor(Pixel pixel);
    void frameAnimation();
    void fpsUpdate(int);
    void playPauseClicked();

private:
    QVector<Frame> frames;
    Pixel currentColor{0, 0, 0, 0};
    enum Tool {brush, eraser};
    Tool currentTool;
    int activeFramePointer = 0;
    int brushSize = 1;
    int frameSize;
    int fps;        //Determines rate of animation
    bool playingAnimation; //Determines if animation is playing
    void addFrame();
    void setPixel(int row, int col, Pixel pixel);
    void updateBrushSize(int brushSize);
    void changeTool(Tool tool);
    void swapFrame(Frame frame, Frame otherFrame);
    void removeFrame(Frame removedFrame);

//    //AnimationWindow
//    //ToolBar
//    //ColorPallette
//    //GridEditor
};

#endif // MODEL_H
