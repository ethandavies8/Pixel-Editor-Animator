#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "iostream"
#include "model.h"

#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include<QJsonObject>
#include <QMessageBox>

MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // do this
    ui->setupUi(this);
    //ui->pixelEditor->setColumnCount(2);
    connect(ui->pixelEditor,
            &QTableWidget::cellClicked,
            this,
            &MainWindow::callEditorClicked
            );

    connect(ui->brushButton,
            &QPushButton::clicked,
            this,
            &MainWindow::callToolSelectedBrush
            );

    connect(ui->eraserButton,
            &QPushButton::clicked,
            this,
            &MainWindow::callToolSelectedEraser //&MainWindow::callToolSelected
            );

    // MENU ITEMS (SAVE AND LOAD)
    connect(ui->actionSave,
            &QAction::triggered,
            this,
            &MainWindow::saveFile
            );

    connect(ui->actionLoad,
            &QAction::triggered,
            this,
            &MainWindow::loadFile
            );

//    connect(this,
//            &MainWindow::replaceProject,
//            &model,
//            &Model::replaceProject
//            );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::callEditorClicked(int row, int col) {
    emit editorClicked(row, col);
    std::cout << "cell pressed: ROW: " << row << " COL: " << col << std::endl;
}

void MainWindow::callToolSelectedBrush() {
    emit toolSelected(brush);
    std::cout << "Emitted select Tool: Brush" << std::endl;
}

void MainWindow::callToolSelectedEraser() {
    emit toolSelected(eraser);
    std::cout << "Emitted select Tool: Eraser" << std::endl;
}

void MainWindow::loadFile() {

    // Ask the user for the file to open
    QFile file(QFileDialog::getOpenFileName(this, "Open Project", "C://", "JSON Files (*.json)"));

    if (!file.isOpen())
        QMessageBox::warning(this, "ERROR", "File not open.");

    QString data = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject project = document.object();

    // Error checking
    if (!project.isEmpty())
        QMessageBox::warning(this, "ERROR", "Project is empty.");
    else if (!project.contains("height"))
        QMessageBox::warning(this, "ERROR", "Project does not contain height.");
    else if (!project.contains("width"))
        QMessageBox::warning(this, "ERROR", "Project does not contain width.");
    else if (!project.contains("numberOfFrames"))
        QMessageBox::warning(this, "ERROR", "Project does not contain numberOfFrames.");
    else if (!project.contains("frames"))
        QMessageBox::warning(this, "ERROR", "Project does not contain frames.");

    // Send this object back to the model to replace current project
    // emit replaceProject(project);
}

void MainWindow::saveFile() {

}
