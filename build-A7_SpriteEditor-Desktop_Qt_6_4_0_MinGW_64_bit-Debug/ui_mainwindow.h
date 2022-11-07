/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSAVE;
    QAction *actionSAVEAS;
    QAction *actionOPEN;
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *horizontalScrollBar;
    QSlider *fpsSlider;
    QPushButton *pushButton;
    QPushButton *brushButton;
    QPushButton *eraserButton;
    QPushButton *pushButton_4;
    QFrame *colorPreview;
    QTableWidget *pixelEditor;
    QMenuBar *menubar;
    QMenu *saveMenu;
    QMenu *loadMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName("actionSAVE");
        actionSAVEAS = new QAction(MainWindow);
        actionSAVEAS->setObjectName("actionSAVEAS");
        actionOPEN = new QAction(MainWindow);
        actionOPEN->setObjectName("actionOPEN");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 450, 761, 81));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 759, 79));
        scrollArea->setWidget(scrollAreaWidgetContents);
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName("horizontalScrollBar");
        horizontalScrollBar->setGeometry(QRect(20, 530, 761, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        fpsSlider = new QSlider(centralwidget);
        fpsSlider->setObjectName("fpsSlider");
        fpsSlider->setGeometry(QRect(590, 200, 101, 22));
        fpsSlider->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(710, 200, 75, 24));
        brushButton = new QPushButton(centralwidget);
        brushButton->setObjectName("brushButton");
        brushButton->setGeometry(QRect(590, 250, 41, 41));
        eraserButton = new QPushButton(centralwidget);
        eraserButton->setObjectName("eraserButton");
        eraserButton->setGeometry(QRect(590, 290, 41, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(710, 250, 41, 41));
        colorPreview = new QFrame(centralwidget);
        colorPreview->setObjectName("colorPreview");
        colorPreview->setGeometry(QRect(710, 300, 31, 31));
        colorPreview->setAutoFillBackground(false);
        colorPreview->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        colorPreview->setFrameShape(QFrame::StyledPanel);
        colorPreview->setFrameShadow(QFrame::Raised);
        pixelEditor = new QTableWidget(centralwidget);
        if (pixelEditor->columnCount() < 8)
            pixelEditor->setColumnCount(8);
        if (pixelEditor->rowCount() < 8)
            pixelEditor->setRowCount(8);
        pixelEditor->setObjectName("pixelEditor");
        pixelEditor->setGeometry(QRect(100, 70, 331, 341));
        pixelEditor->setMouseTracking(true);
        pixelEditor->setShowGrid(true);
        pixelEditor->setRowCount(8);
        pixelEditor->setColumnCount(8);
        pixelEditor->horizontalHeader()->setVisible(false);
        pixelEditor->horizontalHeader()->setCascadingSectionResizes(false);
        pixelEditor->horizontalHeader()->setDefaultSectionSize(49);
        pixelEditor->verticalHeader()->setVisible(false);
        pixelEditor->verticalHeader()->setDefaultSectionSize(42);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        saveMenu = new QMenu(menubar);
        saveMenu->setObjectName("saveMenu");
        loadMenu = new QMenu(menubar);
        loadMenu->setObjectName("loadMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(saveMenu->menuAction());
        menubar->addAction(loadMenu->menuAction());
        saveMenu->addAction(actionSAVE);
        saveMenu->addAction(actionSAVEAS);
        loadMenu->addAction(actionOPEN);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSAVE->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSAVEAS->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionOPEN->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        brushButton->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        eraserButton->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        saveMenu->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
        loadMenu->setTitle(QCoreApplication::translate("MainWindow", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
