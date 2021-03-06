#include "cardclientwindows.h"
#include "ui_cardclientwindows.h"

CardClientWindows::CardClientWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CardClientWindows),
    stateSave(true),
    id_client(-1)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile(QStringLiteral("../icon/well.png"), QSize(), QIcon::Disabled, QIcon::Off);
    this->setWindowIcon(icon);

    connect(ui->regionCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(fillDistrict()));
    connect(ui->closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(clickSaveButton()));
    connect(ui->dataBeginCheckBox, SIGNAL(clicked(bool)), this, SLOT(clickDataBeginCheckBox()));
    connect(ui->dataEndCheckBox, SIGNAL(clicked(bool)), this, SLOT(clickDataEndCheckBox()));

}

void CardClientWindows::showWindow()
{
    this->show();

    fillRegion();
    fillDistrict_FULL();
    fillDiameter();
    fillDate();

    ui->dataBegindateEdit->setEnabled(false);
    ui->dataEndDateEdit->setEnabled(false);
}

CardClientWindows::~CardClientWindows()
{
    delete ui;
}


void CardClientWindows::fillRegion()
{
    ui->regionCombo->clear();
    mapComboGegion_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->regionCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->regionCombo->setEditable(true);
    QSqlQuery query=dataBase.getQueryRegion();
    int i=0;
    while(query.next()) {
         //заполнение словаря
        mapComboGegion_.insert(i,query.value(0).toInt());
        ui->regionCombo->addItem(query.value(1).toString(), query.value(0));
        i++;
    }

    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT Region.region\
                     FROM Region;");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->regionCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->regionCombo->setCompleter(completer);
    ui->regionCombo->setAutoCompletion(true);

}

void CardClientWindows::fillClientCart(personale pers)
{
    if(pers.dataBegin.toString()!="")
        ui->dataBegindateEdit->setEnabled(true);
    if(pers.dataEnd.toString()!="")
        ui->dataEndDateEdit->setEnabled(true);

    ui->surnameLineEdit->setText(pers.surname);
    ui->nameLineEdit->setText(pers.name);
    ui->patronymicLineEdit->setText(pers.patronymic);
    ui->mobilPhoneLineEdit->setText(pers.phone);
    ui->otherPhoneLineEdit->setText(pers.otherPhone);
    ui->regionCombo->setCurrentIndex(mapComboGegion_.key(pers.id_region));
    ui->districtCombo->setCurrentIndex(mapComboDistrict_.key(pers.id_district));
    ui->localityLineEdit->setText(pers.locality);
    ui->streetLineEdit->setText(pers.street);
    ui->depthLineEdit->setText(pers.dept);
    ui->diameterCombo->setCurrentIndex(mapComboInstrument_.key(pers.id_diameter));
    ui->pumpCheckBox->setChecked(pers.pump);
    ui->serviseCheckBox->setChecked(pers.service);
    ui->dataBegindateEdit->setDateTime(pers.dataBegin);
    ui->dataEndDateEdit->setDateTime(pers.dataEnd);
    ui->noteEdit->setText(pers.note);
}

void CardClientWindows::fillDistrict()
{
    ui->districtCombo->clear();
    mapComboDistrict_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->districtCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->districtCombo->setEditable(true);

    int id_Region=ui->regionCombo->currentIndex();
    QSqlQuery query=dataBase.getQueryDistrict(id_Region);
    int i=0;
    while (query.next()) {
         //заполнение словаря
        mapComboDistrict_.insert(i,query.value(0).toInt());
        ui->districtCombo->addItem(query.value(1).toString(), query.value(0));
        i++;
    }

    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT District.district\
                     FROM District\
                     WHERE (((District.id_region)=%1))\
                     ORDER BY District.district;").arg(id_Region);

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->districtCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->districtCombo->setCompleter(completer);
    ui->districtCombo->setAutoCompletion(true);
}

void CardClientWindows::clickSaveButton()
{
    if(stateSave)
        createNewClient();
    else
        updateClient();
    close();

}

void CardClientWindows::clickDataBeginCheckBox()
{
    if(ui->dataBeginCheckBox->isChecked())
        ui->dataBegindateEdit->setEnabled(true);
    else
        ui->dataBegindateEdit->setEnabled(false);

}

void CardClientWindows::clickDataEndCheckBox()
{
    if(ui->dataEndCheckBox->isChecked())
        ui->dataEndDateEdit->setEnabled(true);
    else
        ui->dataEndDateEdit->setEnabled(false);

}

void CardClientWindows::defaultContenWindow()
{
    ui->surnameLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->patronymicLineEdit->clear();
    ui->mobilPhoneLineEdit->clear();
    ui->otherPhoneLineEdit->clear();


    ui->regionCombo->setCurrentIndex(0);
    ui->districtCombo->setCurrentIndex(0);
    ui->localityLineEdit->clear();
    ui->streetLineEdit->clear();

    ui->dataBeginCheckBox->setChecked(false);
    ui->dataEndCheckBox->setChecked(false);

    ui->dataBegindateEdit->setEnabled(false);
    ui->dataEndDateEdit->setEnabled(false);

    fillDate();

    ui->depthLineEdit->clear();
    ui->diameterCombo->setCurrentIndex(0);
    ui->pumpCheckBox->setChecked(false);
    ui->serviseCheckBox->setChecked(false);
    ui->noteEdit->clear();

}

void CardClientWindows::fillDistrict_FULL()
{
    ui->districtCombo->clear();
    mapComboDistrict_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->districtCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->districtCombo->setEditable(true);
    QSqlQuery query=dataBase.getQueryDistrict_FULL();
    int i=0;
    while (query.next()) {
        //заполнение словаря
        mapComboDistrict_.insert(i,query.value(0).toInt());
        ui->districtCombo->addItem(query.value(1).toString(), query.value(0));
        i++;
    }


    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT District.district\
                     FROM District;");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->districtCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->districtCombo->setCompleter(completer);
    ui->districtCombo->setAutoCompletion(true);

}



void CardClientWindows::fillDiameter()
{
    ui->diameterCombo->clear();
    mapComboInstrument_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->diameterCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->diameterCombo->setEditable(true);
    QSqlQuery query=dataBase.getQueryDiameter();
    int i=0;
    while (query.next()) {
        ui->diameterCombo->addItem(query.value(2).toString(), query.value(0));
        mapComboInstrument_.insert(i,query.value(0).toInt());
                i++;
    }


    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT Instruments.nameInstruments\
                     FROM Instruments\
                     WHERE (((Instruments.idClassInstruments)=1));");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->diameterCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->diameterCombo->setCompleter(completer);
    ui->diameterCombo->setAutoCompletion(true);
}


void CardClientWindows::fillDate()
{
    QDate dateToday = QDate::currentDate();
    ui->dataBegindateEdit->setDate(dateToday);
    ui->dataEndDateEdit->setDate(dateToday);
}


void  CardClientWindows::createNewClient()
{
    QString surname, name,patronymic,mobilPhone, otherPhone;
    int id_district, id_diameter;
    QString locality,street,dept;
    QString dataBegin,dataEnd,notes;
    bool pump,service;
    QString query;

    surname=ui->surnameLineEdit->text();
    name=ui->nameLineEdit->text();
    patronymic=ui->patronymicLineEdit->text();
    mobilPhone=ui->mobilPhoneLineEdit->text();
    otherPhone=ui->otherPhoneLineEdit->text();

    id_district=mapComboDistrict_.value(ui->districtCombo->currentIndex());
    id_diameter=mapComboInstrument_.value(ui->diameterCombo->currentIndex());

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



    query= QString("INSERT INTO ClientsCard (surname, name_, patronymic, mobilPhone,otherPhone, \
                   id_district, locality, street,dept, id_instruments, pump, service,");
                   if(ui->dataBeginCheckBox->isChecked())
                   query+=QString(" dataBegin, ");
            if(ui->dataEndCheckBox->isChecked())
            query+=QString(" dataEnd, ");

    query+= QString(" notes )  SELECT '%1','%2','%3','%4', '%5', %6, '%7', '%8', %9, %10, %11, %12" ).arg(surname).arg(name).\
            arg(patronymic).arg(mobilPhone).arg(otherPhone).arg(id_district).arg(locality).\
            arg(street).arg(dept).arg(id_diameter).arg(pump).arg(service);

    if(ui->dataBeginCheckBox->isChecked())
        query+=QString(" ,'%1' ").arg(dataBegin);
    if(ui->dataEndCheckBox->isChecked())
        query+=QString(" ,'%1' ").arg(dataEnd);

    query+=QString(" ,'%1' ").arg(notes);

    dataBase.queryToBase(query);

    query="SELECT @@Identity";
    QSqlQuery queryNew=dataBase.queryToBase(query);

    queryNew.first();
    int idClient=queryNew.value(0).toInt();

    if(ui->serviseCheckBox->isChecked())
        createServiceClient(idClient);
}


void CardClientWindows::updateClient()
{
    QString surname, name,patronymic,mobilPhone, otherPhone;
    int id_district, id_diameter;
    QString locality,street,dept;
    QString dataBegin,dataEnd,notes;
    bool pump,service;
    QString query;

    surname=ui->surnameLineEdit->text();
    name=ui->nameLineEdit->text();
    patronymic=ui->patronymicLineEdit->text();
    mobilPhone=ui->mobilPhoneLineEdit->text();
    otherPhone=ui->otherPhoneLineEdit->text();

    id_district=mapComboDistrict_.value(ui->districtCombo->currentIndex());
    id_diameter=mapComboInstrument_.value(ui->diameterCombo->currentIndex());

    locality=ui->localityLineEdit->text();
    street=ui->streetLineEdit->text();
    dept=ui->depthLineEdit->text();

    dataBegin=ui->dataBegindateEdit->text();

    if(ui->dataEndCheckBox->isChecked())
        dataEnd=ui->dataEndDateEdit->text();

    pump=ui->pumpCheckBox->isChecked();
    service=ui->serviseCheckBox->isChecked();


    notes=ui->noteEdit->toPlainText();


    query= QString( "update ClientsCard set surname = '%1', name_='%2', patronymic='%3', mobilPhone='%4', otherPhone='%12', \
                    id_district=%5, locality='%6', street='%7',dept='%8', id_instruments=%9, pump=%10, service='%11',").arg(surname).arg(name).\
                    arg(patronymic).arg(mobilPhone).arg(id_district).arg(locality).\
                    arg(street).arg(dept).arg(id_diameter).arg(pump).arg(service).arg(otherPhone);
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
    else  if((queryNew.value(0).toInt())&& !(ui->serviseCheckBox->isChecked()))
        deleteServiceClient(id_client);



}

void CardClientWindows::setStateSave(bool state)
{
    stateSave=state;
}

void CardClientWindows::setIdClient(int id)
{
    id_client=id;
}


void CardClientWindows::createServiceClient(int idClient)
{
    QString query= QString("INSERT INTO Service (idClient, idStateService,idStatePayment,\
                           idTypePump,idStatePump,idLocationPump,idSeasone)");

            query+= QString(" SELECT %1,%2,%3,%4,%5,%6,%7" ).arg(idClient).arg(0).arg(0).arg(0).arg(0).arg(0).arg(0);

    dataBase.queryToBase(query);
}

void CardClientWindows::deleteServiceClient(int idClient)
{
    QString query= QString("delete from  Service where idClient=%1 ").arg(idClient);
    dataBase.queryToBase(query);
}

void CardClientWindows::closeEvent(QCloseEvent *event)
{
    defaultContenWindow();
    emit closeSignal();
}



