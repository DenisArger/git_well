#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>
#include "primewindow.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

public slots:
    void clickEnterClick();
private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
