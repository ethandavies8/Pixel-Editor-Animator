/********************************************************************************
** Form generated from reading UI file 'sizedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZEDIALOG_H
#define UI_SIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SizeDialog
{
public:
    QComboBox *sizeComboBox;
    QLabel *instructionLabel;
    QLabel *dialogLabel;
    QPushButton *createButton;

    void setupUi(QDialog *SizeDialog)
    {
        if (SizeDialog->objectName().isEmpty())
            SizeDialog->setObjectName("SizeDialog");
        SizeDialog->resize(400, 107);
        sizeComboBox = new QComboBox(SizeDialog);
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->setObjectName("sizeComboBox");
        sizeComboBox->setGeometry(QRect(330, 10, 50, 22));
        QFont font;
        font.setFamilies({QString::fromUtf8("Small Fonts")});
        font.setPointSize(8);
        sizeComboBox->setFont(font);
        sizeComboBox->setEditable(false);
        instructionLabel = new QLabel(SizeDialog);
        instructionLabel->setObjectName("instructionLabel");
        instructionLabel->setGeometry(QRect(10, 70, 209, 26));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Small Fonts")});
        font1.setPointSize(11);
        instructionLabel->setFont(font1);
        instructionLabel->setWordWrap(true);
        dialogLabel = new QLabel(SizeDialog);
        dialogLabel->setObjectName("dialogLabel");
        dialogLabel->setGeometry(QRect(6, 6, 286, 63));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roman")});
        dialogLabel->setFont(font2);
        createButton = new QPushButton(SizeDialog);
        createButton->setObjectName("createButton");
        createButton->setGeometry(QRect(249, 70, 131, 20));
        createButton->setFont(font);

        retranslateUi(SizeDialog);

        QMetaObject::connectSlotsByName(SizeDialog);
    } // setupUi

    void retranslateUi(QDialog *SizeDialog)
    {
        SizeDialog->setWindowTitle(QCoreApplication::translate("SizeDialog", "Dialog", nullptr));
        sizeComboBox->setItemText(0, QCoreApplication::translate("SizeDialog", "8x8", nullptr));
        sizeComboBox->setItemText(1, QCoreApplication::translate("SizeDialog", "16x16", nullptr));
        sizeComboBox->setItemText(2, QCoreApplication::translate("SizeDialog", "32x32", nullptr));
        sizeComboBox->setItemText(3, QCoreApplication::translate("SizeDialog", "64x64", nullptr));

        instructionLabel->setText(QCoreApplication::translate("SizeDialog", "This will determine the size of the sprite.\n"
"Cannot be changed after creation.", nullptr));
        dialogLabel->setText(QCoreApplication::translate("SizeDialog", "CHOOSE SIZE", nullptr));
        createButton->setText(QCoreApplication::translate("SizeDialog", "CREATE PROJECT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SizeDialog: public Ui_SizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZEDIALOG_H
