#include "editinstrumentsdialog.h"
#include "ui_editinstrumentsdialog.h"
#include "QDebug"
#include "QSqlQuery"
#include "global.h"

EditInstrumentsDialog::EditInstrumentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditInstrumentsDialog),
    idDiameter_(0)
{
    ui->setupUi(this);

    connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->applyButton,SIGNAL(clicked(bool)),this,SLOT(clickApply()));
    connect(ui->applyButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->reCountButton,SIGNAL(clicked(bool)),this,SLOT(clickReCount()));
    connect(ui->resetButton,SIGNAL(clicked(bool)),this,SLOT(fillBalance()));
}

void EditInstrumentsDialog::showWindow()
{
    this->show();

    fillTypeOperation();
    fillTypeInstr();
    fillBalance();
    setCurrentDate();

    ui->typeInstrCombo->setCurrentIndex(currentTab_);
    if(currentTab_)
        ui->typeInstrCombo->setEnabled(false);
    else
        ui->typeInstrCombo->setEnabled(true);
}

EditInstrumentsDialog::~EditInstrumentsDialog()
{
    delete ui;
}


void EditInstrumentsDialog::clickApply()
{
    int idClassInstrument;
    int idInstrument;
    int typeOperation;
    QString dateOperation;
    double countInstr;
    QString source;
    QString notes;
    QString queryStr;


    idInstrument = ui->typeInstrCombo->currentIndex();
    typeOperation = ui->typeOperCombo->currentIndex();
    dateOperation = ui->dateEdit->text();
    countInstr = ui->countInstrEdit->text().toDouble();
    source = ui->sourseLineEdit->text();
    notes = ui->noteTextEdit->toPlainText();

    if(idLoginGlobal!=1){
        queryStr="INSERT INTO MovementInstruments (idInstruments, typeOperation, \
                dateOperation, countInstr, source, notes)";
                queryStr+=QString(" SELECT %1,%2,'%3',%4,'%5', '%6'").arg(idInstrument).arg(typeOperation).arg(dateOperation).arg(countInstr).arg(source).arg(notes);
    }
    else{
        queryStr="INSERT INTO MovementInstruments_Antony (idInstruments, typeOperation, \
                dateOperation, countInstr, source, notes)";
                queryStr+=QString(" SELECT %1,%2,'%3',%4,'%5', '%6'").arg(idInstrument).arg(typeOperation).arg(dateOperation).arg(countInstr).arg(source).arg(notes);

    }
    dataBase.queryToBase(queryStr);

    if(idLoginGlobal!=1){
        queryStr= QString( "UPDATE Instruments SET balance = %1 WHERE id=%2").arg( balance_).arg( idDiameter_);
    }
    else{
        queryStr= QString( "UPDATE Instruments_Antony SET balance = %1 WHERE id=%2").arg( balance_).arg( idDiameter_);
    }

    dataBase.queryToBase(queryStr);


    emit applyClick();
}

void EditInstrumentsDialog::fillTypeOperation()
{
    ui->typeOperCombo->clear();

    ui->typeOperCombo->addItem("");
    ui->typeOperCombo->addItem("Приход");
    ui->typeOperCombo->addItem("Расход");

}


void EditInstrumentsDialog::fillTypeInstr()
{
    ui->typeInstrCombo->clear();
    QSqlQuery query=dataBase.getQueryDiameter();
    while (query.next() ) {
        ui->typeInstrCombo->addItem(query.value(2).toString(), query.value(0));
    }
}


void EditInstrumentsDialog::comingOperation()
{

}



void EditInstrumentsDialog::consumptionOperaton()
{

}

void EditInstrumentsDialog::setIdDiameter(int idDiam)
{
    idDiameter_=idDiam;
}

void EditInstrumentsDialog::fillBalance()
{
    QString queryStr;
    if(idLoginGlobal!=1){
        queryStr=QString("SELECT balance FROM Instruments where id=%1").arg(idDiameter_);}
    else{
        queryStr=QString("SELECT balance FROM Instruments_Antony where id=%1").arg(idDiameter_);
    }

    QSqlQuery query= dataBase.queryToBase(queryStr);
    query.first();
    balance_=query.value(0).toDouble();
    ui->balanceLineEdit->setText(QString("%1").arg(balance_));
}


void EditInstrumentsDialog::setCurrTypeInstruments()
{
    ui->typeInstrCombo->setCurrentIndex(idDiameter_);
}


void EditInstrumentsDialog::clickReCount()
{
    fillBalance();
    //Приход
    if (ui->typeOperCombo->currentIndex()==1) {
        balance_+=ui->countInstrEdit->text().toDouble();
        ui->balanceLineEdit->setText(QString("%1").arg(balance_));
    }
    //Расход
    if (ui->typeOperCombo->currentIndex()==2) {
        balance_-=ui->countInstrEdit->text().toDouble();
        ui->balanceLineEdit->setText(QString("%1").arg(balance_));

    }

}



void EditInstrumentsDialog::setCurrentDate()
{
    QDate dateToday = QDate::currentDate();
    ui->dateEdit->setDate(dateToday);

}

void EditInstrumentsDialog::setCurrentTab(int currentTab)
{
    currentTab_=currentTab;
}
