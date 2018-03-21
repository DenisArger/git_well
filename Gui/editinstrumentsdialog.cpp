#include "editinstrumentsdialog.h"
#include "ui_editinstrumentsdialog.h"
#include "QDebug"
#include "QSqlQuery"
#include "global.h"

EditInstrumentsDialog::EditInstrumentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditInstrumentsDialog),
    idInstrument_(0)
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
    fillInstrument();
    fillBalance();
    setCurrentDate();

    ui->instrumentCombo->setCurrentIndex(currentTab_);
    if(currentTab_)
        ui->instrumentCombo->setEnabled(false);
    else{
        ui->instrumentCombo->setEnabled(true);
    }
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


    idInstrument = ui->instrumentCombo->currentIndex();
    typeOperation = ui->typeOperationCombo->currentIndex();
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
        queryStr= QString( "UPDATE Instruments SET balance = %1 WHERE id=%2").arg( balance_).arg( idInstrument_);
    }
    else{
        queryStr= QString( "UPDATE Instruments_Antony SET balance = %1 WHERE id=%2").arg( balance_).arg( idInstrument_);
    }

    dataBase.queryToBase(queryStr);


    emit applyClick();
}

void EditInstrumentsDialog::fillTypeOperation()
{
    ui->typeOperationCombo->clear();

    ui->typeOperationCombo->addItem("");
    ui->typeOperationCombo->addItem("Приход");
    ui->typeOperationCombo->addItem("Расход");

}


void EditInstrumentsDialog::fillInstrument()
{
    ui->instrumentCombo->clear();
    mapComboInstr_.clear();
    QSqlQuery query=dataBase.getQueryDiameter();
    int i=0;
    while (query.next() ) {
        mapComboInstr_.insert(i,query.value(0).toInt());
        ui->instrumentCombo->addItem(query.value(2).toString(), query.value(0));
        i++;
    }
}

void EditInstrumentsDialog::fillClassInstrument()
{
    ui->classInstrumentCombo->clear();
    mapComboClassInstr_.clear();
    QString queryStr;
    QSqlQuery query;
    queryStr=QString("SELECT ClassInstruments.*\
                     FROM ClassInstruments;");
    query=dataBase.queryToBase(queryStr);
    int i=0;
    while (query.next() ) {
        mapComboClassInstr_.insert(i,query.value(0).toInt());
        ui->classInstrumentCombo->addItem(query.value(1).toString(), query.value(0));
        i++;
    }
}


void EditInstrumentsDialog::comingOperation()
{

}



void EditInstrumentsDialog::consumptionOperaton()
{

}

void EditInstrumentsDialog::setIdInstrument(int idInstrument)
{
    idInstrument_=idInstrument;
}

void EditInstrumentsDialog::fillBalance()
{
    QString queryStr;
    if(idLoginGlobal!=1){
        queryStr=QString("SELECT balance FROM Instruments where id=%1").arg(idInstrument_);}
    else{
        queryStr=QString("SELECT balance FROM Instruments_Antony where id=%1").arg(idInstrument_);
    }

    QSqlQuery query= dataBase.queryToBase(queryStr);
    query.first();
    balance_=query.value(0).toDouble();
    ui->balanceLineEdit->setText(QString("%1").arg(balance_));
}


void EditInstrumentsDialog::setCurrTypeInstruments()
{
    ui->instrumentCombo->setCurrentIndex(idInstrument_);
}


void EditInstrumentsDialog::clickReCount()
{
    fillBalance();
    //Приход
    if (ui->typeOperationCombo->currentIndex()==1) {
        balance_+=ui->countInstrEdit->text().toDouble();
        ui->balanceLineEdit->setText(QString("%1").arg(balance_));
    }
    //Расход
    if (ui->typeOperationCombo->currentIndex()==2) {
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
