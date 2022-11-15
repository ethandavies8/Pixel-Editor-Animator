#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "model.h"
#include "frame.h"

#include <QFile>
#include <QColorDialog>
#include <QFileDialog>
#include <QJsonDocument>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      colorDialog(new QColorDialog)
{
    //SETUP UI
    ui->setupUi(this);

    //Frame Button connetions
    connect(ui->addFrameButton,
            &QPushButton::clicked,
            this,
            &MainWindow::callAddFrame
            );
    connect(ui->duplicateFrameButton,
            &QPushButton::clicked,
            this,
            &MainWindow::callAddFrame
            );
    connect(ui->removeFrameButton,
            &QPushButton::clicked,
            this,
            &MainWindow::callRemoveFrame
            );

    connect(ui->swapFrameButton,
            &QPushButton::clicked,
            this,
            &MainWindow::callSwapFrame);

    //Frame preview connections
    connect(&model,
            &Model::previewUpdate,
            this,
            &MainWindow::updateFramePreview
            );

    connect(ui->framePreview,
            &QTableWidget::cellClicked,
            this,
            &MainWindow::callFramePreviewClicked
            );

    //number of frame connections
    connect(this,
            &MainWindow::askNumberOfFrames,
            &model,
            &Model::returnNumberOfFrames
            );
    connect(&model,
            &Model::sendNumberOfFrames,
            this,
            &MainWindow::receiveNumberOfFrames
            );

    //Pixel editor connections
    connect(ui->pixelEditor,
            &QTableWidget::cellClicked,
            this,
            &MainWindow::callEditorClicked
            );

    connect(ui->pixelEditor,
            &QTableWidget::cellEntered,
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

    connect(&model,
            &Model::resetView,
            this,
            &MainWindow::setUpView
            );

    connect(this,
            &MainWindow::loadPotentialProject,
            &model,
            &Model::updateResettedView
            );

    //Animation Preview connection
    connect(ui->playPauseButton,
            &QPushButton::clicked,
            &model,
            &Model::playPauseClicked
            );

    //Model update connections
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

    connect(this,
            &MainWindow::removeFrame,
            &model,
            &Model::removeFrame);

    connect(&model,
            &Model::sendFrameIndex,
            this,
            &MainWindow::receiveFrameIndex);

    connect(this,
            &MainWindow::duplicateFrame,
            &model,
            &Model::duplicateFrame);

    connect(this,
            &MainWindow::swapFrame,
            &model,
            &Model::swapFrame);

    connect(this,
            &MainWindow::frameSelected,
            &model,
            &Model::updateCurrentFramePointer);

    connect(ui->playPauseButton,
            &QPushButton::clicked,
            this,
            &MainWindow::playPauseClicked
            );

    connect(ui->fpsSlider,
            &QSlider::valueChanged,
            &model,
            &Model::fpsUpdate
            );

    connect(ui->fpsSlider,
            &QSlider::valueChanged,
            this,
            &MainWindow::updateFPSLabel
            );

    connect(this,
            &MainWindow::fpsUpdate,
            &model,
            &Model::fpsUpdate
            );

    connect(&model,
            &Model::updateFrameAnimation,
            this,
            &MainWindow::updateFrameAnimation
            );

    connect(ui->resizeButton,
            &QPushButton::clicked,
            this,
            &MainWindow::resizeAnimation
            );


    //SETUP VIEW
    ui->pixelEditor->horizontalHeader()->setMinimumSectionSize(0);
    ui->pixelEditor->verticalHeader()->setMinimumSectionSize(0);
    ui->pixelEditor->setSelectionMode(QAbstractItemView::NoSelection); // Removes highlighting
    ui->pixelEditor->setFocusPolicy(Qt::NoFocus); // Removes cell focus
    setUpView(model.getFrameSize(), 1);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpView(int size, int numFrames) {

    ui->framePreview->setColumnCount(numFrames);
    for (int frame = 0; frame < numFrames; ++frame) {
        QTableWidgetItem *item = new QTableWidgetItem;
        ui->framePreview->setItem(0, frame, item);
    }

    // Set parameters
    frameSize = size;
    currentFrameIndex = 0;
    totalFrames = numFrames;
    actualSizeAnimation = false;
    isPlayingAnimation = false;
    swapEnabled = false;
    currentTool = Model::brush;
    frameToSwitch.isChosen = false;

    //SETUP PIXEL EDITOR
    ui->pixelEditor->setEnabled(true);
    ui->pixelEditor->setColumnCount(frameSize);
    ui->pixelEditor->setRowCount(frameSize);
    QPalette pal;
    pal.setColor(QPalette::Highlight, Qt::black);
    ui->pixelEditor->setPalette(pal);

    // Set all other items
    QPixmap blankMap;
    ui->spritePreviewLabel->setPixmap(blankMap);
    ui->fpsSlider->setValue(1);
    colorDialog->setCurrentColor(Qt::black);
    sendColor();
    ui->resizeButton->setStyleSheet("background-color: rgba(71,212,212,255);");
    ui->brushButton->setStyleSheet("background-color: rgba(91,250,250,100);");
    ui->eraserButton->setStyleSheet("background-color: rgba(71,212,212,255);");
    ui->playPauseButton->setStyleSheet("background-color: rgba(71,212,212,255);");
    ui->framePreview->item(0, 0)->setSelected(true);
    ui->swapFrameLabel->setVisible(false);

    if(numFrames > 1){
        ui->removeFrameButton->setEnabled(true);
    }

    //set size of cells
    for (int currentCell = 0; currentCell < frameSize; ++currentCell) {
        ui->pixelEditor->setColumnWidth(currentCell, ui->pixelEditor->width()/frameSize);
        ui->pixelEditor->setRowHeight(currentCell, ui->pixelEditor->width()/frameSize);
    }

    //preload QTableWidgetItems
    for (int row = 0; row < frameSize; ++row) {
        for (int col = 0; col < frameSize; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->pixelEditor->setItem(row, col, item);
        }
    }

    // If a project is already loaded in, update the view
    emit loadPotentialProject();
}

//Updates pixel editor from received frame from the model
void MainWindow::updatePixelEditor(Frame frame){
    for (int row = 0; row < frameSize; ++row) {
        for (int col = 0; col < frameSize; ++col) {
            setPixel(frame.getPixel(row, col), row, col);
        }
    }
}

//is called when a new cell is selected
void MainWindow::callEditorClicked(int row, int col) {
    emit editorClicked(row, col);
}

//Emits a signal to inform the model that the currently selected frame has changed
void MainWindow::callFramePreviewClicked(int row, int frameIndex) {
    if(swapEnabled){
        if(!frameToSwitch.isChosen){
            frameToSwitch.isChosen = true;
            frameToSwitch.index = frameIndex;
        }
        else{
            emit swapFrame(frameToSwitch.index, frameIndex);
            callSwapFrame();
            frameToSwitch.isChosen = false;
        }
    }
    emit frameSelected(frameIndex);
    QPalette pal;
    pal.setColor(QPalette::Highlight, Qt::white);
    ui->pixelEditor->setPalette(pal);
    }


void MainWindow::receiveNumberOfFrames(int numFrames) {
    totalFrames = numFrames;
    if(totalFrames == 1){
        ui->removeFrameButton->setEnabled(false);
    }
    else{
        ui->removeFrameButton->setEnabled(true);
    }
}

void MainWindow::receiveFrameIndex(int frameIndex){
    currentFrameIndex = frameIndex;
    if(currentFrameIndex < ui->framePreview->columnCount()){
        ui->framePreview->item(0, currentFrameIndex)->setSelected(true);
    }
}

void MainWindow::callToolSelectedBrush() {
    emit toolSelected(Model::brush);
    currentTool = Model::brush;
    ui->brushButton->setStyleSheet("background-color: rgba(91,250,250,100);");
    ui->eraserButton->setStyleSheet("background-color: rgba(71,212,212,255);");
}

void MainWindow::callToolSelectedEraser() {
    emit toolSelected(Model::eraser);
    currentTool = Model::eraser;
    ui->eraserButton->setStyleSheet("background-color: rgba(91,250,250,100);");
    ui->brushButton->setStyleSheet("background-color: rgba(71,212,212,255);");
}

//sets clicked pixel to the current color
void MainWindow::setPixel(Pixel pixel, int row, int col) {
    ui->pixelEditor->item(row, col)->setBackground(QColor(qRgba(pixel.red,pixel.green,pixel.blue,pixel.alpha)));
}

void MainWindow::playPauseClicked(){
    emit fpsUpdate(ui->fpsSlider->value());
    isPlayingAnimation = !isPlayingAnimation;
    if(isPlayingAnimation)
        ui->playPauseButton->setStyleSheet("background-color: rgba(91,250,250,100);");
    else
        ui->playPauseButton->setStyleSheet("background-color: rgba(71,212,212,255);");

}

void MainWindow::updateFrameAnimation(QPixmap map){
    if(actualSizeAnimation)
        ui->spritePreviewLabel->setPixmap(map);
    else
        ui->spritePreviewLabel->setPixmap(map.scaled(200,200));
}

void MainWindow::resizeAnimation(){
    actualSizeAnimation = !actualSizeAnimation;
    if(actualSizeAnimation)
        ui->resizeButton->setStyleSheet("background-color: rgba(91,250,250,100);");
    else
        ui->resizeButton->setStyleSheet("background-color: rgba(71,212,212,255);");
}

void MainWindow::updateFPSLabel(){
    ui->fpsLabel->setText("fps:" + QString::number(ui->fpsSlider->value()));
}

void MainWindow::openColorDialog() {
    colorDialog->open();
}

//sends the color selection to the model and updates the colorPreview to match the color selection
void MainWindow::sendColor() {
   QColor currentColor(colorDialog->currentColor());
    emit colorChange({currentColor.red(), currentColor.green(), currentColor.blue(), currentColor.alpha()});
   std::string style = "QFrame {background-color: rgba(" + std::to_string(currentColor.red()) + ", " +
           std::to_string(currentColor.green()) + ", " +
           std::to_string(currentColor.blue()) + ", " +
           std::to_string(currentColor.alpha()) + ");}";

   ui->colorPreview->setStyleSheet(QString::fromStdString(style));
}

//Adds a new blank frame or a duplicate frame of the active frame depending on the button sender
void MainWindow::callAddFrame() {
    //Acquire button sender for either adding a blank frame or duplicate frame
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();

    //create new column in framePreview
    ui->framePreview->setColumnCount(ui->framePreview->columnCount() + 1);
    QTableWidgetItem *item = new QTableWidgetItem;
    ui->framePreview->setItem(0, ui->framePreview->columnCount() -  1, item);
    ui->framePreview->scrollToItem(item);
    ui->framePreview->setCurrentItem(item);

    if(buttonText == "+"){
        emit addFrame();
    }
    else {
        emit duplicateFrame();
    }

    //select newly added frame and add highlight
    ui->framePreview->item(0, currentFrameIndex)->setSelected(true);
    QPalette pal;
    pal.setColor(QPalette::Highlight, Qt::white);
    ui->framePreview->setPalette(pal);
}

//Removes the active frame if the operation is valid
void MainWindow::callRemoveFrame() {
    if (totalFrames == 1) {
        ui->removeFrameButton->setEnabled(false);
    }
    else {
        emit removeFrame();
    }
}

void MainWindow::callSwapFrame(){
    swapEnabled = !swapEnabled;
    if(swapEnabled){
        ui->pixelEditor->setEnabled(false);
        ui->swapFrameLabel->setVisible(true);
    }
    else{
        ui->pixelEditor->setEnabled(true);
        ui->swapFrameLabel->setVisible(false);
        frameToSwitch.isChosen = false;
    }
}

//Sets column count for framePreview and updates framePreview pixmaps from frames parameter
void MainWindow::updateFramePreview(QVector<QPixmap> frames) {
    ui->framePreview->setColumnCount(frames.length());
    for (int currentFrame = 0; currentFrame < frames.length(); currentFrame++) {
        QIcon icon(frames[currentFrame].scaled(80, 80, Qt::KeepAspectRatio));
        ui->framePreview->item(0, currentFrame)->setData(Qt::DecorationRole, frames[currentFrame].scaledToHeight(75));
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
