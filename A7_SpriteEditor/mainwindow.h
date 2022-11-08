#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <frame.h>
#include "QColorDialog"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void callEditorClicked(int, int);
    void callToolSelectedBrush();
    void callToolSelectedEraser();
    void openColorDialog();
    enum Tool {brush, eraser};
    Tool currentTool = brush;

    void setPixel(Pixel, int, int);
    void sendColor();

    QColorDialog *colorDialog;

public slots:
    //void getColor();

signals:
    void editorClicked(int, int);
    void toolSelected(MainWindow::Tool);
    void colorChange(Pixel);

};
#endif // MAINWINDOW_H
