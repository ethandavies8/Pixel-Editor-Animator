#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <frame.h>
#include "QColorDialog"
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(Model& model, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QColorDialog *colorDialog;
    Model::Tool currentTool = Model::brush;
    int frameSize;
    int totalFrames;
    int currentFrameIndex;
    bool actualSizeAnimation;
    bool isPlayingAnimation;

    void callEditorClicked(int, int);
    void callToolSelectedBrush();
    void callToolSelectedEraser();
    void openColorDialog();
    void playPauseClicked();
    bool projectFormatIsCorrect(QJsonObject&);

    void setPixel(Pixel, int, int);
    void sendColor();


    void callDuplicateFrame();
    void callAddFrame();
    void callRemoveFrame();
    void updateFramePreview(QVector<QPixmap>);

    void callFramePreviewClicked(int, int);

    void callSwapFrame();
    bool swapEnabled;

    struct frameSwapStruct {bool isChosen; int index;};

    struct frameSwapStruct frameToSwitch{false, 0};

public slots:
    void loadFile();
    void saveFile(QJsonObject&);
    void updatePixelEditor(Frame);
    void updateFPSLabel();
    void updateFrameAnimation(QPixmap);
    void resizeAnimation();
    void receiveNumberOfFrames(int);
    void receiveFrameIndex(int);
    void setUpView(int, int);

signals:
    void editorClicked(int, int);
    void toolSelected(Model::Tool);
    void replaceProject(QJsonObject&);
    void colorChange(Pixel);

    void addFrame();
    void duplicateFrame();
    void swapFrame(int, int);
    void removeFrame();
    void changeBrushSize(int);
    void frameSelected(int);
    void fpsUpdate(int);

    void askNumberOfFrames();
    void loadPotentialProject();
};
#endif // MAINWINDOW_H
