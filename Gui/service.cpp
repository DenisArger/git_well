#include "service.h"
#include "ui_service.h"
#include "global.h"
#include "servicecard.h"

service::service(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::service)
{
    ui->setupUi(this);

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
               );

    /* Инициализируем внешний вид таблицы с данными
     * */
    this->createUI();

    fillRegion();
    fillDistrict();
    fillDistrict_FULL();
    fillStateService();
    fillStatePayment();
    fillTypePump();
    fillStatePump();
    fillLocationPump();
    fillSeasone();


    connect(ui->filterButton,SIGNAL(clicked(bool)),this,SLOT(clickFilter()));
    connect(ui->clearFilterButton,SIGNAL(clicked(bool)),this,SLOT(clickClear()));

    /*this->setMinimumSize(gWidth,gHeight);
    this->setMaximumSize(gWidth,gHeight);
    this->resize(gWidth * PERCENT_OF_SCREEN_WIDTH, gHeight * PERCENT_OF_SCREEN_HEIGHT);*/

}

service::~service()
{
    delete ui;
}


void service::setupModel(const QStringList &headers)
{
   QString query=QString("SELECT Service.id, Service.idClient, Region.region, District.district,\
          ClientsCard.locality, ClientsCard.street, StateService.stateSevice, Service.dataBegin, \
          StatePayment.statePayment, TypePump.typePump, StatePump.statePump, LocationPump.locationPump,\
                 Seasone.season, ClientsCard.surname,ClientsCard.name_, ClientsCard.patronymic, ClientsCard.mobilPhone\
                             FROM Seasone INNER JOIN (LocationPump INNER JOIN (StatePump INNER JOIN \
              (TypePump INNER JOIN (StateService INNER JOIN (StatePayment INNER JOIN (Service \
            INNER JOIN ((ClientsCard INNER JOIN District ON ClientsCard.id_district = District.id)\
              INNER JOIN Region ON District.id_region = Region.ID) ON Service.idClient = ClientsCard.ID)\
            ON StatePayment.ID = Service.idStatePayment) ON StateService.ID = Service.idStateService)\
          ON TypePump.ID = Service.idTypePump) ON StatePump.ID = Service.idStatePump) \
            ON LocationPump.ID = Service.idLocationPump) ON Seasone.ID = Service.idSeasone;");


    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    model = new QSqlQueryModel(this);
    model->setQuery(query , dataBase.getDatase());

    qDebug()<<query;
    /* Устанавливаем названия колонок в таблице с сортировкой данных*/

   for(int i = 0, j = 0; i <model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);

    }
}

void service::createUI()
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

void service::on_pushButton_clicked()
{
    close();
}

void service::on_tableView_doubleClicked(const QModelIndex &index)
{
   /* servicecard  *w=new servicecard(this);

    w->show();


    //Получаем индекс нужного ИД
    QModelIndex index1= index.sibling(index.row(),0);
    QModelIndex index_= index.sibling(index.row(),1);
    personaleService res;
    int idClient=index_.model()->data(index_, Qt::DisplayRole).toInt();
    int idServicet=index1.model()->data(index1, Qt::DisplayRole).toInt();
    res=fillDataService(idClient);
    w->setIdService(idServicet);
    w->setIdClient(idClient);
    w->fillServiceCart(res);

    model->setQuery(model->query().lastQuery());*/
}


/*personaleService service::fillDataService(int idClient)
{


    QString query;
    personaleService pers;
    query=QString("SELECT ClientsCard.surname, ClientsCard.name_, ClientsCard.patronymic, \
            ClientsCard.mobilPhone, Region.ID, District.id, ClientsCard.locality, ClientsCard.street,\
            StateService.ID, Service.dataBegin, StatePayment.ID, TypePump.ID, StatePump.ID, LocationPump.ID, Seasone.ID\
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

*/
void service::fillRegion()
{
    ui->regionCombo->clear();
    QSqlQuery query=dataBase.getQueryRegion();
    while(query.next()) {
        ui->regionCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void service::fillDistrict()
{
    ui->districtCombo->clear();
    int id_Region=ui->regionCombo->currentIndex();
    QSqlQuery query=dataBase.getQueryDistrict(id_Region);
    while (query.next()) {
        ui->districtCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void service::fillDistrict_FULL()
{
    ui->districtCombo->clear();
    QSqlQuery query=dataBase.getQueryDistrict_FULL();
    while (query.next()) {
        ui->districtCombo->addItem(query.value(1).toString(), query.value(0));
    }
}


void service::fillStateService()
{
    ui->stateServiceCombo->clear();
    QSqlQuery query=dataBase.queryToBase("SELECT StateService.*FROM StateService;");
    while(query.next()) {
        ui->stateServiceCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void service::fillStatePayment()
{
    ui->statePaymentCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT StatePayment.* FROM StatePayment;");
    while(query.next()) {
        ui->statePaymentCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void service::fillTypePump()
{
    ui->typePumpCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT TypePump.* FROM TypePump;");
    while(query.next()) {
        ui->typePumpCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void service::fillStatePump()
{
    ui->statePumpCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT StatePump.* FROM StatePump;");
    while(query.next()) {
        ui->statePumpCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void service::fillLocationPump()
{
    ui->locationePumpCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT LocationPump.* FROM LocationPump;");
    while(query.next()) {
        ui->locationePumpCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void service::fillSeasone()
{
    ui->seasonaCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT Seasone.* FROM Seasone;");
    while(query.next()) {
        ui->seasonaCombo->addItem(query.value(1).toString(), query.value(0));
    }
}


void service::clickFilter()
{
    QString queryStr;


     queryStr=QString("SELECT Service.id, Service.idClient, Region.region, District.district,\
                                     ClientsCard.locality, ClientsCard.street, StateService.stateSevice, Service.dataBegin, \
                                     StatePayment.statePayment, TypePump.typePump, StatePump.statePump, LocationPump.locationPump,\
                                            Seasone.season, ClientsCard.surname,ClientsCard.name_, ClientsCard.patronymic, ClientsCard.mobilPhone\
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

   /* queryTXT+=filterPump();

    queryTXT+=filterService();



    queryTXT+=";";*/
    qDebug()<<queryStr;

    model->setQuery(queryStr,dataBase.getDatase());
    model->setQuery(model->query().lastQuery());
    qDebug() << model->query().lastError().text();
}



QString service::filterLocation()
{
    int id_region=ui->regionCombo->currentIndex();
    int id_district=ui->districtCombo->currentIndex();
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


int service::parsingLocation()
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

QString service::filterStateService()
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


QString service::filterStatePayment()
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


QString service::filterTypeInstr()
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

QString service::filterStateInstr()
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

QString service::filterLocationInstr()
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

QString service::filterSeasone()
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

int service::parsingPersonale()
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

QString service::filterPersonale()
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



void service::clickClear()
{
    QString query=QString("SELECT Service.id, Service.idClient, Region.region, District.district,\
           ClientsCard.locality, ClientsCard.street, StateService.stateSevice, Service.dataBegin, \
           StatePayment.statePayment, TypePump.typePump, StatePump.statePump, LocationPump.locationPump,\
                  Seasone.season, ClientsCard.surname,ClientsCard.name_, ClientsCard.patronymic, ClientsCard.mobilPhone\
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

     ui->stateServiceCombo->setCurrentIndex(0);
     ui->statePaymentCombo->setCurrentIndex(0);
     ui->typePumpCombo->setCurrentIndex(0);
     ui->statePumpCombo->setCurrentIndex(0);
     ui->locationePumpCombo->setCurrentIndex(0);
     ui->seasonaCombo->setCurrentIndex(0);



}
