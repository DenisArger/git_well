#include "cardservicewindows.h"
#include "ui_cardservicewindows.h"

CardServiceWindows::CardServiceWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CardServiceWindows)
{

    ui->setupUi(this);


    connect(ui->regionCombo_2, SIGNAL(currentIndexChanged(int)), this, SLOT(fillDistrict()));
    connect(ui->closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(clickSaveButton()));
    connect(ui->typePumpCombo_2, SIGNAL(currentIndexChanged(int)), this, SLOT(changedCurrtentUndex(int)));

}

void CardServiceWindows::showWindow()
{
    this->show();

    fillStateService();
    fillStatePayment();
    fillTypePump();
    fillStatePump();
    fillLocationPump();
    fillSeasone();
    fillDistrict_FULL();
    fillRegion();
}



CardServiceWindows::~CardServiceWindows()
{
    delete ui;
}

void CardServiceWindows::setIdClient(int ID)

{
    id_client=ID;
}

void CardServiceWindows::setIdService(int ID)
{
    id_service=ID;
}

void CardServiceWindows::fillServiceCart(personaleService pers)
{
    if(pers.dataBeginService.toString()!="")
        ui->dataBeginServiceEdit_2->setEnabled(true);
    /*if(pers.dataNextService.toString()!="")
        ui->dataNextServiceEdit->setEnabled(true);*/

    ui->surnameLineEdit_2->setText(pers.surname);
    ui->nameLineEdit_2->setText(pers.name);
    ui->patronymicLineEdit_2->setText(pers.patronymic);
    ui->mobilPhoneLineEdit_2->setText(pers.phone);
    ui->otherPhoneLineEdit->setText(pers.otherPhone);
    ui->regionCombo_2->setCurrentIndex(mapComboGegion_.key(pers.id_region));
    ui->districtCombo_2->setCurrentIndex(mapComboDistrict_.key(pers.id_district));
    ui->localityLineEdit_2->setText(pers.locality);
    ui->streetLineEdit_2->setText(pers.street);
    ui->stateServiceCombo_2->setCurrentIndex(pers.id_stateService);
    ui->statePaymentCombo_2->setCurrentIndex(pers.id_statePayment);
    ui->dataBeginServiceEdit_2->setDateTime(pers.dataBeginService);
    ui->typePumpCombo_2->setCurrentIndex(pers.id_typePump);
    ui->statePumpCombo_2->setCurrentIndex(pers.id_statePump);
    ui->locationePumpCombo_2->setCurrentIndex(pers.id_locationPump);
    ui->seasonaCombo_2->setCurrentIndex(pers.id_seasone);
    //ui->dataNextServiceEdit->setDateTime(pers.dataNextService);
    ui->noteEdit_2->setText(pers.note);
}


void CardServiceWindows::fillStateService()
{
    ui->stateServiceCombo_2->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->stateServiceCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->stateServiceCombo_2->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT StateService.*FROM StateService;");
    while(query.next()) {
        ui->stateServiceCombo_2->addItem(query.value(1).toString(), query.value(0));
    }


    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT StateService.stateSevice\
                     FROM StateService;");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->stateServiceCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->stateServiceCombo_2->setCompleter(completer);
    ui->stateServiceCombo_2->setAutoCompletion(true);
}

void CardServiceWindows::fillStatePayment()
{
    ui->statePaymentCombo_2->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->statePaymentCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->statePaymentCombo_2->setEditable(true);
    QSqlQuery query=dataBase.queryToBase("SELECT StatePayment.* FROM StatePayment;");
    while(query.next()) {
        ui->statePaymentCombo_2->addItem(query.value(1).toString(), query.value(0));
    }


    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT StatePayment.statePayment\
                     FROM StatePayment;");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->statePaymentCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->statePaymentCombo_2->setCompleter(completer);
    ui->statePaymentCombo_2->setAutoCompletion(true);
}


void CardServiceWindows::fillTypePump()
{
    ui->typePumpCombo_2->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->typePumpCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->typePumpCombo_2->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT TypePump.* FROM TypePump;");
    while(query.next()) {
        ui->typePumpCombo_2->addItem(query.value(1).toString(), query.value(0));
    }


    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT TypePump.typePump\
                     FROM TypePump;");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->typePumpCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->typePumpCombo_2->setCompleter(completer);
    ui->typePumpCombo_2->setAutoCompletion(true);
}


void CardServiceWindows::fillStatePump()
{
    ui->statePumpCombo_2->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->statePumpCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->statePumpCombo_2->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT StatePump.* FROM StatePump;");
    while(query.next()) {
        ui->statePumpCombo_2->addItem(query.value(1).toString(), query.value(0));
    }

    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT StatePump.statePump\
                     FROM StatePump;");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->statePumpCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->statePumpCombo_2->setCompleter(completer);
    ui->statePumpCombo_2->setAutoCompletion(true);
}


void CardServiceWindows::fillLocationPump()
{
    ui->locationePumpCombo_2->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->locationePumpCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->locationePumpCombo_2->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT LocationPump.* FROM LocationPump;");
    while(query.next()) {
        ui->locationePumpCombo_2->addItem(query.value(1).toString(), query.value(0));
    }

    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT LocationPump.locationPump\
                     FROM LocationPump;");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->locationePumpCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->locationePumpCombo_2->setCompleter(completer);
    ui->locationePumpCombo_2->setAutoCompletion(true);
}

void CardServiceWindows::fillSeasone()
{
    ui->seasonaCombo_2->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->seasonaCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->seasonaCombo_2->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT Seasone.* FROM Seasone;");
    while(query.next()) {
        ui->seasonaCombo_2->addItem(query.value(1).toString(), query.value(0));
    }

    //Реализуем возможность автозаполнения comboBox
    QString queryStr;
    QSqlQueryModel *queryModel;
    QCompleter* completer;

    queryStr=QString("SELECT Seasone.season\
                     FROM Seasone;");

    //Производим инициализацию модели представления данных
    queryModel = new QSqlQueryModel(this);
    queryModel->setQuery( queryStr, dataBase.getDatase());

    completer = new QCompleter(queryModel,ui->seasonaCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->seasonaCombo_2->setCompleter(completer);
    ui->seasonaCombo_2->setAutoCompletion(true);
}


void CardServiceWindows::fillRegion()
{
    ui->regionCombo_2->clear();
    mapComboGegion_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->regionCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->regionCombo_2->setEditable(true);
    QSqlQuery query=dataBase.getQueryRegion();
    int i=0;
    while(query.next()) {
         //заполнение словаря
        mapComboGegion_.insert(i,query.value(0).toInt());
        ui->regionCombo_2->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->regionCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->regionCombo_2->setCompleter(completer);
    ui->regionCombo_2->setAutoCompletion(true);
}

void CardServiceWindows::fillDistrict()
{
    ui->districtCombo_2->clear();
    mapComboDistrict_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->districtCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->districtCombo_2->setEditable(true);

    int id_Region=ui->regionCombo_2->currentIndex();
    QSqlQuery query=dataBase.getQueryDistrict(id_Region);
    int i=0;
    while (query.next()) {
         //заполнение словаря
        mapComboDistrict_.insert(i,query.value(0).toInt());
        ui->districtCombo_2->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->districtCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->districtCombo_2->setCompleter(completer);
    ui->districtCombo_2->setAutoCompletion(true);
}

void CardServiceWindows::clickSaveButton()
{
    updateServiceCard();
    close();
}

void CardServiceWindows::changedCurrtentUndex(int index)
{
    createNextDataService(index);
}

void CardServiceWindows::fillDistrict_FULL()
{
    ui->districtCombo_2->clear();
    mapComboDistrict_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->districtCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->districtCombo_2->setEditable(true);
    QSqlQuery query=dataBase.getQueryDistrict_FULL();
    int i=0;
    while (query.next()) {
        //заполнение словаря
        mapComboDistrict_.insert(i,query.value(0).toInt());
        ui->districtCombo_2->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->districtCombo_2 );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->districtCombo_2->setCompleter(completer);
    ui->districtCombo_2->setAutoCompletion(true);
}



void CardServiceWindows::updateServiceCard()
{
    personaleService pers;

    dataService=ui->dataBeginServiceEdit_2->dateTime();

    pers.dataBeginServiceStr=ui->dataBeginServiceEdit_2->text();
    pers.id_stateService=ui->stateServiceCombo_2->currentIndex();
    pers.id_statePayment=ui->statePaymentCombo_2->currentIndex();
    pers.id_statePump=ui->statePumpCombo_2->currentIndex();
    pers.id_typePump=ui->typePumpCombo_2->currentIndex();
    pers.id_seasone=ui->seasonaCombo_2->currentIndex();
    pers.id_locationPump=ui->locationePumpCombo_2->currentIndex();


    pers.note=ui->noteEdit_2->toPlainText();


    QString query= QString( "update Service set idStateService = %1, idStatePayment=%2, dataBegin='%3', idTypePump=%4, \
                   idStatePump=%5, idLocationPump=%6, idSeasone=%7,notes='%8'").arg( pers.id_stateService).arg(  pers.id_statePayment).\
                    arg( pers.dataBeginServiceStr).arg(pers.id_typePump).arg( pers.id_statePump).arg(pers.id_locationPump).\
                    arg(pers.id_seasone).arg(pers.note);

    query+=QString(" where idClient=%1 ").arg(id_client);

    dataBase.queryToBase(query);

}

void CardServiceWindows::createNextDataService(int index)
{
    dataService=ui->dataBeginServiceEdit_2->dateTime();
    qDebug()<< dataService.toString("dd.MM.yyyy");

    QString queryStr=QString("delete from  NextService where idService=%1 ").arg(id_service);
    QSqlQuery query=dataBase.queryToBase(queryStr);

    queryStr="";
    if(index==1){
        QString dateNextStr=dataService.addMonths(6).toString("dd.MM.yyyy").replace(".","/");
        queryStr=QString("Insert Into NextService(idService,idInstrumentsService,dataNextSevice)\
        select %1,%2,#%3# ").arg(id_service).arg(0).arg(dateNextStr);
    dataBase.queryToBase(queryStr);
    }

    if(index==2){
       QString dateNextStr=dataService.addMonths(6).toString("dd.MM.yyyy").replace(".","/");
        queryStr=QString("Insert Into NextService(idService,idInstrumentsService,dataNextSevice)\
        select %1,%2,#%3# ").arg(id_service).arg(1).arg(dateNextStr) ;
        dataBase.queryToBase(queryStr);
        dateNextStr=dataService.addMonths(12).toString("dd.MM.yyyy").replace(".","/");
        queryStr=QString("Insert Into NextService(idService,idInstrumentsService,dataNextSevice)\
        select %1,%2,#%3# ").arg(id_service).arg(2).arg(dateNextStr) ;
        dataBase.queryToBase(queryStr);

                         }


    this->setupModel(QStringList() << trUtf8("ID")
                             << trUtf8("Оборудование")
                             << trUtf8("Дата следующего обслуживнаия")

              );

    this->createUI();

}


void CardServiceWindows::setupModel(const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    model = new ServiceCardQueryModel(this);
    model->setQuery( QString("SELECT NextService.ID, InstrumentsService.instrumentsService, NextService.dataNextSevice\
                             FROM InstrumentsService INNER JOIN NextService \
                ON InstrumentsService.ID = NextService.idInstrumentsService where idService=%1;").arg(id_service),dataBase.getDatase());

    /* Устанавливаем названия колонок в таблице с сортировкой данных*/

   for(int i = 0, j = 0; i <model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);

    }
}

void CardServiceWindows::createUI()
{
    ui->tableView_2->setModel(model);     // Устанавливаем модель на TableView


    //ui->tableView->horizontalHeader()->hide();
    //ui->tableView->verticalHeader()->hide();

    ui->tableView_2->horizontalHeader()->setVisible(false);// Скрываем количество строк
    ui->tableView_2->verticalHeader()->setVisible(false);// заголовки таблицы

    ui->tableView_2->setColumnHidden(0, true);    // Скрываем колонку с id записей
    //ui->tableView->setColumnHidden(1, true);    // Скрываем колонку с флагом обслуживания
    // Разрешаем выделение строк
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения нескольких строк в таблице
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView_2->resizeColumnsToContents();
    ui->tableView_2->setItemDelegate(new QSqlRelationalDelegate(ui->tableView_2));
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);


     model->setQuery(model->query().lastQuery());


}
