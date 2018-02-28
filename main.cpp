#include "Gui/logindialog.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog *lg= new LoginDialog();
    lg->show();



    return a.exec();
}
