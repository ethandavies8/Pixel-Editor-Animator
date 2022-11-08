#include "mainwindow.h"
#include "sizedialog.h"
#include "model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Start a dialog that asks for the size of the sprite
    // Will run until a size is chosen, then start the program
    SizeDialog s;
    s.setModal(true);
    s.exec();

    Model model = s.getModel();
    MainWindow w(model);
    w.show();
    return a.exec();
}
