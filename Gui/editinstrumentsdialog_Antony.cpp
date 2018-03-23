#include "editinstrumentsdialog_Antony.h"
#include "ui_editinstrumentsdialog.h"
#include "QDebug"
#include "QSqlQuery"
#include "global.h"

EditInstrumentsDialog_Antony::EditInstrumentsDialog_Antony(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditInstrumentsDialog),
    idInstrument_(0),
    stateConnectSetBalance(false),
    stateConnectSetNameClass(false),
    stateReCount(false)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile(QStringLiteral("../icon/well.png"), QSize(), QIcon::Disabled, QIcon::Off);
    this->setWindowIcon(icon);

    connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    //connect(ui->applyButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->reCountButton,SIGNAL(clicked(bool)),this,SLOT(reCount()));
    connect(ui->resetButton,SIGNAL(clicked(bool)),this,SLOT(fillBalance()));
}


void EditInstrumentsDialog_Antony::showEditBalanseWindow()
{
    fillClassInstrument();
    this->show();
    this->setWindowTitle("Изменение остатка материала");
    if(!stateConnectSetBalance)
        stateConnectSetBalance=connect(ui->applyButton,SIGNAL(clicked(bool)),this,SLOT(setBalance()));
    if(stateConnectSetNameClass)
        stateConnectSetNameClass=!(disconnect(ui->applyButton,SIGNAL(clicked(bool)),this,SLOT(setNameInstrument())));


    stateReCount=false;
    ui->dateEdit->clear();
    ui->countInstrEdit->clear();
    ui->sourseLineEdit->clear();
    ui->noteTextEdit->clear();



    ui->instrumentLineEdit->show();
    ui->typeInstrLabel->show();
    ui->typeOperLabel->show();
    ui->typeOperationCombo->show();
    ui->dateLabel->show();
    ui->dateEdit->show();
    ui->countInstrLabel->show();
    ui->countInstrEdit->show();
    ui->countInstrLabel_2->show();
    ui->sourseLineEdit->show();
    ui->noteLabel->show();
    ui->noteTextEdit->show();
    ui->groupBox_2->show();

    fillTypeOperation();
    fillInstrument();
    fillBalance();
    setCurrentDate();

    ui->classInstrumentCombo->setCurrentIndex(mapComboClassInstr_.key(getIdClassInstrument()));
    ui->instrumentLineEdit->setText(getNameInstrument());

    ui->classInstrumentCombo->setEnabled(false);
    ui->instrumentLineEdit->setEnabled(false);

}

void EditInstrumentsDialog_Antony::showEditInstrumentWindow()
{
    fillClassInstrument();
    this->show();
    this->setWindowTitle("Изменение материала");
    if(!stateConnectSetNameClass)
        stateConnectSetNameClass=connect(ui->applyButton,SIGNAL(clicked(bool)),this,SLOT(setNameInstrument()));
    if(stateConnectSetBalance)
        stateConnectSetBalance=!(disconnect(ui->applyButton,SIGNAL(clicked(bool)),this,SLOT(setBalance())));

    ui->typeOperLabel->hide();
    ui->typeOperationCombo->hide();
    ui->dateLabel->hide();
    ui->dateEdit->hide();
    ui->countInstrLabel->hide();
    ui->countInstrEdit->hide();
    ui->countInstrLabel_2->hide();
    ui->sourseLineEdit->hide();
    ui->noteLabel->hide();
    ui->noteTextEdit->hide();

    ui->groupBox_2->hide();
    //Изменить размеры окна
    ui->verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize); // !!! This is the what makes it auto-resize


    ui->classInstrumentCombo->setCurrentIndex(mapComboClassInstr_.key(getIdClassInstrument()));
    ui->instrumentLineEdit->setText(getNameInstrument());

    ui->classInstrumentCombo->setEnabled(true);
    ui->instrumentLineEdit->setEnabled(true);
}

EditInstrumentsDialog_Antony::~EditInstrumentsDialog_Antony()
{
    delete ui;
}


void EditInstrumentsDialog_Antony::setBalance()
{
    int typeOperation;
    QString dateOperation;
    double countInstr;
    QString source;
    QString notes;
    QString queryStr;



    typeOperation = ui->typeOperationCombo->currentIndex();
    dateOperation = ui->dateEdit->text();
    countInstr = ui->countInstrEdit->text().toDouble();
    source = ui->sourseLineEdit->text();
    notes = ui->noteTextEdit->toPlainText();

    if(!typeOperation){
         QMessageBox::warning(this, "Внимание","Не выбран тип операции.");
         return;
    }

    if(!stateReCount){
         QMessageBox::warning(this, "Внимание","Необходимо пересчитать остаток материала");
         return;
    }





   queryStr="INSERT INTO MovementInstruments_Antony (idInstruments, typeOperation, \
                dateOperation, countInstr, source, notes)";
   queryStr+=QString(" SELECT %1,%2,'%3',%4,'%5', '%6'").arg(idInstrument_).arg(typeOperation).arg(dateOperation).arg(countInstr).arg(source).arg(notes);
   dataBase.queryToBase(queryStr);


    queryStr= QString( "UPDATE Instruments_Antony SET balance = %1 WHERE id=%2").arg( balance_).arg( idInstrument_);
    dataBase.queryToBase(queryStr);

    close();
    emit applyClick();
}


void EditInstrumentsDialog_Antony::setNameInstrument()
{
    int idClassInstrument;
    QString nameInstrument;
    QString queryStr;

    idClassInstrument=mapComboClassInstr_.value(ui->classInstrumentCombo->currentIndex());
    nameInstrument = ui->instrumentLineEdit->text();


    if(idLoginGlobal!=1){
        queryStr= QString( "UPDATE Instruments SET idClassInstruments = %1,  \
nameInstruments='%2' WHERE id=%3").arg( idClassInstrument).arg(nameInstrument).arg( idInstrument_);
    }
    else{
        queryStr= QString( "UPDATE Instruments_Antony SET idClassInstruments = %1,  \
nameInstruments='%2' WHERE id=%3").arg( idClassInstrument).arg(nameInstrument).arg( idInstrument_);
    }

    dataBase.queryToBase(queryStr);

    close();
    emit applyClick();
}

void EditInstrumentsDialog_Antony::fillTypeOperation()
{
    ui->typeOperationCombo->clear();

    ui->typeOperationCombo->addItem("");
    ui->typeOperationCombo->addItem("Приход");
    ui->typeOperationCombo->addItem("Расход");

}


void EditInstrumentsDialog_Antony::fillInstrument()
{
    mapComboInstr_.clear();
    QSqlQuery query=dataBase.getQueryDiameter();
    int i=0;
    while (query.next() ) {
        mapComboInstr_.insert(i,query.value(0).toInt());
       i++;
    }
}

void EditInstrumentsDialog_Antony::fillClassInstrument()
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




void EditInstrumentsDialog_Antony::setIdInstrument(int idInstrument)
{
    idInstrument_=idInstrument;
}

void EditInstrumentsDialog_Antony::fillBalance()
{
    QString queryStr;
    queryStr=QString("SELECT balance FROM Instruments_Antony where id=%1").arg(idInstrument_);

    QSqlQuery query= dataBase.queryToBase(queryStr);
    query.first();
    balance_=query.value(0).toDouble();
    ui->balanceLineEdit->setText(QString("%1").arg(balance_));
}


void EditInstrumentsDialog_Antony::setCurrTypeInstruments()
{
    //ui->instrumentCombo->setCurrentIndex(idInstrument_);
}


void EditInstrumentsDialog_Antony::reCount()
{
    stateReCount=true;
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



void EditInstrumentsDialog_Antony::setCurrentDate()
{
    QDate dateToday = QDate::currentDate();
    ui->dateEdit->setDate(dateToday);

}

void EditInstrumentsDialog_Antony::setCurrentTab(int currentTab)
{
    currentTab_=currentTab;
}


QString EditInstrumentsDialog_Antony::getNameInstrument()
{
    QString queryStr;
    QSqlQuery query;
    QString nameInstrument;
    queryStr=QString("SELECT Instruments_Antony.nameInstruments\
                     FROM Instruments_Antony\
                     WHERE (((Instruments_Antony.id)=%1));").arg(idInstrument_);
    query=dataBase.queryToBase(queryStr);
    query.first();
    nameInstrument=query.value(0).toString();

    return nameInstrument;


}


int EditInstrumentsDialog_Antony::getIdClassInstrument()
{
    QString queryStr;
    QSqlQuery query;
    int idInstrument;
    queryStr=QString("SELECT Instruments_Antony.idClassInstruments\
                     FROM Instruments_Antony\
                     WHERE (((Instruments_Antony.id)=%1));").arg(idInstrument_);
    query=dataBase.queryToBase(queryStr);
    query.first();
    idInstrument=query.value(0).toInt();

    return idInstrument;

}
