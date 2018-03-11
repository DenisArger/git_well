#include "addinstruments.h"
#include "ui_addinstruments.h"

AddInstruments::AddInstruments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddInstruments),
    currentTab_(0)
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

void AddInstruments::showWindow()
{
    this->show();
    ui->classInstrComboBox->setCurrentIndex(currentTab_);
    if(currentTab_)
        ui->classInstrComboBox->setEnabled(false);
    else
        ui->classInstrComboBox->setEnabled(true);

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
    if(idLoginGlobal!=1){
        queryStr=QString("INSERT INTO  Instruments (idClassInstruments,nameInstruments,balance) \
                         SELECT %1, '%2', %3").arg(idClassInstruments).arg(nameInstr).arg(balanceInstr);
    }
    else{
        queryStr=QString("INSERT INTO  Instruments_Antony (idClassInstruments,nameInstruments,balance) \
                         SELECT %1, '%2', %3").arg(idClassInstruments).arg(nameInstr).arg(balanceInstr);
    }

    dataBase.queryToBase(queryStr);

}

void AddInstruments::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
}


void AddInstruments:: fillClassInstruments()
{
    ui->classInstrComboBox->clear();
    QString queryStr;
    if(idLoginGlobal!=1){
        queryStr="SELECT ClassInstruments.* FROM ClassInstruments;";
    }
    else{
        queryStr="SELECT ClassInstruments_Antony.* FROM ClassInstruments_Antony;";
    }
    QSqlQuery query=dataBase.queryToBase(queryStr);
    while(query.next()) {
        ui->classInstrComboBox->addItem(query.value(1).toString(), query.value(0));
    }
}

void AddInstruments::setCurrentTab(int currentTab)
{
    currentTab_=currentTab;
}
