#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>
#include "model.h"

namespace Ui {
class SizeDialog;
}

class SizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SizeDialog(QWidget *parent = nullptr);
    ~SizeDialog();
    Model getModel();

public slots:
    void setSpriteSize();

private:
    Ui::SizeDialog *ui;
    int size; // Size to be used to create model
};

#endif // SIZEDIALOG_H
