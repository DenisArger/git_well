#include "Gui/mainwindow.h"
#include "Gui/primewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PrimeWindow w;
    w.show();

    return a.exec();
}
