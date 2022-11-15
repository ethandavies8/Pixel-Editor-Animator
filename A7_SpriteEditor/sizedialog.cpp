#include "sizedialog.h"
#include "ui_sizedialog.h"
#include "model.h"

/*
* The Cuties
* CS3505
* Sprite Editor Implementation
*
* Reviewed by: Ethan Davies
*
* Class file for size dialog box which shows on initial startup
* From this size dialog the user is able to choose how big of a sprite to create in the sprite editor
*/


SizeDialog::SizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SizeDialog) {
    ui->setupUi(this);

    // When the button is clicked, the selected option on the combo box will be the size of the sprite
    connect(ui->createButton,
            &QPushButton::clicked,
            this,
            &SizeDialog::setSpriteSize
            );
}

SizeDialog::~SizeDialog() {
    delete ui;
}

// A slot for setting the size of the sprite based on the combo box
void SizeDialog::setSpriteSize() {
    switch (ui->sizeComboBox->currentIndex()) {
        case 0:
            size = 8; // 8x8
        break;
        case 1:
            size = 16; // 16x16
        break;
        case 2:
            size = 32; // 32x32
        break;
        case 3:
            size = 64; // 64x64
        break;
        default:
            size = 8; // Should never reach this
        break;
    }

    // Close the dialog after the button is pressed
    this->accept();
}

// Returns a model using the size chosen by the user
Model SizeDialog::getModel() {
    return Model(size);
}
