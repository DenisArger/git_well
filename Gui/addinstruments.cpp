#include "addinstruments.h"
#include "ui_addinstruments.h"

AddInstruments::AddInstruments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddInstruments)
{
    ui->setupUi(this);

    connect(ui->applyButton,SIGNAL(clicked(bool)), this, SLOT(addNewInstr()));
    connect(ui->applyButton,SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->cancelPushButton,SIGNAL(clicked(bool)), this, SLOT(close()));

    fillClassInstruments();
}

AddInstruments::~AddInstruments()
{
    delete ui;
}

void AddInstruments::addNewInstr()
{
    QString nameInstr;
    int idClassInstruments;
    QString balanceInstr;

    QString queryStr;

    nameInstr=ui->nameInstrLineEdit->text();
    idClassInstruments=ui->classInstrComboBox->currentIndex();
    balanceInstr=ui->balanceLineEdit->text();
    queryStr=QString("INSERT INTO  Instruments (idClassInstruments,nameInstruments,balance) \
    SELECT %1, '%2', %3").arg(idClassInstruments).arg(nameInstr).arg(balanceInstr);

    dataBase.queryToBase(queryStr);

}

void AddInstruments::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
}


void AddInstruments:: fillClassInstruments()
{
    ui->classInstrComboBox->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT ClassInstruments.* FROM ClassInstruments;");
    while(query.next()) {
        ui->classInstrComboBox->addItem(query.value(1).toString(), query.value(0));
    }
}
