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


    //SETUP FRAME PREVIEW & Connections
    ui->framePreview->setColumnCount(8);
    ui->framePreview->setRowCount(1);
    ui->framePreview->setGeometry(20,460,540,98);

    for (int frame = 0; frame < 8; ++frame) {
        QTableWidgetItem *item = new QTableWidgetItem;
        ui->framePreview->setItem(0, frame, item);
    }

    connect(ui->addFrameButton,
            &QPushButton::clicked,
            this,
            &MainWindow::callAddFrame
            );
    connect(ui->removeFrameButton,
            &QPushButton::clicked,
            this,
            &MainWindow::callRemoveFrame
            );
    connect(&model,
            &Model::previewUpdate,
            this,
            &MainWindow::updateFramePreview
            );


    //SETUP PIXEL EDITOR & Connections
    //SETUP PIXEL EDITOR
    frameSize = model.getFrameSize();
    ui->pixelEditor->horizontalHeader()->setMinimumSectionSize(0);
    ui->pixelEditor->verticalHeader()->setMinimumSectionSize(0);
    ui->pixelEditor->setColumnCount(model.getFrameSize());
    ui->pixelEditor->setRowCount(model.getFrameSize());
    ui->pixelEditor->setGeometry(20,0,450,450);

    for (int currentCell = 0; currentCell < model.getFrameSize(); ++currentCell) {
        ui->pixelEditor->setColumnWidth(currentCell, ui->pixelEditor->width()/model.getFrameSize());
        ui->pixelEditor->setRowHeight(currentCell, ui->pixelEditor->width()/model.getFrameSize());
    }

    for (int row = 0; row < model.getFrameSize(); ++row) {
        for (int col = 0; col < model.getFrameSize(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->pixelEditor->setItem(row, col, item);
        }
    }
    emit colorChange({0, 0, 0, 255});
    QPalette pal;
    pal.setColor(QPalette::Highlight, Qt::black);
    ui->pixelEditor->setPalette(pal);

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

    connect(ui->brushSizeSlider,
            &QSlider::valueChanged,
            &model,
            &Model::updateBrushSize
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

    //Model Connection
    connect(this,
            &MainWindow::changeBrushSize,
            &model,
            &Model::updateBrushSize);

    connect(this,
            &MainWindow::editorClicked,
            &model,
            &Model::receivePixelClick);

    connect(this,
            &MainWindow::toolSelected,
            &model,
            &Model::changeTool);

    connect(this,
            &MainWindow::colorChange,
            &model,
            &Model::updateCurrentColor);
    connect(&model,
            &Model::frameEditorUpdate,
            this,
            &MainWindow::updatePixelEditor);

    connect(this,
            &MainWindow::addFrame,
            &model,
            &Model::addFrame);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePixelEditor(Frame frame){
    for (int row = 0; row < frameSize; ++row) {
        for (int col = 0; col < frameSize; ++col) {
            setPixel(frame.getPixel(row, col), row, col);
        }
    }
}

void MainWindow::callEditorClicked(int row, int col) {
    QColor currentColor(colorDialog->currentColor());
    QPalette pal;
    if(currentTool == Model::brush) {
       pal.setColor(QPalette::Highlight, currentColor);
    }
    else {
        pal.setColor(QPalette::Highlight, Qt::white);
    }
    ui->pixelEditor->setPalette(pal);
    emit editorClicked(row, col);
    //setPixel({currentColor.red(), currentColor.green(), currentColor.blue(), currentColor.alpha()}, row,col);
    std::cout << "cell pressed: ROW: " << row << " COL: " << col << std::endl;
}

void MainWindow::callToolSelectedBrush() {
    emit toolSelected(Model::brush);
    std::cout << "Emitted select Tool: Brush" << std::endl;
}

void MainWindow::callToolSelectedEraser() {
    emit toolSelected(Model::eraser);
    std::cout << "Emitted select Tool: Eraser" << std::endl;
}


void MainWindow::setPixel(Pixel pixel, int row, int col) {
    ui->pixelEditor->item(row, col)->setBackground(QColor(qRgba(pixel.red,pixel.green,pixel.blue,pixel.alpha)));
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

void MainWindow::callAddFrame() {
        emit addFrame();
}
void MainWindow::callRemoveFrame() {
        emit removeFrame();
}

void MainWindow::updateFramePreview(QVector<QPixmap> frames) {
    for (int currentFrame = 0; currentFrame < frames.length(); ++currentFrame) {
        QIcon icon(frames[currentFrame].scaled(80, 80, Qt::KeepAspectRatio));
        ui->framePreview->item(0, currentFrame)->setData(Qt::DecorationRole, frames[currentFrame].scaledToHeight(75));
        std::cout << "updated Frame at: " << std::to_string(currentFrame) << std::endl;
    }

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
