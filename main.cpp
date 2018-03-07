#include "config.h"

#ifndef DEBUG
#include "Gui/logindialog.h"
#else
#include "GUI/primewindow.h"
#endif


#include <QApplication>


int main(int argc, char *argv[])
{
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);

    QApplication a(argc, argv);

    #ifndef DEBUG
    LoginDialog *lg= new LoginDialog();
    lg->show();
    #else
    PrimeWindow *pr=new PrimeWindow();
    pr->show();
    #endif


    return a.exec();
}
