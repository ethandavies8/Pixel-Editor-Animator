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
    void callEditorClicked(int, int);
    void callToolSelectedBrush();
    void callToolSelectedEraser();
    void openColorDialog();
    bool projectFormatIsCorrect(QJsonObject&);
    Model::Tool currentTool = Model::brush;

    void setPixel(Pixel, int, int);
    void sendColor();

    QColorDialog *colorDialog;
    int frameSize;

    void callAddFrame();
    void callRemoveFrame();
    void updateFramePreview(QVector<QPixmap>);

public slots:
    void loadFile();
    void saveFile(QJsonObject&);
    void updatePixelEditor(Frame);

signals:
    void editorClicked(int, int);
    void toolSelected(Model::Tool);
    void replaceProject(QJsonObject&);
    void colorChange(Pixel);

    void addFrame();
    void removeFrame();
    void changeBrushSize(int);
};
#endif // MAINWINDOW_H
