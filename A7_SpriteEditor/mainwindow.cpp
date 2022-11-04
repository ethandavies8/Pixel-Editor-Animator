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
            &MainWindow::printCellPressed
            );
}

MainWindow::~MainWindow()
{
    delete ui;
    while (true) {

    }
}

void MainWindow::printCellPressed(int row, int col) {
    std::cout << "cell pressed: ROW: " << row << " COL: " << col << std::endl;
}

