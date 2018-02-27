#include "operationstock.h"
#include "ui_operationstock.h"
#include "QSqlQuery"
#include "global.h"

OperationStock::OperationStock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OperationStock)
{
    ui->setupUi(this);

    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(addNewInstr()));
    connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(close()));

}

OperationStock::~OperationStock()
{
    delete ui;
}

void OperationStock::addNewInstr()
{
    QString nameInstr;
    QString balanceInstr;
    QString queryStr;
    QSqlQuery query;

    nameInstr=ui->nameInstrLineEdit->text();
    balanceInstr=ui->balanceInstrLineEdit->text();
    queryStr=QString("INSERT INTO  Diameter (numberDiameter,balance) SELECT '%1', %2").arg(nameInstr).arg(balanceInstr);

    dataBase.queryToBase(queryStr);


}

void OperationStock::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
}
