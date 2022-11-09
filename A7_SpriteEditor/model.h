#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "frame.h"
#include "qpixmap.h"

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(int spriteSize, QObject *parent = nullptr);
    virtual ~Model();
    int getFrameSize();
    enum Tool {brush, eraser};

signals:
    void saveProject(QJsonObject& thisProject);
    void frameEditorUpdate(Frame);
    void previewUpdate(QVector<QPixmap>);

public slots:
    void loadProject(QJsonObject& otherProject);
    void retrieveJsonProject();
    void receivePixelClick(int row, int col);
    void updateCurrentColor(Pixel pixel);
    void updateBrushSize(int brushSize);
    void changeTool(Model::Tool tool);
    void addFrame();
    void updateCurrentFramePointer(int);

private:
    QVector<Frame> frames;
    Pixel currentColor{0, 0, 0, 0};
    Tool currentTool;
    int activeFramePointer = 0;
    int brushSize = 1;
    int frameSize;
    void setPixel(int row, int col, Pixel);
    void swapFrame(int frameIndex, int otherFrameIndex);
    void removeFrame(int removedFrameIndex);
    void sendPreviewArray();
    QPixmap frameToPixmap(Frame);
};

#endif // MODEL_H
