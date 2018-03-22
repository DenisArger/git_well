#include "clientswindows.h"
#include "ui_clientswindows.h"

ClientsWindows::ClientsWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientsWindows)
{
    ui->setupUi(this);
    cardClientWindows=new CardClientWindows(this);

    connect(ui->regionCombo_2, SIGNAL(currentIndexChanged(int)), this, SLOT(fillDistrict()));
    connect(ui->closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->filterButton, SIGNAL(clicked(bool)), this, SLOT(clickFilterButton()));
    connect(ui->clearFilterButton, SIGNAL(clicked(bool)), this, SLOT(clickClearFilterButton()));
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(clickDoubleClickedTable(QModelIndex)));
    connect(cardClientWindows,SIGNAL(closeSignal()),this,SLOT(updateModel()));

}

void ClientsWindows::showWindow()
{
    this->showMaximized();

    dataBase.connectToDataBase();
    this->setupModel(QStringList() << trUtf8("ID")
                     << trUtf8("Service")
                     << trUtf8("Область")
                     << trUtf8("Район")
                     << trUtf8("Населенный пункт")
                     << trUtf8("Адрес")
                     << trUtf8("Диаметр")
                     << trUtf8("Телефон")
                     << trUtf8("Доп.телефоны")
                     << trUtf8("Фамилия")
                     << trUtf8("Имя")
                     << trUtf8("Отчество")
                     );

    /*Инициализируем внешний вид таблицы с данными **/
    this->createUI();

    fillRegion();
    fillDistrict_FULL();
    fillDiameter();

}


ClientsWindows::~ClientsWindows()
{
    delete ui;
}


void ClientsWindows::setupModel(const QStringList &headers)
{
    mainQuery=QString("SELECT ClientsCard.ID,ClientsCard.service,Region.region, District.district, ClientsCard.locality, \
ClientsCard.street, Instruments.nameInstruments,ClientsCard.mobilPhone, ClientsCard.otherPhone, ClientsCard.surname, \
ClientsCard.name_, ClientsCard.patronymic FROM ((ClientsCard INNER JOIN Instruments ON ClientsCard.id_instruments = Instruments.id)\
 INNER JOIN District ON ClientsCard.id_district = District.id) INNER JOIN Region ON District.id_region = Region.id ORDER BY ClientsCard.ID DESC;");

    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    model = new HeirQSqlQueryModel(this);
    model->setQuery( mainQuery, dataBase.getDatase());

    /* Устанавливаем названия колонок в таблице с сортировкой данных*/

    for(int i = 0, j = 0; i <model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);

    }
}



void ClientsWindows::updateModel()
{
    model->setQuery( mainQuery, dataBase.getDatase());

}

void ClientsWindows::createUI()
{
    ui->tableView->setModel(model);     // Устанавливаем модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    ui->tableView->setColumnHidden(1, true);    // Скрываем колонку с флагом обслуживания
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения нескольких строк в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    /* QModelIndex index;
    index.sibling(2,2);
    QColor color(12,122,11);

    ui->tableView->model()->setData(index,color,Qt::BackgroundRole);*/


    model->setQuery(model->query().lastQuery());


}

void ClientsWindows::fillRegion()
{
    ui->regionCombo_2->clear();
     mapComboGegion_.clear();
    //Строка не будет вставлена ​​в поле со списком
    ui->regionCombo_2->setInsertPolicy(QComboBox::NoInsert);
    ui->regionCombo_2->setEditable(true);
    QSqlQuery query=dataBase.getQueryRegion();
    int i=0;
    while(query.next()) {
        mapComboGegion_.insert(i,query.value(0).toInt());
        ui->regionCombo_2->addItem(query.value(1).toString(), query.value(0));
        i++;    }

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

void ClientsWindows::fillDistrict()
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

void ClientsWindows::clickFilterButton()
{
    QString queryTXT= QString("SELECT ClientsCard.ID,ClientsCard.service,Region.region, District.district, ClientsCard.locality, ClientsCard.street, Instruments.nameInstruments,\
                              ClientsCard.mobilPhone, ClientsCard.otherPhone, ClientsCard.surname, ClientsCard.name_, ClientsCard.patronymic\
                              FROM ((ClientsCard INNER JOIN Instruments ON ClientsCard.id_instruments = Instruments.id)\
                                    INNER JOIN District ON ClientsCard.id_district = District.id) INNER JOIN Region ON District.id_region = Region.id");




    queryTXT+=filterLocation();

    if(ui->diameterCombo->currentIndex()){
    queryTXT+=filterDiameter();
    }

    queryTXT+=filterPump();

    queryTXT+=filterService();

    queryTXT+=filterPersonale();

    queryTXT+=filterOtherPhone();

    queryTXT+=";";
    qDebug()<<queryTXT;

    mainQuery=queryTXT;
    model->setQuery(mainQuery,dataBase.getDatase());
    model->setQuery(model->query().lastQuery());
    qDebug() << model->query().lastError().text();

}

void ClientsWindows::clickClearFilterButton()
{
    QString queryStr;
    queryStr=QString("SELECT ClientsCard.ID,ClientsCard.service,Region.region, District.district, ClientsCard.locality, ClientsCard.street, Instruments.nameInstruments,\
                     ClientsCard.mobilPhone, ClientsCard.otherPhone, ClientsCard.surname, ClientsCard.name_, ClientsCard.patronymic FROM ((ClientsCard INNER JOIN Instruments \
                     ON ClientsCard.id_Instruments = Instruments.id) INNER JOIN District ON ClientsCard.id_district = District.id) INNER JOIN Region ON District.id_region = Region.id;");
    model->setQuery(queryStr,dataBase.getDatase());


    model->setQuery(model->query().lastQuery());
    qDebug() << model->query().lastError().text();

    ui->localityLineEdit_2->clear();


    ui->regionCombo_2->setCurrentIndex(0);
    ui->districtCombo_2->setCurrentIndex(0);
    ui->localityLineEdit_2->clear();
    ui->streetLineEdit_3->clear();

    ui->diameterCombo->setCurrentIndex(0);
    ui->pumpCheckBox->setChecked(false);
    ui->serviseCheckBox->setChecked(false);

    ui->surnameLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->patronymicLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->otherLineEdit->clear();

    mainQuery=queryStr;
}

void ClientsWindows::clickDoubleClickedTable(QModelIndex index)
{

    cardClientWindows->setStateSave(false);
    cardClientWindows->showWindow();

    //Получаем индекс нужного ИД
    QModelIndex index_= index.sibling(index.row(),0);
    personale res;
    int idClient=index_.model()->data(index_, Qt::DisplayRole).toInt();
    res=fillDataClient(idClient);
    cardClientWindows->setIdClient(idClient);
    cardClientWindows->fillClientCart(res);



}

void ClientsWindows::fillDistrict_FULL()
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


QString ClientsWindows::filterLocation()
{
    int id_region=mapComboGegion_.value(ui->regionCombo_2->currentIndex());
    int id_district=mapComboDistrict_.value(ui->districtCombo_2->currentIndex());
    QString locality= ui->localityLineEdit_2->text();
    QString street= ui->streetLineEdit_3->text();

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


QString ClientsWindows::filterDiameter()
{
    int id_diameter=mapComboInstrument_.value(ui->diameterCombo->currentIndex());
    QString  textFilter;
    if(parsingLocation())
        textFilter=QString(" AND ClientsCard.id_instruments=%1").arg(id_diameter);
    else
        textFilter=QString(" WHERE ClientsCard.id_instruments=%1").arg(id_diameter);

    return textFilter;

}

QString ClientsWindows::filterPump()
{
    QString  textFilter;
    bool pump=ui->pumpCheckBox->isChecked();
    if(!pump){
        textFilter="";
        return textFilter;
    }

    if(parsingLocation()||ui->diameterCombo->currentIndex())
        textFilter=QString(" AND ClientsCard.pump=%1").arg(pump);
    else
        textFilter=QString(" WHERE ClientsCard.pump=%1").arg(pump);

    return textFilter;

}

QString ClientsWindows::filterService()
{
    QString  textFilter;
    bool service=ui->serviseCheckBox->isChecked();
    if(!service){
        textFilter="";
        return textFilter;
    }

    if(parsingLocation()||ui->diameterCombo->currentIndex()||ui->pumpCheckBox->isChecked())
        textFilter=QString(" AND ClientsCard.service=%1").arg(service);
    else
        textFilter=QString(" WHERE ClientsCard.service=%1").arg(service);

    return textFilter;

}


QString ClientsWindows::filterOtherPhone()
{
    QString  textFilter;
    QString otherPhone=ui->otherLineEdit->text();
    if(otherPhone==""){
        textFilter="";
        return textFilter;
    }

    if(parsingLocation()||parsingPersonale()||ui->diameterCombo->currentIndex()||ui->pumpCheckBox->isChecked()||ui->serviseCheckBox->isChecked())
        textFilter=QString(" AND ClientsCard.otherPhone LIKE '%%1%'").arg(otherPhone);
    else
        textFilter=QString(" WHERE ClientsCard.otherPhone LIKE '%%1%'").arg(otherPhone);

    return textFilter;

}


int ClientsWindows::parsingLocation()
{
    int parsing;
    int id_region=mapComboGegion_.value(ui->regionCombo_2->currentIndex());
    int id_district=mapComboDistrict_.value(ui->districtCombo_2->currentIndex());

    QString locality= ui->localityLineEdit_2->text();
    QString street= ui->streetLineEdit_3->text();


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


int ClientsWindows::parsingPersonale()
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

QString ClientsWindows::filterPersonale()
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

    if(parsingLocation()||ui->diameterCombo->currentIndex()||\
            ui->pumpCheckBox->isChecked()||ui->serviseCheckBox->isChecked()){
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


void ClientsWindows::fillDiameter()
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


personale ClientsWindows::fillDataClient(int ID_DataClient)
{
    QString query;
    personale pers;
    query=QString("SELECT ClientsCard.surname, ClientsCard.name_, ClientsCard.patronymic, ClientsCard.mobilPhone,\
                  District.id_region, ClientsCard.id_district, ClientsCard.locality, ClientsCard.street, ClientsCard.dept, \
                  ClientsCard.id_instruments, ClientsCard.pump, ClientsCard.service, ClientsCard.dataBegin, ClientsCard.dataEnd, ClientsCard.notes, ClientsCard.otherPhone\
                  FROM (ClientsCard INNER JOIN District ON ClientsCard.id_district = District.id)\
                  INNER JOIN Region ON District.id_region = Region.ID where ClientsCard.ID=%1;").arg(ID_DataClient);

            //qDebug()<<query;
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
    pers.dept=queryNew.value(8).toString();
    pers.id_diameter=queryNew.value(9).toInt();
    pers.pump=queryNew.value(10).toBool();
    pers.service=queryNew.value(11).toBool();
    pers.dataBegin=queryNew.value(12).toDateTime();
    pers.dataEnd=queryNew.value(13).toDateTime();
    pers.note=queryNew.value(14).toString();
    pers.otherPhone=queryNew.value(15).toString();

    return pers;
}
