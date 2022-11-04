#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // do this
    ui->setupUi(this);
    ui->pixelEditor->setColumnCount(2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

