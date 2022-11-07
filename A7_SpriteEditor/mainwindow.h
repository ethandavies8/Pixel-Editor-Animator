#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <frame.h>

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
    enum Tool {brush, eraser};
    Tool currentTool = brush;

    void setPixel(Pixel, int, int);

public slots:
    //void getColor();

signals:
    void editorClicked(int, int);
    void toolSelected(MainWindow::Tool);
};
#endif // MAINWINDOW_H
