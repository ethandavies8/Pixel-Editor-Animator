#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    bool projectFormatIsCorrect(QJsonObject&);
    enum Tool {brush, eraser};
    Tool currentTool = brush;

public slots:
    void loadFile();
    void saveFile();

signals:
    void editorClicked(int, int);
    void toolSelected(Tool);
    void replaceProject(QJsonObject&);
};
#endif // MAINWINDOW_H
