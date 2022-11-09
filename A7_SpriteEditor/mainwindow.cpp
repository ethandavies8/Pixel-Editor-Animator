#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "iostream"
#include "model.h"

#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonArray>

MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      colorDialog(new QColorDialog)
{
    //SETUP UI
    ui->setupUi(this);

    //SETUP PIXEL EDITOR
    ui->pixelEditor->horizontalHeader()->setMinimumSectionSize(0);
    ui->pixelEditor->verticalHeader()->setMinimumSectionSize(0);
    ui->pixelEditor->setColumnCount(model.getFrameSize());
    ui->pixelEditor->setRowCount(model.getFrameSize());
    //ui->pixelEditor->setStyleSheet("QTableWidget { selection-color: transparent; selection-background-color: transparent; }");
    //EDITOR/DRAWING Conncetions
    for (int currentCell = 0; currentCell < model.getFrameSize(); ++currentCell) {
        ui->pixelEditor->setColumnWidth(currentCell, ui->pixelEditor->width()/model.getFrameSize());
        ui->pixelEditor->setRowHeight(currentCell, ui->pixelEditor->width()/model.getFrameSize());
    }

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
            &MainWindow::callToolSelectedEraser
            );
    connect(ui->colorButton,
            &QPushButton::clicked,
            this,
            &MainWindow::openColorDialog
            );
    connect(colorDialog,
            &QColorDialog::colorSelected,
            this,
            &MainWindow::sendColor
            );


    // MENU ITEMS (SAVE AND LOAD)
    connect(ui->actionSave,
            &QAction::triggered,
            &model,
            &Model::retrieveJsonProject
            );

    connect(ui->actionLoad,
            &QAction::triggered,
            this,
            &MainWindow::loadFile
            );

    connect(this,
            &MainWindow::replaceProject,
            &model,
            &Model::loadProject
            );

    connect(&model,
            &Model::saveProject,
            this,
            &MainWindow::saveFile
            );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::callEditorClicked(int row, int col) {
    QColor currentColor(colorDialog->currentColor());
    QPalette pal;
    pal.setColor(QPalette::Highlight, currentColor);
    ui->pixelEditor->setPalette(pal);
    emit editorClicked(row, col);
    setPixel({currentColor.red(), currentColor.green(), currentColor.blue(), currentColor.alpha()}, row,col);
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

void MainWindow::setPixel(Pixel pixel, int row, int col) {
    if(ui->pixelEditor->item(row, col) == nullptr) {
        //ui->pixelEditor->setStyleSheet("item {selection-background-color: transparent; selection-color: transparent;};");
        //ui->pixelEditor->setStyleSheet("item:selected{ background-color: transparent }");
        std::cout << "No item, creating one." << std::endl;
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setBackground(QColor(qRgba(pixel.red,pixel.green,pixel.blue,pixel.alpha)));
        ui->pixelEditor->setItem(row, col, item);
    }
    else {
        std::cout << "item exists" << std::endl;
        ui->pixelEditor->item(row, col)->setBackground(QColor(qRgba(pixel.red,pixel.green,pixel.blue,pixel.alpha)));
    }
}

void MainWindow::openColorDialog() {
    colorDialog->open();
}

void MainWindow::sendColor() {
   QColor currentColor(colorDialog->currentColor());
    emit colorChange({currentColor.red(), currentColor.green(), currentColor.blue(), currentColor.alpha()});
   std::string style = "QFrame {background-color: rgba(" + std::to_string(currentColor.red()) + ", " +
           std::to_string(currentColor.green()) + ", " +
           std::to_string(currentColor.blue()) + ", " +
           std::to_string(currentColor.alpha()) + ");}";

   ui->colorPreview->setStyleSheet(QString::fromStdString(style));

}

// Slot that will ask the user for a file and read it to replace the project
void MainWindow::loadFile() {

    // Ask the user for the file to open
    QFile file(QFileDialog::getOpenFileName(this, "Open Project", "./", "Sprite Sheet Projects (*.ssp)"));

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "ERROR", "File not loaded.");
        return;
    }

    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject project = document.object();

    if (projectFormatIsCorrect(project))
        emit replaceProject(project); // Replace the project if it passes error checking
}

// Slot that will ask the user for a file location and save the project
void MainWindow::saveFile(QJsonObject& thisProject) {

    QFile file(QFileDialog::getSaveFileName(this, "Save Project", "./", "Sprite Sheet Projects (*.ssp)"));

    file.open(QIODevice::WriteOnly);
    QJsonDocument document;
    document.setObject(thisProject);
    file.write(document.toJson());
    file.close();
}

// Helper method for error checking JSON format
bool MainWindow::projectFormatIsCorrect(QJsonObject& project) {

    if (project.isEmpty()) {
        QMessageBox::warning(this, "ERROR", "Project is empty.");
        return false;
    }
    else if (!project.contains("height")) {
        QMessageBox::warning(this, "ERROR", "Project does not contain height.");
        return false;
    }
    else if (!project.contains("width")) {
        QMessageBox::warning(this, "ERROR", "Project does not contain width.");
        return false;
    }
    else if (!project.contains("numberOfFrames")) {
        QMessageBox::warning(this, "ERROR", "Project does not contain numberOfFrames.");
        return false;
    }
    else if (!project.contains("frames")) {
        QMessageBox::warning(this, "ERROR", "Project does not contain frames.");
        return false;
    }
    else if (project.value("height").toInt() != project.value("width").toInt()) {
        QMessageBox::warning(this, "ERROR", "Project must have a square sprite size.");
        return false;
    }
    else if (project.value("numberOfFrames").toInt() != project.value("frames").toObject().size()) {
        QMessageBox::warning(this, "ERROR", "The number of frames does not match the frames present.");
        return false;
    }

    return true;
}
