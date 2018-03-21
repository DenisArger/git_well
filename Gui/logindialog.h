#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>
#include "primewindow.h"
#include <QMessageBox>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

    bool checkUser();
    bool eventFilter(QObject *obj, QEvent *event);
public slots:
    void clickEnterClick();

private:
    Ui::LoginDialog *ui;
    QShortcut       *keyEnterReturn;    // объект горячей клавиши Enter (основная клавиатура)
    QShortcut       *keyEnter;    // объект горячей клавиши Enter (доп клавиатура)
    QShortcut       *keyEsc;    // объект горячей клавиши Esc
};

#endif // LOGINDIALOG_H
