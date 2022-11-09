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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen;
    QAction *actionLoad;
    QWidget *centralwidget;
    QSlider *fpsSlider;
    QPushButton *playPauseButton;
    QPushButton *brushButton;
    QPushButton *eraserButton;
    QPushButton *colorButton;
    QFrame *colorPreview;
    QTableWidget *pixelEditor;
    QGraphicsView *spritePreview;
    QTableWidget *framePreview;
    QPushButton *removeFrameButton;
    QPushButton *addFrameButton;
    QSlider *brushSizeSlider;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(145, 218, 218, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(false);
        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName("actionSAVE");
        actionSAVEAS = new QAction(MainWindow);
        actionSAVEAS->setObjectName("actionSAVEAS");
        actionOPEN = new QAction(MainWindow);
        actionOPEN->setObjectName("actionOPEN");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        fpsSlider = new QSlider(centralwidget);
        fpsSlider->setObjectName("fpsSlider");
        fpsSlider->setGeometry(QRect(590, 200, 101, 22));
        fpsSlider->setMinimum(1);
        fpsSlider->setMaximum(3);
        fpsSlider->setOrientation(Qt::Horizontal);
        fpsSlider->setTickPosition(QSlider::TicksBelow);
        playPauseButton = new QPushButton(centralwidget);
        playPauseButton->setObjectName("playPauseButton");
        playPauseButton->setGeometry(QRect(710, 195, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../../../battl/Downloads/playpause.png"), QSize(), QIcon::Normal, QIcon::Off);
        playPauseButton->setIcon(icon);
        playPauseButton->setIconSize(QSize(25, 25));
        brushButton = new QPushButton(centralwidget);
        brushButton->setObjectName("brushButton");
        brushButton->setGeometry(QRect(590, 300, 41, 41));
        QPalette palette1;
        QBrush brush2(QColor(157, 235, 235, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        brushButton->setPalette(palette1);
        QFont font;
        font.setStrikeOut(false);
        brushButton->setFont(font);
        brushButton->setAutoFillBackground(false);
        brushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(157, 235, 235);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../../../../battl/Downloads/brush Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        brushButton->setIcon(icon1);
        brushButton->setIconSize(QSize(30, 30));
        eraserButton = new QPushButton(centralwidget);
        eraserButton->setObjectName("eraserButton");
        eraserButton->setGeometry(QRect(590, 340, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../../../../battl/Downloads/Eraser_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraserButton->setIcon(icon2);
        eraserButton->setIconSize(QSize(35, 35));
        colorButton = new QPushButton(centralwidget);
        colorButton->setObjectName("colorButton");
        colorButton->setGeometry(QRect(660, 320, 41, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../../../../../battl/Downloads/color-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorButton->setIcon(icon3);
        colorButton->setIconSize(QSize(35, 35));
        colorPreview = new QFrame(centralwidget);
        colorPreview->setObjectName("colorPreview");
        colorPreview->setGeometry(QRect(710, 325, 31, 31));
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
        pixelEditor->setGeometry(QRect(20, 0, 450, 450));
        pixelEditor->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette2;
        QBrush brush3(QColor(170, 0, 0, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        QBrush brush4(QColor(0, 0, 0, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        QBrush brush6(QColor(0, 120, 215, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush7);
        pixelEditor->setPalette(palette2);
        pixelEditor->setMouseTracking(true);
        pixelEditor->setFocusPolicy(Qt::StrongFocus);
        pixelEditor->setStyleSheet(QString::fromUtf8(""));
        pixelEditor->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pixelEditor->setDragEnabled(false);
        pixelEditor->setShowGrid(true);
        pixelEditor->setRowCount(8);
        pixelEditor->setColumnCount(8);
        pixelEditor->horizontalHeader()->setVisible(false);
        pixelEditor->horizontalHeader()->setCascadingSectionResizes(false);
        pixelEditor->horizontalHeader()->setDefaultSectionSize(49);
        pixelEditor->verticalHeader()->setVisible(false);
        pixelEditor->verticalHeader()->setDefaultSectionSize(42);
        spritePreview = new QGraphicsView(centralwidget);
        spritePreview->setObjectName("spritePreview");
        spritePreview->setGeometry(QRect(560, 0, 241, 191));
        framePreview = new QTableWidget(centralwidget);
        if (framePreview->columnCount() < 8)
            framePreview->setColumnCount(8);
        if (framePreview->rowCount() < 1)
            framePreview->setRowCount(1);
        framePreview->setObjectName("framePreview");
        framePreview->setGeometry(QRect(20, 460, 540, 98));
        framePreview->setMouseTracking(true);
        framePreview->setShowGrid(true);
        framePreview->setRowCount(1);
        framePreview->setColumnCount(8);
        framePreview->horizontalHeader()->setVisible(false);
        framePreview->horizontalHeader()->setMinimumSectionSize(50);
        framePreview->horizontalHeader()->setDefaultSectionSize(80);
        framePreview->verticalHeader()->setVisible(false);
        framePreview->verticalHeader()->setDefaultSectionSize(80);
        removeFrameButton = new QPushButton(centralwidget);
        removeFrameButton->setObjectName("removeFrameButton");
        removeFrameButton->setEnabled(false);
        removeFrameButton->setGeometry(QRect(570, 500, 41, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bebas Neue")});
        font1.setPointSize(21);
        removeFrameButton->setFont(font1);
        removeFrameButton->setIcon(icon2);
        removeFrameButton->setIconSize(QSize(35, 35));
        addFrameButton = new QPushButton(centralwidget);
        addFrameButton->setObjectName("addFrameButton");
        addFrameButton->setGeometry(QRect(570, 460, 41, 41));
        addFrameButton->setFont(font1);
        addFrameButton->setIcon(icon2);
        addFrameButton->setIconSize(QSize(35, 35));
        brushSizeSlider = new QSlider(centralwidget);
        brushSizeSlider->setObjectName("brushSizeSlider");
        brushSizeSlider->setGeometry(QRect(480, 310, 101, 22));
        brushSizeSlider->setMinimum(1);
        brushSizeSlider->setMaximum(3);
        brushSizeSlider->setOrientation(Qt::Horizontal);
        brushSizeSlider->setTickPosition(QSlider::TicksBelow);
        brushSizeSlider->setTickInterval(1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName("fileMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(fileMenu->menuAction());
        fileMenu->addAction(actionSave);
        fileMenu->addSeparator();
        fileMenu->addAction(actionLoad);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSAVE->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSAVEAS->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionOPEN->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        playPauseButton->setText(QString());
        brushButton->setText(QString());
        eraserButton->setText(QString());
        colorButton->setText(QString());
        removeFrameButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        addFrameButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        fileMenu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
