#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "frame.h"
#include "qpixmap.h"
#include <QPixmap>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(int spriteSize, QObject *parent = nullptr);
    virtual ~Model();
    int getFrameSize();
    int getNumberOfFrames();
    enum Tool {brush, eraser};

signals:
    void saveProject(QJsonObject& thisProject);
    void frameEditorUpdate(Frame);
    void previewUpdate(QVector<QPixmap>);
    void updateFrameAnimation(QPixmap);
    void sendNumberOfFrames(int);
    void resetView(int);

public slots:
    void loadProject(QJsonObject& otherProject);
    void retrieveJsonProject();
    void receivePixelClick(int row, int col);
    void updateCurrentColor(Pixel pixel);
    void updateBrushSize(int brushSize);
    void changeTool(Model::Tool tool);
    void addFrame();
    void duplicateFrame();
    void updateCurrentFramePointer(int);
    void frameAnimation();
    void fpsUpdate(int);
    void playPauseClicked();
    void animationUpdate();
    void returnNumberOfFrames();
    void updateResettedView();

private:
    QVector<Frame> frames;
    Pixel currentColor{0, 0, 0, 255};
    Tool currentTool;
    int activeFramePointer = 0;
    int brushSize = 1;
    int frameSize;
    int fps;        //Determines rate of animation
    int animationFrame = 0;
    bool playingAnimation; //Determines if animation is playing
    void setPixel(int row, int col, Pixel);
    void swapFrame(int frameIndex, int otherFrameIndex);
    void removeFrame(int removedFrameIndex);
    void sendPreviewArray();
    QPixmap frameToPixmap(Frame);
    void swapFrame(Frame frame, Frame otherFrame);
    void removeFrame(Frame removedFrame);
    void callSendNumberOfFrames();

//    //AnimationWindow
//    //ToolBar
//    //ColorPallette
//    //GridEditor
};

#endif // MODEL_H
