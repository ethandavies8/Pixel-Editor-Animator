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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QLabel *spritePreviewLabel;
    QLabel *fpsLabel;
    QLabel *borderLabel;
    QLabel *borderLabel_2;
    QLabel *borderLabel_3;
    QLabel *borderLabel_4;
    QLabel *borderLabel_5;
    QPushButton *removeFrameButton;
    QPushButton *addFrameButton;
    QSlider *brushSizeSlider;
    QTableWidget *framePreview;
    QPushButton *resizeButton;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(225, 225, 225, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
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
        fpsSlider->setGeometry(QRect(590, 235, 101, 22));
        fpsSlider->setStyleSheet(QString::fromUtf8("color: rgb(71, 212, 212);"));
        fpsSlider->setMinimum(1);
        fpsSlider->setMaximum(20);
        fpsSlider->setSingleStep(0);
        fpsSlider->setPageStep(0);
        fpsSlider->setOrientation(Qt::Horizontal);
        fpsSlider->setTickPosition(QSlider::TicksBelow);
        playPauseButton = new QPushButton(centralwidget);
        playPauseButton->setObjectName("playPauseButton");
        playPauseButton->setGeometry(QRect(700, 230, 31, 31));
        playPauseButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 212, 212);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/playpause.png"), QSize(), QIcon::Normal, QIcon::Off);
        playPauseButton->setIcon(icon);
        playPauseButton->setIconSize(QSize(25, 25));
        brushButton = new QPushButton(centralwidget);
        brushButton->setObjectName("brushButton");
        brushButton->setGeometry(QRect(560, 335, 41, 41));
        QPalette palette1;
        QBrush brush1(QColor(71, 212, 212, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        brushButton->setPalette(palette1);
        brushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 212, 212);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/brush Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        brushButton->setIcon(icon1);
        brushButton->setIconSize(QSize(30, 30));
        eraserButton = new QPushButton(centralwidget);
        eraserButton->setObjectName("eraserButton");
        eraserButton->setGeometry(QRect(560, 375, 41, 41));
        eraserButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 212, 212);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/Eraser_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraserButton->setIcon(icon2);
        eraserButton->setIconSize(QSize(35, 35));
        colorButton = new QPushButton(centralwidget);
        colorButton->setObjectName("colorButton");
        colorButton->setGeometry(QRect(630, 375, 41, 41));
        colorButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 212, 212);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/color-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorButton->setIcon(icon3);
        colorButton->setIconSize(QSize(35, 35));
        colorPreview = new QFrame(centralwidget);
        colorPreview->setObjectName("colorPreview");
        colorPreview->setGeometry(QRect(680, 380, 31, 31));
        colorPreview->setAutoFillBackground(false);
        colorPreview->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        colorPreview->setFrameShape(QFrame::StyledPanel);
        colorPreview->setFrameShadow(QFrame::Raised);
        pixelEditor = new QTableWidget(centralwidget);
        if (pixelEditor->columnCount() < 8)
            pixelEditor->setColumnCount(8);
        if (pixelEditor->rowCount() < 8)
            pixelEditor->setRowCount(8);
        pixelEditor->setObjectName("pixelEditor");
        pixelEditor->setGeometry(QRect(20, 0, 461, 450));
        pixelEditor->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush2(QColor(170, 0, 0, 0));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(0, 0, 0, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush4(QColor(240, 240, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush6(QColor(0, 120, 215, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush7);
        pixelEditor->setPalette(palette2);
        pixelEditor->setMouseTracking(true);
        pixelEditor->setFocusPolicy(Qt::StrongFocus);
        pixelEditor->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
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
        spritePreviewLabel = new QLabel(centralwidget);
        spritePreviewLabel->setObjectName("spritePreviewLabel");
        spritePreviewLabel->setGeometry(QRect(540, 20, 200, 200));
        spritePreviewLabel->setAutoFillBackground(false);
        spritePreviewLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spritePreviewLabel->setAlignment(Qt::AlignCenter);
        fpsLabel = new QLabel(centralwidget);
        fpsLabel->setObjectName("fpsLabel");
        fpsLabel->setGeometry(QRect(700, 20, 41, 20));
        fpsLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0)"));
        borderLabel = new QLabel(centralwidget);
        borderLabel->setObjectName("borderLabel");
        borderLabel->setGeometry(QRect(480, -30, 2, 479));
        borderLabel->setStyleSheet(QString::fromUtf8("border-color: rgb(85, 85, 85);\n"
"background-color: rgb(85, 85, 85);"));
        borderLabel_2 = new QLabel(centralwidget);
        borderLabel_2->setObjectName("borderLabel_2");
        borderLabel_2->setGeometry(QRect(20, -30, 5, 475));
        borderLabel_2->setStyleSheet(QString::fromUtf8("border-color: rgb(85, 85, 85);\n"
"background-color: rgb(85, 85, 85);"));
        borderLabel_3 = new QLabel(centralwidget);
        borderLabel_3->setObjectName("borderLabel_3");
        borderLabel_3->setGeometry(QRect(20, 445, 780, 5));
        borderLabel_3->setStyleSheet(QString::fromUtf8("border-color: rgb(85, 85, 85);\n"
"background-color: rgb(85, 85, 85);"));
        borderLabel_4 = new QLabel(centralwidget);
        borderLabel_4->setObjectName("borderLabel_4");
        borderLabel_4->setGeometry(QRect(20, 0, 780, 5));
        borderLabel_4->setStyleSheet(QString::fromUtf8("border-color: rgb(85, 85, 85);\n"
"background-color: rgb(85, 85, 85);"));
        borderLabel_5 = new QLabel(centralwidget);
        borderLabel_5->setObjectName("borderLabel_5");
        borderLabel_5->setGeometry(QRect(795, 0, 5, 450));
        borderLabel_5->setStyleSheet(QString::fromUtf8("border-color: rgb(85, 85, 85);\n"
"background-color: rgb(85, 85, 85);"));
        removeFrameButton = new QPushButton(centralwidget);
        removeFrameButton->setObjectName("removeFrameButton");
        removeFrameButton->setEnabled(false);
        removeFrameButton->setGeometry(QRect(670, 500, 41, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        removeFrameButton->setPalette(palette3);
        QFont font;
        font.setFamilies({QString::fromUtf8("Bebas Neue")});
        font.setPointSize(21);
        removeFrameButton->setFont(font);
        removeFrameButton->setAutoFillBackground(false);
        removeFrameButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 212, 212);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../../../battl/Downloads/Eraser_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeFrameButton->setIcon(icon4);
        removeFrameButton->setIconSize(QSize(35, 35));
        addFrameButton = new QPushButton(centralwidget);
        addFrameButton->setObjectName("addFrameButton");
        addFrameButton->setGeometry(QRect(670, 460, 41, 41));
        addFrameButton->setFont(font);
        addFrameButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 212, 212);"));
        addFrameButton->setIcon(icon4);
        addFrameButton->setIconSize(QSize(35, 35));
        brushSizeSlider = new QSlider(centralwidget);
        brushSizeSlider->setObjectName("brushSizeSlider");
        brushSizeSlider->setGeometry(QRect(610, 340, 101, 22));
        brushSizeSlider->setMinimum(1);
        brushSizeSlider->setMaximum(3);
        brushSizeSlider->setOrientation(Qt::Horizontal);
        brushSizeSlider->setTickPosition(QSlider::TicksBelow);
        brushSizeSlider->setTickInterval(1);
        framePreview = new QTableWidget(centralwidget);
        if (framePreview->columnCount() < 8)
            framePreview->setColumnCount(8);
        if (framePreview->rowCount() < 1)
            framePreview->setRowCount(1);
        framePreview->setObjectName("framePreview");
        framePreview->setGeometry(QRect(20, 460, 642, 81));
        framePreview->setMouseTracking(true);
        framePreview->setRowCount(1);
        framePreview->setColumnCount(8);
        framePreview->horizontalHeader()->setVisible(false);
        framePreview->horizontalHeader()->setMinimumSectionSize(50);
        framePreview->horizontalHeader()->setDefaultSectionSize(80);
        framePreview->verticalHeader()->setVisible(false);
        framePreview->verticalHeader()->setDefaultSectionSize(80);
        resizeButton = new QPushButton(centralwidget);
        resizeButton->setObjectName("resizeButton");
        resizeButton->setGeometry(QRect(550, 230, 31, 31));
        resizeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 212, 212);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/resizeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        resizeButton->setIcon(icon5);
        resizeButton->setIconSize(QSize(31, 31));
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
        spritePreviewLabel->setText(QString());
        fpsLabel->setText(QCoreApplication::translate("MainWindow", "fps:1", nullptr));
        borderLabel->setText(QString());
        borderLabel_2->setText(QString());
        borderLabel_3->setText(QString());
        borderLabel_4->setText(QString());
        borderLabel_5->setText(QString());
        removeFrameButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        addFrameButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        resizeButton->setText(QString());
        fileMenu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
