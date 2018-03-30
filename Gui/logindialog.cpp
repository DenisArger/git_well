#include "logindialog.h"
#include "ui_logindialog.h"
#include "QSplashScreen"
#include "busysplashwidget.h"
#include <QtConcurrent/QtConcurrent>
#include <QKeyEvent>

LoginDialog::LoginDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile(QStringLiteral("../icon/key.png"), QSize(), QIcon::Disabled, QIcon::Off);
    this->setWindowIcon(icon);



    keyEnterReturn = new QShortcut(this);   // Инициализируем объект
    keyEnter = new QShortcut(this);   // Инициализируем объект
    keyEsc = new QShortcut(this);   // Инициализируем объект

    keyEnterReturn->setKey(Qt::Key_Return);    // Устанавливаем код клавиши
    keyEnter->setKey(Qt::Key_Enter);    // Устанавливаем код клавиши
    keyEsc->setKey(Qt::Key_Escape);    // Устанавливаем код клавиши


    connect(keyEnterReturn, SIGNAL(activated()), this,SLOT(clickEnterClick()));
    connect(keyEnter, SIGNAL(activated()), this,SLOT(clickEnterClick()));
    connect(keyEsc, SIGNAL(activated()), this,SLOT(close()));
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
    QString queryStr="SELECT Login.ID,Login.NameLogin, Login.Password FROM Login;";
    QSqlQuery query= dataBase.queryToBase(queryStr);
    while(query.next()){
        if(loginStr==query.value(1).toString()){
            check= passStr==query.value(2).toString();
            idLoginGlobal=query.value(0).toInt();
            break;
        }

    }
    return check;
}


bool LoginDialog::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            clickEnterClick();
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}
