#include "logindialog.h"
#include "ui_logindialog.h"
#include "QSplashScreen"
#include "busysplashwidget.h"
#include <QtConcurrent/QtConcurrent>

LoginDialog::LoginDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    connect(ui->enterButton,SIGNAL(clicked(bool)), this, SLOT(clickEnterClick()));
    connect(ui->cancelPushButton,SIGNAL(clicked(bool)),this, SLOT(close()));

}

LoginDialog::~LoginDialog()
{
    delete ui;
}



void LoginDialog::clickEnterClick()
{
    if(checkUser()){
        close();

        //BusySplashWidget splash("Please wait…", this);

        //QFutureWatcher<void> watcher;
        //connect(&watcher, SIGNAL(finished()), &splash, SLOT(quit()));

        //QFuture<void> future = QtConcurrent::run(ReadGiantZipFile);
        //watcher.setFuture(future);

        //splash.exec();

        PrimeWindow *pr= new PrimeWindow();
        pr->show();


    }
    else
        QMessageBox::warning(this, "Внимание","Проверьте правильность ввода логина или пароля");


}


bool LoginDialog::checkUser()
{
    bool check=false;
    QString loginStr= ui->loginLineEdit->text();
    QString passStr= ui->passLineEdit->text();
    QString queryStr="SELECT Login.NameLogin, Login.Password FROM Login;";
    QSqlQuery query= dataBase.queryToBase(queryStr);
    while(query.next()){
        if(loginStr==query.value(0).toString()){
            check= passStr==query.value(1).toString();
            break;
        }

    }
    return check;
}
