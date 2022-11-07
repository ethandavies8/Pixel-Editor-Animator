#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
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

    //Pixel pix = {0,0,0,1};

}

MainWindow::~MainWindow()
{
    delete ui;
    while (true) {

    }
}

void MainWindow::callEditorClicked(int row, int col) {
    emit editorClicked(row, col);
    setPixel({0,0,255,255}, row,col);
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
        std::cout << "No item, creating one." << std::endl;
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setBackground(QColor(qRgba(pixel.red,pixel.green,pixel.blue,pixel.alpha)));
        ui->pixelEditor->setItem(row, col, item);
    }
    else {
        std::cout << "item exists" << std::endl;
        ui->pixelEditor->itemAt(row, col)->setBackground(QColor(qRgba(pixel.red,pixel.green,pixel.blue,pixel.alpha)));
    }


    //ui->pixelEditor->setItem(row, col, item);
    //QTableWidgetItem item()
    //ui->pixelEditor->item(row, col)->setBackground(color); //QColor(pixel.red, pixel.green, pixel.blue, pixel.alpha)
}


