#include "servicecard.h"
#include "ui_servicecard.h"
#include "QDesktopWidget"

servicecard::servicecard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::servicecard)
{
    ui->setupUi(this);
    fillStateService();
    fillStatePayment();
    fillTypePump();
    fillStatePump();
    fillLocationPump();
    fillSeasone();
    fillDistrict_FULL();
    fillRegion();

     connect(ui->regionCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(fillDistrict()));

     this->setMinimumSize(gWidth*0.42,gHeight*0.90);
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

servicecard::~servicecard()
{
    delete ui;
}

void servicecard::setIdClient(int ID)

{
    id_client=ID;
}

void servicecard::setIdService(int ID)
{
    id_service=ID;
}

/*void servicecard::fillServiceCart(personaleService pers)
{
    if(pers.dataBeginService.toString()!="")
        ui->dataBeginServiceEdit->setEnabled(true);
    /*if(pers.dataNextService.toString()!="")
        ui->dataNextServiceEdit->setEnabled(true);*/

  /*  ui->surnameLineEdit->setText(pers.surname);
    ui->nameLineEdit->setText(pers.name);
    ui->patronymicLineEdit->setText(pers.patronymic);
    ui->mobilPhoneLineEdit->setText(pers.phone);
    ui->regionCombo->setCurrentIndex(pers.id_region);
    ui->districtCombo->setCurrentIndex(pers.id_district);
    ui->localityLineEdit->setText(pers.locality);
    ui->streetLineEdit->setText(pers.street);
    ui->stateServiceCombo->setCurrentIndex(pers.id_stateService);
    ui->statePaymentCombo->setCurrentIndex(pers.id_statePayment);
    ui->dataBeginServiceEdit->setDateTime(pers.dataBeginService);
    ui->typePumpCombo->setCurrentIndex(pers.id_typePump);
    ui->statePumpCombo->setCurrentIndex(pers.id_statePump);
    ui->locationePumpCombo->setCurrentIndex(pers.id_locationPump);
    ui->seasonaCombo->setCurrentIndex(pers.id_seasone);
    //ui->dataNextServiceEdit->setDateTime(pers.dataNextService);
    ui->noteEdit->setText(pers.note);
}
*/

void servicecard::on_pushButton_clicked()
{
    //updateServiceCard();
    close();
}

void servicecard::on_closeButton_clicked()
{
    close();
}


void servicecard::fillStateService()
{
    ui->stateServiceCombo->clear();
    QSqlQuery query=dataBase.queryToBase("SELECT StateService.*FROM StateService;");
    while(query.next()) {
        ui->stateServiceCombo->addItem(query.value(1).toString(), query.value(0));
    }



}

void servicecard::fillStatePayment()
{
    ui->statePaymentCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT StatePayment.* FROM StatePayment;");
    while(query.next()) {
        ui->statePaymentCombo->addItem(query.value(1).toString(), query.value(0));
    }

}


void servicecard::fillTypePump()
{
    ui->typePumpCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT TypePump.* FROM TypePump;");
    while(query.next()) {
        ui->typePumpCombo->addItem(query.value(1).toString(), query.value(0));
    }

}


void servicecard::fillStatePump()
{
    ui->statePumpCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT StatePump.* FROM StatePump;");
    while(query.next()) {
        ui->statePumpCombo->addItem(query.value(1).toString(), query.value(0));
    }
}


void servicecard::fillLocationPump()
{
    ui->locationePumpCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT LocationPump.* FROM LocationPump;");
    while(query.next()) {
        ui->locationePumpCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void servicecard::fillSeasone()
{
    ui->seasonaCombo->clear();

    QSqlQuery query=dataBase.queryToBase("SELECT Seasone.* FROM Seasone;");
    while(query.next()) {
        ui->seasonaCombo->addItem(query.value(1).toString(), query.value(0));
    }
}


void servicecard::fillRegion()
{
    ui->regionCombo->clear();
    QSqlQuery query=dataBase.getQueryRegion();
    while(query.next()) {
        ui->regionCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void servicecard::fillDistrict()
{
    ui->districtCombo->clear();
    int id_Region=ui->regionCombo->currentIndex();
    QSqlQuery query=dataBase.getQueryDistrict(id_Region);
    while (query.next()) {
        ui->districtCombo->addItem(query.value(1).toString(), query.value(0));
    }
}

void servicecard::fillDistrict_FULL()
{
    ui->districtCombo->clear();
    QSqlQuery query=dataBase.getQueryDistrict_FULL();
    while (query.next()) {
        ui->districtCombo->addItem(query.value(1).toString(), query.value(0));
    }
}



/*void servicecard::updateServiceCard()
{
    personaleService pers;

    dataService=ui->dataBeginServiceEdit->dateTime();

    pers.dataBeginServiceStr=ui->dataBeginServiceEdit->text();
    pers.id_stateService=ui->stateServiceCombo->currentIndex();
    pers.id_statePayment=ui->statePaymentCombo->currentIndex();
    pers.id_statePump=ui->statePumpCombo->currentIndex();
    pers.id_typePump=ui->typePumpCombo->currentIndex();
    pers.id_seasone=ui->seasonaCombo->currentIndex();
    pers.id_locationPump=ui->locationePumpCombo->currentIndex();


    pers.note=ui->noteEdit->toPlainText();


    QString query= QString( "update Service set idStateService = %1, idStatePayment=%2, dataBegin='%3', idTypePump=%4, \
                   idStatePump=%5, idLocationPump=%6, idSeasone=%7,notes='%8'").arg( pers.id_stateService).arg(  pers.id_statePayment).\
                    arg( pers.dataBeginServiceStr).arg(pers.id_typePump).arg( pers.id_statePump).arg(pers.id_locationPump).\
                    arg(pers.id_seasone).arg(pers.note);

    query+=QString(" where idClient=%1 ").arg(id_client);

    dataBase.queryToBase(query);

}
*/
void servicecard::createNextDataService(int index)
{
    dataService=ui->dataBeginServiceEdit->dateTime();
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


void servicecard::setupModel(const QStringList &headers)
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

void servicecard::createUI()
{
    ui->tableView->setModel(model);     // Устанавливаем модель на TableView


    //ui->tableView->horizontalHeader()->hide();
    //ui->tableView->verticalHeader()->hide();

    ui->tableView->horizontalHeader()->setVisible(false);// Скрываем количество строк
    ui->tableView->verticalHeader()->setVisible(false);// заголовки таблицы

    ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    //ui->tableView->setColumnHidden(1, true);    // Скрываем колонку с флагом обслуживания
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения нескольких строк в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


     model->setQuery(model->query().lastQuery());


}

void servicecard::on_typePumpCombo_currentIndexChanged(int index)
{
    createNextDataService(index);
}
