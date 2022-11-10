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
    void playPauseClicked();
    bool projectFormatIsCorrect(QJsonObject&);
    enum Tool {brush, eraser};
    Tool currentTool = brush;

    void setPixel(Pixel, int, int);
    void sendColor();

    QColorDialog *colorDialog;

public slots:
    void loadFile();
    void saveFile(QJsonObject&);
    void updateFPSLabel();

signals:
    void editorClicked(int, int);
    void toolSelected(Tool);
    void replaceProject(QJsonObject&);
    void colorChange(Pixel);
    void fpsUpdate(int);
};
#endif // MAINWINDOW_H
