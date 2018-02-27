#include "clientscardwindows.h"
#include "ui_clientscardwindows.h"
#include "QDesktopWidget"

clientsCardWindows::clientsCardWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientsCardWindows),
    stateSave(true)
{
    ui->setupUi(this);
    fillRegion();
    fillDistrict_FULL();
    fillDiameter();
    fillDate();

    ui->dataBegindateEdit->setEnabled(false);
    ui->dataEndDateEdit->setEnabled(false);

   // ui->regionCombo->setCurrentIndex(-1);
   // ui->diameterCombo->setCurrentIndex(-1);
   // ui->regionCombo->setEditable (true);
    //ui->regionCombo->setCompleter ();

    connect(ui->regionCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(fillDistrict()));

    this->setMinimumSize(gWidth*0.50,gHeight*0.89);
    this->setMaximumSize(gWidth,gHeight);
    this->resize(gWidth * PERCENT_OF_SCREEN_WIDTH, gHeight * PERCENT_OF_SCREEN_HEIGHT);

    //Отображение окна по центру экрана
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);

}

clientsCardWindows::~clientsCardWindows()
{
    delete ui;
}

void clientsCardWindows::fillRegion()
{
    ui->regionCombo->clear();
    QSqlQuery query=dataBase.getQueryRegion();
    while(query.next()) {
        ui->regionCombo->addItem(query.value(1).toString(), query.value(0));
    }
}
/*
void clientsCardWindows::fillClientCart(personale pers)
{
    if(pers.dataBegin.toString()!="")
        ui->dataBegindateEdit->setEnabled(true);
    if(pers.dataEnd.toString()!="")
        ui->dataEndDateEdit->setEnabled(true);

    ui->surnameLineEdit->setText(pers.surname);
    ui->nameLineEdit->setText(pers.name);
    ui->patronymicLineEdit->setText(pers.patronymic);
    ui->mobilPhoneLineEdit->setText(pers.phone);
    ui->regionCombo->setCurrentIndex(pers.id_region);
    ui->districtCombo->setCurrentIndex(pers.id_district);
    ui->localityLineEdit->setText(pers.locality);
    ui->streetLineEdit->setText(pers.street);
    ui->depthLineEdit->setText(pers.dept);
    ui->diameterCombo->setCurrentIndex(pers.id_diameter);
    ui->pumpCheckBox->setChecked(pers.pump);
    ui->serviseCheckBox->setChecked(pers.service);
    ui->dataBegindateEdit->setDateTime(pers.dataBegin);
    ui->dataEndDateEdit->setDateTime(pers.dataEnd);
    ui->noteEdit->setText(pers.note);
}
*/
void clientsCardWindows::fillDistrict()
{
    ui->districtCombo->clear();
    int id_Region=ui->regionCombo->currentIndex();
    QSqlQuery query=dataBase.getQueryDistrict(id_Region);
    while (query.next()) {
        ui->districtCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void clientsCardWindows::fillDistrict_FULL()
{
    ui->districtCombo->clear();
    QSqlQuery query=dataBase.getQueryDistrict_FULL();
    while (query.next()) {
        ui->districtCombo->addItem(query.value(1).toString(), query.value(0));
    }
}



void clientsCardWindows::fillDiameter()
{
    ui->diameterCombo->clear();
    QSqlQuery query=dataBase.getQueryDiameter();
    while (query.next()) {
        ui->diameterCombo->addItem(query.value(1).toString(), query.value(0));
    }
}


void clientsCardWindows::fillDate()
{
    QDate dateToday = QDate::currentDate();
    ui->dataBegindateEdit->setDate(dateToday);
    ui->dataEndDateEdit->setDate(dateToday);
}

void clientsCardWindows::on_closeButton_clicked()
{
    close();
}



void clientsCardWindows::on_pushButton_clicked()
{
    if(stateSave)
        createNewClient();
    else
        updateClient();
    close();

}


void  clientsCardWindows::createNewClient()
{
    QString surname, name,patronymic,mobilPhone;
    int id_district, id_diameter;
    QString locality,street,dept;
    QString dataBegin,dataEnd,notes;
    bool pump,service;
    QString query;

    surname=ui->surnameLineEdit->text();
    name=ui->nameLineEdit->text();
    patronymic=ui->patronymicLineEdit->text();
    mobilPhone=ui->mobilPhoneLineEdit->text();

    id_district=ui->districtCombo->currentIndex();
    id_diameter=ui->diameterCombo->currentIndex();

    locality=ui->localityLineEdit->text();
    street=ui->streetLineEdit->text();
    dept=ui->depthLineEdit->text();
    if(dept=="")
        dept="0";


    dataBegin=ui->dataBegindateEdit->text();

    if(ui->dataEndCheckBox->isChecked())
         dataEnd=ui->dataEndDateEdit->text();



    pump=ui->pumpCheckBox->isChecked();
    service=ui->serviseCheckBox->isChecked();


    notes=ui->noteEdit->toPlainText();

    query= QString("INSERT INTO ClientsCard (surname, name_, patronymic, mobilPhone, \
                   id_district, locality, street,dept, id_diameter, pump, service,");
    if(ui->dataBeginCheckBox->isChecked())
         query+=QString(" dataBegin, ");
    if(ui->dataEndCheckBox->isChecked())
         query+=QString(" dataEnd, ");

    query+= QString(" notes )  SELECT '%1','%2','%3','%4', %5, '%6', '%7', %8, %9, %10, %11" ).arg(surname).arg(name).\
            arg(patronymic).arg(mobilPhone).arg(id_district).arg(locality).\
            arg(street).arg(dept).arg(id_diameter).arg(pump).arg(service);

    if(ui->dataBeginCheckBox->isChecked())
         query+=QString(" ,'%1' ").arg(dataBegin);
    if(ui->dataEndCheckBox->isChecked())
        query+=QString(" ,'%1' ").arg(dataEnd);

    query+=QString(" ,'%1' ").arg(notes);


    qDebug()<<query;
    dataBase.queryToBase(query);

    query="SELECT @@Identity";
    QSqlQuery queryNew=dataBase.queryToBase(query);

    queryNew.first();
    int idClient=queryNew.value(0).toInt();

    if(ui->serviseCheckBox->isChecked())
        createServiceClient(idClient);
}


void clientsCardWindows::updateClient()
{
    QString surname, name,patronymic,mobilPhone;
    int id_district, id_diameter;
    QString locality,street,dept;
    QString dataBegin,dataEnd,notes;
    bool pump,service;
    QString query;

    surname=ui->surnameLineEdit->text();
    name=ui->nameLineEdit->text();
    patronymic=ui->patronymicLineEdit->text();
    mobilPhone=ui->mobilPhoneLineEdit->text();

    id_district=ui->districtCombo->currentIndex();
    id_diameter=ui->diameterCombo->currentIndex();

    locality=ui->localityLineEdit->text();
    street=ui->streetLineEdit->text();
    dept=ui->depthLineEdit->text();

    dataBegin=ui->dataBegindateEdit->text();

    if(ui->dataEndCheckBox->isChecked())
         dataEnd=ui->dataEndDateEdit->text();

    pump=ui->pumpCheckBox->isChecked();
    service=ui->serviseCheckBox->isChecked();


    notes=ui->noteEdit->toPlainText();


    query= QString( "update ClientsCard set surname = '%1', name_='%2', patronymic='%3', mobilPhone='%4', \
                   id_district=%5, locality='%6', street='%7',dept='%8', id_diameter=%9, pump=%10, service='%11',").arg(surname).arg(name).\
                    arg(patronymic).arg(mobilPhone).arg(id_district).arg(locality).\
                    arg(street).arg(dept).arg(id_diameter).arg(pump).arg(service);
    if(ui->dataBeginCheckBox->isChecked())
         query+=QString(" dataBegin='%1', ").arg(dataBegin);
    if(ui->dataEndCheckBox->isChecked())
         query+=QString(" dataEnd='%1', ").arg(dataEnd);

    query+=QString(" notes='%1' where ID=%2 ").arg(notes).arg(id_client);


    //qDebug()<<query;
    dataBase.queryToBase(query);

    query=QString("Select COUNT(*) from Service  where idClient=%1").arg(id_client);
    QSqlQuery queryNew= dataBase.queryToBase(query);
    queryNew.first();
   // qDebug()<<queryNew.value(0).toInt();
            if(!(queryNew.value(0).toInt())&& ui->serviseCheckBox->isChecked())
                createServiceClient(id_client);



}

/*Ui::clientsCardWindows *clientsCardWindows::getUIClientsCardWindows()
{
    return ui;
}
*/
void clientsCardWindows::setStateSave(bool state)
{
    stateSave=state;
}

void clientsCardWindows::setIdClient(int id)
{
    id_client=id;
}

void clientsCardWindows::on_dataBeginCheckBox_clicked()
{
    if(ui->dataBeginCheckBox->isChecked())
        ui->dataBegindateEdit->setEnabled(true);
    else
        ui->dataBegindateEdit->setEnabled(false);
}

void clientsCardWindows::on_dataEndCheckBox_clicked()
{
    if(ui->dataEndCheckBox->isChecked())
        ui->dataEndDateEdit->setEnabled(true);
    else
        ui->dataEndDateEdit->setEnabled(false);
}


void clientsCardWindows::createServiceClient(int idClient)
{
    QString query= QString("INSERT INTO Service (idClient, stateService)");

    query+= QString(" SELECT %1,%2" ).arg(idClient).arg(-1);

    dataBase.queryToBase(query);
}
