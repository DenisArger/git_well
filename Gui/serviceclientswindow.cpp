#include "serviceclientswindow.h"
#include "ui_serviceclientswindow.h"

#include "global.h"


ServiceClientsWindow::ServiceClientsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServiceClientsWindow)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile(QStringLiteral("../icon/well.png"), QSize(), QIcon::Disabled, QIcon::Off);
    this->setWindowIcon(icon);

    cardServiceWindows=new CardServiceWindows(this);

    connect(ui->filterButton,SIGNAL(clicked(bool)),this,SLOT(clickFilter()));
    connect(ui->clearFilterButton,SIGNAL(clicked(bool)),this,SLOT(clickClear()));
    connect(ui->closeButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickTable(QModelIndex)));
    connect(ui->regionCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(fillDistrict()));

    connect(cardServiceWindows,SIGNAL(closeEvent(QCloseEvent*)),this,SLOT(updateModel()));

}


void ServiceClientsWindow::showWindow()
{
    this->showMaximized();

    dataBase.connectToDataBase();
    this->setupModel(QStringList()  << trUtf8("ID")
                     << trUtf8("ID client")
                     << trUtf8("Область")
                     << trUtf8("Район")
                     << trUtf8("Населенный пункт")
                     << trUtf8("Адрес")
                     << trUtf8("Статус предложения")
                     << trUtf8("Дата начала обслуживания")
                     << trUtf8("Статус оплаты")
                     << trUtf8("Тип насоса")
                     << trUtf8("Насос")
                     << trUtf8("Расположение насоса")
                     << trUtf8("Сезонность")
                     << trUtf8("Фамилия")
                     << trUtf8("Имя")
                     << trUtf8("Отчество")
                     << trUtf8("Телефон")
                     << trUtf8("Доп.телефон")
                     );

    /* Инициализируем внешний вид таблицы с данными */
    this->createUI();

    fillRegion();
    fillDistrict_FULL();
    fillStateService();
    fillStatePayment();
    fillTypePump();
    fillStatePump();
    fillLocationPump();
    fillSeasone();
}

ServiceClientsWindow::~ServiceClientsWindow()
{
    delete ui;
}


void ServiceClientsWindow::setupModel(const QStringList &headers)
{
    mainQuery=QString("SELECT Service.id, Service.idClient, Region.region, District.district,\
                          ClientsCard.locality, ClientsCard.street, StateService.stateSevice, Service.dataBegin, \
                          StatePayment.statePayment, TypePump.typePump, StatePump.statePump, LocationPump.locationPump,\
                          Seasone.season, ClientsCard.surname,ClientsCard.name_, ClientsCard.patronymic, ClientsCard.mobilPhone, ClientsCard.otherPhone\
                          FROM Seasone INNER JOIN (LocationPump INNER JOIN (StatePump INNER JOIN \
                                                                            (TypePump INNER JOIN (StateService INNER JOIN (StatePayment INNER JOIN (Service \
                                                                                                                                                    INNER JOIN ((ClientsCard INNER JOIN District ON ClientsCard.id_district = District.id)\
                                                                                                                                                                INNER JOIN Region ON District.id_region = Region.ID) ON Service.idClient = ClientsCard.ID)\
                                                                                                                           ON StatePayment.ID = Service.idStatePayment) ON StateService.ID = Service.idStateService)\
                                                                             ON TypePump.ID = Service.idTypePump) ON StatePump.ID = Service.idStatePump) \
                                                   ON LocationPump.ID = Service.idLocationPump) ON Seasone.ID = Service.idSeasone ORDER BY ClientsCard.ID DESC;");


            /* Производим инициализацию модели представления данных
                     * с установкой имени таблицы в базе данных, по которому
                     * будет производится обращение в таблице
                     * */
            model = new QSqlQueryModel(this);
    model->setQuery(mainQuery , dataBase.getDatase());

    qDebug()<<mainQuery;
    /* Устанавливаем названия колонок в таблице с сортировкой данных*/

    for(int i = 0, j = 0; i <model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);

    }
}


void ServiceClientsWindow::updateModel()
{
    model->setQuery(mainQuery , dataBase.getDatase());

}

void ServiceClientsWindow::createUI()
{
    ui->tableView->setModel(model);     // Устанавливаем модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    ui->tableView->setColumnHidden(1, true);    // Скрываем колонку с id клиента записей
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    model->setQuery(model->query().lastQuery());


}


personaleService ServiceClientsWindow::fillDataService(int idClient)
{


    QString query;
    personaleService pers;
    query=QString("SELECT ClientsCard.surname, ClientsCard.name_, ClientsCard.patronymic, \
                  ClientsCard.mobilPhone, Region.ID, District.id, ClientsCard.locality, ClientsCard.street,\
                  StateService.ID, Service.dataBegin, StatePayment.ID, TypePump.ID, StatePump.ID, LocationPump.ID, Seasone.ID, ClientsCard.otherPhone\
                  FROM Seasone INNER JOIN (LocationPump INNER JOIN (StatePump INNER JOIN (TypePump INNER JOIN\
                                                                                          (StateService INNER JOIN (StatePayment INNER JOIN (Service INNER JOIN ((ClientsCard INNER JOIN District \
                                                                                                                                                                  ON ClientsCard.id_district = District.id) INNER JOIN Region ON District.id_region = Region.ID) ON Service.idClient = ClientsCard.ID) \
                                                                                                                    ON StatePayment.ID = Service.idStatePayment) ON StateService.ID = Service.idStateService) ON TypePump.ID = Service.idTypePump)\
                                                                    ON StatePump.ID = Service.idStatePump) ON LocationPump.ID = Service.idLocationPump) ON Seasone.ID = Service.idSeasone\
            where Service.idClient=%1;").arg(idClient);

            QSqlQuery queryNew=dataBase.queryToBase(query);

    queryNew.first();

    pers.surname=queryNew.value(0).toString();
    pers.name=queryNew.value(1).toString();
    pers.patronymic=queryNew.value(2).toString();
    pers.phone=queryNew.value(3).toString();
    pers.otherPhone=queryNew.value(15).toString();
    pers.id_region=queryNew.value(4).toInt();
    pers.id_district=queryNew.value(5).toInt();
    pers.locality=queryNew.value(6).toString();
    pers.street=queryNew.value(7).toString();
    pers.id_stateService=queryNew.value(8).toInt();
    pers.dataBeginService=queryNew.value(9).toDateTime();
    pers.id_statePayment=queryNew.value(10).toInt();
    pers.id_typePump=queryNew.value(11).toInt();
    pers.id_statePump=queryNew.value(12).toInt();
    pers.id_locationPump=queryNew.value(13).toInt();
    pers.id_seasone=queryNew.value(14).toInt();
    //pers.note=queryNew.value(15).toString();

    return pers;

}


void ServiceClientsWindow::fillRegion()
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

void ServiceClientsWindow::fillDistrict()
{
    ui->districtCombo->clear();
    mapComboDistrict_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->districtCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->districtCombo->setEditable(true);

    int id_Region=ui->regionCombo->currentIndex();
    if(!id_Region){
        fillDistrict_FULL();
        return;
    }


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

void ServiceClientsWindow::fillDistrict_FULL()
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


void ServiceClientsWindow::fillStateService()
{
    ui->stateServiceCombo->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->stateServiceCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->stateServiceCombo->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT StateService.*FROM StateService;");
    while(query.next()) {
        ui->stateServiceCombo->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->stateServiceCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->stateServiceCombo->setCompleter(completer);
    ui->stateServiceCombo->setAutoCompletion(true);
}

void ServiceClientsWindow::fillStatePayment()
{
    ui->statePaymentCombo->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->statePaymentCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->statePaymentCombo->setEditable(true);
    QSqlQuery query=dataBase.queryToBase("SELECT StatePayment.* FROM StatePayment;");
    while(query.next()) {
        ui->statePaymentCombo->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->statePaymentCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->statePaymentCombo->setCompleter(completer);
    ui->statePaymentCombo->setAutoCompletion(true);
}

void ServiceClientsWindow::fillTypePump()
{
    ui->typePumpCombo->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->typePumpCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->typePumpCombo->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT TypePump.* FROM TypePump;");
    while(query.next()) {
        ui->typePumpCombo->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->typePumpCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->typePumpCombo->setCompleter(completer);
    ui->typePumpCombo->setAutoCompletion(true);
}

void ServiceClientsWindow::fillStatePump()
{
    ui->statePumpCombo->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->statePumpCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->statePumpCombo->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT StatePump.* FROM StatePump;");
    while(query.next()) {
        ui->statePumpCombo->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->statePumpCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->statePumpCombo->setCompleter(completer);
    ui->statePumpCombo->setAutoCompletion(true);
}

void ServiceClientsWindow::fillLocationPump()
{
    ui->locationePumpCombo->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->locationePumpCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->locationePumpCombo->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT LocationPump.* FROM LocationPump;");
    while(query.next()) {
        ui->locationePumpCombo->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->locationePumpCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->locationePumpCombo->setCompleter(completer);
    ui->locationePumpCombo->setAutoCompletion(true);
}

void ServiceClientsWindow::fillSeasone()
{
    ui->seasonaCombo->clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->seasonaCombo->setInsertPolicy(QComboBox::NoInsert);
    ui->seasonaCombo->setEditable(true);

    QSqlQuery query=dataBase.queryToBase("SELECT Seasone.* FROM Seasone;");
    while(query.next()) {
        ui->seasonaCombo->addItem(query.value(1).toString(), query.value(0));
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

    completer = new QCompleter(queryModel,ui->seasonaCombo );
    completer->setCaseSensitivity( Qt::CaseInsensitive );
    completer->setCompletionMode(QCompleter::PopupCompletion);

    ui->seasonaCombo->setCompleter(completer);
    ui->seasonaCombo->setAutoCompletion(true);
}


void ServiceClientsWindow::clickFilter()
{
    QString queryStr;


    queryStr=QString("SELECT Service.id, Service.idClient, Region.region, District.district,\
                     ClientsCard.locality, ClientsCard.street, StateService.stateSevice, Service.dataBegin, \
                     StatePayment.statePayment, TypePump.typePump, StatePump.statePump, LocationPump.locationPump,\
                     Seasone.season, ClientsCard.surname,ClientsCard.name_, ClientsCard.patronymic, ClientsCard.mobilPhone, ClientsCard.otherPhone \
                     FROM Seasone INNER JOIN (LocationPump INNER JOIN (StatePump INNER JOIN \
                                                                       (TypePump INNER JOIN (StateService INNER JOIN (StatePayment INNER JOIN (Service \
                                                                                                                                               INNER JOIN ((ClientsCard INNER JOIN District ON ClientsCard.id_district = District.id)\
                                                                                                                                                           INNER JOIN Region ON District.id_region = Region.ID) ON Service.idClient = ClientsCard.ID)\
                                                                                                                      ON StatePayment.ID = Service.idStatePayment) ON StateService.ID = Service.idStateService)\
                                                                        ON TypePump.ID = Service.idTypePump) ON StatePump.ID = Service.idStatePump) \
                                              ON LocationPump.ID = Service.idLocationPump) ON Seasone.ID = Service.idSeasone");


            queryStr += filterLocation();
            queryStr += filterPersonale();

    queryStr += filterStateService();
    queryStr += filterStatePayment();

    queryStr += filterTypeInstr();
    queryStr += filterStateInstr();

    queryStr += filterLocationInstr();
    queryStr += filterSeasone();
    queryStr += filterOtherPhone();

    /* queryTXT+=filterPump();

    queryTXT+=filterService();



    queryTXT+=";";*/
    qDebug()<<queryStr;

    mainQuery=queryStr;
    model->setQuery(mainQuery,dataBase.getDatase());
    model->setQuery(model->query().lastQuery());
    qDebug() << model->query().lastError().text();
}



QString ServiceClientsWindow::filterLocation()
{
    int id_region=mapComboGegion_.value(ui->regionCombo->currentIndex());
    int id_district=mapComboDistrict_.value(ui->districtCombo->currentIndex());
    QString locality= ui->localityLineEdit->text();
    QString street= ui->streetLineEdit->text();

    QString  textFilter;
    switch (parsingLocation()) {
    case 0:
        textFilter="";
        break;
    case 1:
        textFilter=QString(" WHERE ClientsCard.street LIKE '%%1%'").arg(street);
        break;
    case 2:
        textFilter=QString(" WHERE ClientsCard.locality LIKE '%%1%'").arg(locality);
        break;
    case 3:
        textFilter=QString( "WHERE ClientsCard.street LIKE '%%1%' AND \
                            ClientsCard.locality LIKE '%%2%' ").arg(street.arg(locality));
                            break;
            case 4:
                textFilter=QString(" WHERE ClientsCard.id_district = %1").arg(id_district);
        break;
    case 5:
        textFilter=QString(" WHERE ClientsCard.street LIKE '%%1%' AND \
                           ClientsCard.id_district LIKE '%2'").arg(street).arg(id_district);
                           break;
            case 6:
                textFilter=QString(" WHERE ClientsCard.locality LIKE '%%1%' AND \
                                   ClientsCard.id_district = %2").arg(locality).arg(id_district);
                break;
            case 7:
                textFilter=QString(" WHERE ClientsCard.street LIKE '%%1%' AND \
                                   ClientsCard.locality LIKE '%%2%' AND \
                                   ClientsCard.id_district = %3").arg(street).arg(locality).arg(id_district);
                break;
            case 8:
                textFilter=QString(" WHERE District.id_region = %1").arg(id_region);
        break;
    case 9:
        textFilter=QString( "WHERE ClientsCard.street LIKE '%%1%' AND \
                            District.id_region = %2").arg(street).arg(id_region);
                break;
            case 10:
                textFilter=QString(" WHERE ClientsCard.locality LIKE '%%1%' AND \
                                   District.id_region = %2").arg(locality).arg(id_region);
                break;
            case 11:
                textFilter=QString(" WHERE ClientsCard.street LIKE '%%1%' AND \
                                   ClientsCard.locality LIKE '%%2%' AND \
                                   District.id_region = %3").arg(street).arg(locality).arg(id_region);
                break;
            case 12:
                textFilter=QString(" WHERE  ClientsCard.id_district = %1 AND \
                                   District.id_region = %2").arg(id_district).arg(id_region);
                break;
            case 13:
                textFilter=QString(" WHERE ClientsCard.street LIKE '%%1%' AND \
                                   ClientsCard.id_district = %2 AND \
                District.id_region = %3").arg(street).arg(id_district).arg(id_region);
                break;
            case 14:
                textFilter=QString(" WHERE ClientsCard.locality LIKE '%%1%' AND \
                                   ClientsCard.id_district = %2 AND \
                District.id_region = %3").arg(locality).arg(id_district).arg(id_region);
                break;
            case 15:
                textFilter=QString(" WHERE ClientsCard.street LIKE '%%1%' AND \
                                   ClientsCard.locality LIKE '%%2%' AND \
                                   ClientsCard.id_district = %3 AND \
                District.id_region = %4").arg(street).arg(locality).arg(id_district).arg(id_region);
                break;
            default:
                textFilter="";
        break;
    }

    return textFilter;
}


int ServiceClientsWindow::parsingLocation()
{
    int parsing;
    int id_region=ui->regionCombo->currentIndex();
    int id_district=ui->districtCombo->currentIndex();
    QString locality= ui->localityLineEdit->text();
    QString street= ui->streetLineEdit->text();


    if(!id_region && !id_district && locality =="" && street == "" )
        parsing=0;
    else if(!id_region && !id_district && locality ==" " && street != "" )
        parsing=1;
    else if(!id_region && !id_district && locality !="" && street == "" )
        parsing=2;
    else if(!id_region && !id_district && locality !="" && street != "" )
        parsing=3;
    else if(!id_region && id_district && locality =="" && street == "" )
        parsing=4;
    else if(!id_region && id_district && locality =="" && street != "" )
        parsing=5;
    else if(!id_region && id_district && locality !="" && street == "" )
        parsing=6;
    else if(!id_region && id_district && locality !="" && street != "" )
        parsing=7;
    else if(id_region && !id_district && locality =="" && street == "" )
        parsing=8;
    else if(id_region && !id_district && locality =="" && street != "" )
        parsing=9;
    else if(id_region && !id_district && locality !="" && street == "" )
        parsing=10;
    else if(id_region && !id_district && locality !="" && street != "" )
        parsing=11;
    else if(id_region && id_district && locality =="" && street == "" )
        parsing=12;
    else if(id_region && id_district && locality =="" && street != "" )
        parsing=13;
    else if(id_region && id_district && locality !="" && street == "" )
        parsing=14;
    else if(id_region && id_district && locality !="" && street != "" )
        parsing=15;

    //qDebug()<<"parsing = " <<parsing;
    return parsing;
}

QString ServiceClientsWindow::filterStateService()
{
    QString queryStr;
    int idStateService;

    idStateService=ui->stateServiceCombo->currentIndex();
    if(!idStateService) {
        isStateService_=false;
        queryStr="";
        return queryStr;
    }

    isStateService_=true;

    if(parsingPersonale()||parsingLocation())
        queryStr=QString(" AND idStateService=%1").arg(idStateService);
    else
        queryStr=QString(" WHERE idStateService=%1").arg(idStateService);

    return queryStr;
}


QString ServiceClientsWindow::filterStatePayment()
{
    QString queryStr;
    int idStatePayment;

    idStatePayment=ui->statePaymentCombo->currentIndex();
    if(!idStatePayment) {
        isStatePayment_=false;
        queryStr="";
        return queryStr;
    }

    isStatePayment_=true;

    if(parsingPersonale()||parsingLocation()||isStateService_)
        queryStr=QString(" AND idStatePayment=%1").arg(idStatePayment);
    else
        queryStr=QString(" WHERE idStatePayment=%1").arg(idStatePayment);

    return queryStr;
}


QString ServiceClientsWindow::filterTypeInstr()
{
    QString queryStr;
    int idTypeInsrt;

    idTypeInsrt=ui->typePumpCombo->currentIndex();
    if(!idTypeInsrt) {
        isTypeInstr_=false;
        queryStr="";
        return queryStr;
    }

    isTypeInstr_=true;

    if(parsingPersonale()||parsingLocation()||isStateService_||isStatePayment_)
        queryStr=QString(" AND idTypePump=%1").arg(idTypeInsrt);
    else
        queryStr=QString(" WHERE idTypePump=%1").arg(idTypeInsrt);

    return queryStr;
}

QString ServiceClientsWindow::filterStateInstr()
{
    QString queryStr;
    int idStateInsrt;

    idStateInsrt=ui->statePumpCombo->currentIndex();
    if(!idStateInsrt) {
        isStateInstr_=false;
        queryStr="";
        return queryStr;
    }

    isStateInstr_=true;

    if(parsingPersonale()||parsingLocation()||isStateService_||isStatePayment_||isTypeInstr_)
        queryStr=QString(" AND idStatePump=%1").arg(idStateInsrt);
    else
        queryStr=QString(" WHERE idStatePump=%1").arg(idStateInsrt);

    return queryStr;
}

QString ServiceClientsWindow::filterLocationInstr()
{
    QString queryStr;
    int idLocationInsrt;

    idLocationInsrt=ui->locationePumpCombo->currentIndex();
    if(!idLocationInsrt) {
        isLocationInstr_=false;
        queryStr="";
        return queryStr;
    }

    isLocationInstr_=true;

    if(parsingPersonale()||parsingLocation()||isStateService_||isStatePayment_||isTypeInstr_||isStateInstr_)
        queryStr=QString(" AND idLocationPump=%1").arg(idLocationInsrt);
    else
        queryStr=QString(" WHERE idLocationPump=%1").arg(idLocationInsrt);

    return queryStr;
}

QString ServiceClientsWindow::filterSeasone()
{
    QString queryStr;
    int idSeasone;

    idSeasone=ui->seasonaCombo->currentIndex();
    if(!idSeasone) {
        isSeasone_=false;
        queryStr="";
        return queryStr;
    }

    isSeasone_=true;

    if(parsingPersonale()||parsingLocation()||isStateService_||isStatePayment_||isTypeInstr_||isStateInstr_||isLocationInstr_)
        queryStr=QString(" AND idSeasone=%1").arg(idSeasone);
    else
        queryStr=QString(" WHERE idSeasone=%1").arg(idSeasone);

    return queryStr;
}

int ServiceClientsWindow::parsingPersonale()
{
    int parsing;
    QString surname= ui->surnameLineEdit->text();
    QString name= ui->nameLineEdit->text();
    QString patronymic= ui->patronymicLineEdit->text();
    QString phone= ui->phoneLineEdit->text();


    if(surname =="" && name =="" && patronymic =="" && phone == "" )
        parsing=0;
    else if(surname =="" && name =="" && patronymic =="" && phone != "" )
        parsing=1;
    else if(surname =="" && name =="" && patronymic !="" && phone == "" )
        parsing=2;
    else if(surname =="" && name =="" && patronymic !="" && phone != "" )
        parsing=3;
    else if(surname =="" && name !="" && patronymic =="" && phone == "" )
        parsing=4;
    else if(surname =="" && name !="" && patronymic =="" && phone != "" )
        parsing=5;
    else if(surname =="" && name !="" && patronymic !="" && phone == "" )
        parsing=6;
    else if(surname =="" && name !="" && patronymic !="" && phone != "" )
        parsing=7;
    else if(surname !="" && name =="" && patronymic =="" && phone == "" )
        parsing=8;
    else if(surname !="" && name =="" && patronymic =="" && phone != "" )
        parsing=9;
    else if(surname !="" && name =="" && patronymic !="" && phone == "" )
        parsing=10;
    else if(surname !="" && name =="" && patronymic !="" && phone != "" )
        parsing=11;
    else if(surname !="" && name !="" && patronymic =="" && phone == "" )
        parsing=12;
    else if(surname !="" && name !="" && patronymic =="" && phone != "" )
        parsing=13;
    else if(surname !="" && name !="" && patronymic !="" && phone == "" )
        parsing=14;
    else if(surname !="" && name !="" && patronymic !="" && phone != "" )
        parsing=15;

    //qDebug()<<"parsing = " <<parsing;
    return parsing;
}

QString ServiceClientsWindow::filterPersonale()
{
    QString  textFilter;
    QString surname= ui->surnameLineEdit->text();
    QString name= ui->nameLineEdit->text();
    QString patronymic= ui->patronymicLineEdit->text();
    QString phone= ui->phoneLineEdit->text();

    int parsing=parsingPersonale();
    if(!parsing){
        textFilter="";
        return textFilter;
    }

    if(parsingLocation()){
        switch (parsing) {
        case 1:
            textFilter=QString(" AND ClientsCard.mobilPhone LIKE '%%1%'").arg(phone);
            break;
        case 2:
            textFilter=QString(" AND ClientsCard.patronymic LIKE '%%1%'").arg(patronymic);
            break;
        case 3:
            textFilter=QString(" AND ClientsCard.mobilPhone LIKE '%%1%' \
                               AND ClientsCard.patronymic LIKE '%%2%'").arg(phone).arg(patronymic);
                               break;
                case 4:
                    textFilter=QString(" AND ClientsCard.name_ LIKE '%%1%'").arg(name);
            break;
        case 5:
            textFilter=QString("    AND ClientsCard.mobilPhone LIKE '%%1%' \
                               AND ClientsCard.name_ LIKE '%%2%'").arg(phone).arg(name);
                               break;
                case 6:
                    textFilter=QString("    AND ClientsCard.patronymic LIKE '%%1%' \
                                       AND ClientsCard.name_ LIKE '%%2%'").arg(patronymic).arg(name);
                                       break;
                case 7:
                    textFilter=QString(" AND ClientsCard.mobilPhone LIKE '%%1%'   \
                                       AND ClientsCard.patronymic LIKE '%%2%' \
                                       AND ClientsCard.name_ LIKE '%%3%'").arg(phone).arg(patronymic).arg(name);
                                       break;
                case 8:
                    textFilter=QString(" AND ClientsCard.surname LIKE '%%1%'").arg(surname);
            break;
        case 9:
            textFilter=QString("    AND ClientsCard.mobilPhone LIKE '%%1%' \
                               AND ClientsCard.surname LIKE '%%2%'").arg(phone).arg(surname);
                               break;
                case 10:
                    textFilter=QString("    AND ClientsCard.patronymic LIKE '%%1%' \
                                       AND ClientsCard.surname LIKE '%%2%'").arg(patronymic).arg(surname);
                                       break;
                case 11:
                    textFilter=QString(" AND ClientsCard.mobilPhone LIKE '%%1%'   \
                                       AND ClientsCard.patronymic LIKE '%%2%' \
                                       AND ClientsCard.surname LIKE '%%3%'").arg(phone).arg(patronymic).arg(surname);
                                       break;
                case 12:
                    textFilter=QString("    AND ClientsCard.name LIKE '%%1%' \
                                       AND ClientsCard.surname LIKE '%%2%'").arg(name).arg(surname);
                                       break;
                case 13:
                    textFilter=QString(" AND ClientsCard.mobilPhone LIKE '%%1%'   \
                                       AND ClientsCard.name_ LIKE '%%2%' \
                                       AND ClientsCard.surname LIKE '%%3%'").arg(phone).arg(name).arg(surname);
                                       break;
                case 14:
                    textFilter=QString(" AND ClientsCard.patronymic LIKE '%%1%'   \
                                       AND ClientsCard.name_ LIKE '%%2%' \
                                       AND ClientsCard.surname LIKE '%%3%'").arg(patronymic).arg(name).arg(surname);
                                       break;
                case 15:
                    textFilter=QString(" AND ClientsCard.mobilPhone LIKE '%%1%'   \
                                       AND ClientsCard.patronymic LIKE '%%2%' \
                                       AND ClientsCard.name_ LIKE '%%3%' \
                                       AND ClientsCard.surname LIKE '%%4%'").arg(phone).arg(patronymic).arg(name).arg(surname);
                                       break;
                default:
                    break;
        }

    }
    else{
        switch (parsing) {
        case 1:
            textFilter=QString(" WHERE ClientsCard.mobilPhone LIKE '%%1%'").arg(phone);
            break;
        case 2:
            textFilter=QString(" WHERE ClientsCard.patronymic LIKE '%%1%'").arg(patronymic);
            break;
        case 3:
            textFilter=QString(" WHERE ClientsCard.mobilPhone LIKE '%%1%' \
                               AND ClientsCard.patronymic LIKE '%%2%'").arg(phone).arg(patronymic);
                               break;
                case 4:
                    textFilter=QString(" WHERE ClientsCard.name_ LIKE '%%1%'").arg(name);
            break;
        case 5:
            textFilter=QString("    WHERE ClientsCard.mobilPhone LIKE '%%1%' \
                               AND ClientsCard.name_ LIKE '%%2%'").arg(phone).arg(name);
                               break;
                case 6:
                    textFilter=QString("    WHERE ClientsCard.patronymic LIKE '%%1%' \
                                       AND ClientsCard.name_ LIKE '%%2%'").arg(patronymic).arg(name);
                                       break;
                case 7:
                    textFilter=QString(" WHERE ClientsCard.mobilPhone LIKE '%%1%'   \
                                       AND ClientsCard.patronymic LIKE '%%2%' \
                                       AND ClientsCard.name_ LIKE '%%3%'").arg(phone).arg(patronymic).arg(name);
                                       break;
                case 8:
                    textFilter=QString(" WHERE ClientsCard.surname LIKE '%%1%'").arg(surname);
            break;
        case 9:
            textFilter=QString("    WHERE ClientsCard.mobilPhone LIKE '%%1%' \
                               AND ClientsCard.surname LIKE '%%2%'").arg(phone).arg(surname);
                               break;
                case 10:
                    textFilter=QString("    WHERE ClientsCard.patronymic LIKE '%%1%' \
                                       AND ClientsCard.surname LIKE '%%2%'").arg(patronymic).arg(surname);
                                       break;
                case 11:
                    textFilter=QString(" WHERE ClientsCard.mobilPhone LIKE '%%1%'   \
                                       AND ClientsCard.patronymic LIKE '%%2%' \
                                       AND ClientsCard.surname LIKE '%%3%'").arg(phone).arg(patronymic).arg(surname);
                                       break;
                case 12:
                    textFilter=QString("    WHERE ClientsCard.name LIKE '%%1%' \
                                       AND ClientsCard.surname LIKE '%%2%'").arg(name).arg(surname);
                                       break;
                case 13:
                    textFilter=QString(" WHERE ClientsCard.mobilPhone LIKE '%%1%'   \
                                       AND ClientsCard.name_ LIKE '%%2%' \
                                       AND ClientsCard.surname LIKE '%%3%'").arg(phone).arg(name).arg(surname);
                                       break;
                case 14:
                    textFilter=QString(" WHERE ClientsCard.patronymic LIKE '%%1%'   \
                                       AND ClientsCard.name_ LIKE '%%2%' \
                                       AND ClientsCard.surname LIKE '%%3%'").arg(patronymic).arg(name).arg(surname);
                                       break;
                case 15:
                    textFilter=QString(" WHERE ClientsCard.mobilPhone LIKE '%%1%'   \
                                       AND ClientsCard.patronymic LIKE '%%2%' \
                                       AND ClientsCard.name_ LIKE '%%3%' \
                                       AND ClientsCard.surname LIKE '%%4%'").arg(phone).arg(patronymic).arg(name).arg(surname);
                                       break;
                default:
                    break;
        }
    }
}



QString ServiceClientsWindow::filterOtherPhone()
{
    QString  textFilter;
    QString otherPhone=ui->otherPhoneLineEdit->text();
    if(otherPhone==""){
        textFilter="";
        return textFilter;
    }

    if(parsingPersonale()||parsingLocation()||isStateService_||isStatePayment_||isTypeInstr_||isStateInstr_||isLocationInstr_||isSeasone_)
        textFilter=QString(" AND ClientsCard.otherPhone LIKE '%%1%'").arg(otherPhone);
    else
        textFilter=QString(" WHERE ClientsCard.otherPhone LIKE '%%1%'").arg(otherPhone);

    return textFilter;

}




void ServiceClientsWindow::clickClear()
{
    QString query=QString("SELECT Service.id, Service.idClient, Region.region, District.district,\
                          ClientsCard.locality, ClientsCard.street, StateService.stateSevice, Service.dataBegin, \
                          StatePayment.statePayment, TypePump.typePump, StatePump.statePump, LocationPump.locationPump,\
                          Seasone.season, ClientsCard.surname,ClientsCard.name_, ClientsCard.patronymic, ClientsCard.mobilPhone, ClientsCard.otherPhone\
                          FROM Seasone INNER JOIN (LocationPump INNER JOIN (StatePump INNER JOIN \
                                                                            (TypePump INNER JOIN (StateService INNER JOIN (StatePayment INNER JOIN (Service \
                                                                                                                                                    INNER JOIN ((ClientsCard INNER JOIN District ON ClientsCard.id_district = District.id)\
                                                                                                                                                                INNER JOIN Region ON District.id_region = Region.ID) ON Service.idClient = ClientsCard.ID)\
                                                                                                                           ON StatePayment.ID = Service.idStatePayment) ON StateService.ID = Service.idStateService)\
                                                                             ON TypePump.ID = Service.idTypePump) ON StatePump.ID = Service.idStatePump) \
                                                   ON LocationPump.ID = Service.idLocationPump) ON Seasone.ID = Service.idSeasone;");



            model->setQuery(query , dataBase.getDatase());

    model->setQuery(model->query().lastQuery());
    qDebug() << model->query().lastError().text();

    //ui->localityLineEdit->clear();

    ui->regionCombo->setCurrentIndex(0);
    ui->districtCombo->setCurrentIndex(0);
    ui->localityLineEdit->clear();
    ui->streetLineEdit->clear();

    ui->surnameLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->patronymicLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->otherPhoneLineEdit->clear();

    ui->stateServiceCombo->setCurrentIndex(0);
    ui->statePaymentCombo->setCurrentIndex(0);
    ui->typePumpCombo->setCurrentIndex(0);
    ui->statePumpCombo->setCurrentIndex(0);
    ui->locationePumpCombo->setCurrentIndex(0);
    ui->seasonaCombo->setCurrentIndex(0);

    mainQuery=query;

}

void ServiceClientsWindow::doubleClickTable(const QModelIndex &index)
{
    cardServiceWindows->showWindow();


    //Получаем индекс нужного ИД
    QModelIndex index1= index.sibling(index.row(),0);
    QModelIndex index_= index.sibling(index.row(),1);
    personaleService res;
    int idClient=index_.model()->data(index_, Qt::DisplayRole).toInt();
    int idServicet=index1.model()->data(index1, Qt::DisplayRole).toInt();
    res=fillDataService(idClient);
    cardServiceWindows->setIdService(idServicet);
    cardServiceWindows->setIdClient(idClient);
    cardServiceWindows->fillServiceCart(res);
}
