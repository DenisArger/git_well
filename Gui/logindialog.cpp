#include "logindialog.h"
#include "ui_logindialog.h"

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
    PrimeWindow *pr= new PrimeWindow();
    pr->show();
}


