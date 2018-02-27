#include "diameter.h"
#include "ui_diameter.h"
#include "global.h"
#include "QFont"

diameter::diameter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::diameter)
{
    ui->setupUi(this);

    editInstruments=new EditInstrumentsDialog();
    operationStock=new OperationStock();

    dataBase.connectToDataBase();
    this->setupModel(                   QStringList() << trUtf8("ID")
                                   << trUtf8("Диаметр")
                                   << trUtf8("Кол-во заказов за период")
                                   << trUtf8("Потрачено за период")
                                   << trUtf8("Остаток")
               );

    /* Инициализируем внешний вид таблицы с данными
     * */
    this->createUI();
    //fillDate();

    connect(ui->addInstrButton,SIGNAL(clicked(bool)),operationStock, SLOT(show()));
    connect(ui->editInstrumentsButton,SIGNAL(clicked(bool)),editInstruments, SLOT(show()));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(parsingIdInstr(QModelIndex)));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(showHistory()));
    connect(editInstruments,SIGNAL(applyClick()),this,SLOT(updateWindows()));
    connect(operationStock,SIGNAL(closeSignal()),this,SLOT(updateWindows()));
}

diameter::~diameter()
{
    delete ui;
}

void diameter::fillDate()
{
    QDate dateToday = QDate::currentDate();
    QDate dateTodayBack= dateToday.addDays(-7);
    ui->dataBegindateEdit->setDate(dateTodayBack);
    ui->dataEnddateEdit->setDate(dateToday);
}


void diameter::setupModel(const QStringList &headers)
{
    QDate dateToday = QDate::currentDate();
    QDate dateTodayBack= dateToday.addDays(-7);
    ui->dataBegindateEdit->setDate(dateTodayBack);
    ui->dataEnddateEdit->setDate(dateToday);

   QString dateTodayStr= ui->dataEnddateEdit->text().replace(".","/");
   QString dateTodayBackStr= ui->dataBegindateEdit->text().replace(".","/");
   QString query=QString("SELECT Diameter.id, Diameter.numberDiameter, Count(Diameter.id) \
                         AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Diameter.balance\
                         FROM ClientsCard INNER JOIN Diameter ON ClientsCard.id_diameter = Diameter.id\
                         GROUP BY Diameter.id, Diameter.numberDiameter, Diameter.balance;")
                     .arg(dateTodayBackStr).arg(dateTodayStr);

       //WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))

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

void diameter::createUI()
{
    ui->tableView->setModel(model);     // Устанавливаем модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    ui->tableView->setColumnHidden(2, true);    // Скрываем колонку c количеством заказов за период
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

void diameter::on_pushButton_3_clicked()
{
    close();
}

void diameter::on_pushButton_clicked()
{
   QString dateTodayStr= ui->dataEnddateEdit->text().replace(".","/");
   QString dateTodayBackStr= ui->dataBegindateEdit->text().replace(".","/");
   QString query= QString("SELECT Diameter.id, Diameter.numberDiameter, Count(Diameter.id) \
                          AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Diameter.balance\
                          FROM ClientsCard INNER JOIN Diameter ON ClientsCard.id_diameter = Diameter.id\
                          WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))\
                          GROUP BY Diameter.id, Diameter.numberDiameter, Diameter.balance;")
                      .arg(dateTodayBackStr).arg(dateTodayStr);



    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    //model = new QSqlQueryModel(this);
    model->setQuery(query, dataBase.getDatase());

    //qDebug()<<query;
    QSqlQuery queryRun=model->query();

    model->setQuery(queryRun.lastQuery());


    //qDebug() << model->query().lastError().text();
}

void diameter::on_clearButtton_clicked()
{
    QDate dateToday = QDate::currentDate();
    QDate dateTodayBack= dateToday.addDays(-7);
    ui->dataBegindateEdit->setDate(dateTodayBack);
    ui->dataEnddateEdit->setDate(dateToday);

    QString dateTodayStr= ui->dataEnddateEdit->text().replace(".","/");
    QString dateTodayBackStr= ui->dataBegindateEdit->text().replace(".","/");


    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    //model = new QSqlQueryModel(this);
    model->setQuery( QString("SELECT Diameter.id, Diameter.numberDiameter, Count(Diameter.id) \
        AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Diameter.balance\
        FROM ClientsCard INNER JOIN Diameter ON ClientsCard.id_diameter = Diameter.id\
        WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))\
        GROUP BY Diameter.id, Diameter.numberDiameter, Diameter.balance;")
    .arg(dateTodayBackStr).arg(dateTodayStr), dataBase.getDatase());

    model->setQuery(model->query().lastQuery());
    qDebug() << model->query().lastError().text();
}


void diameter::parsingIdInstr(QModelIndex index)
{
    //Получаем индекс нужного ИД
    QModelIndex indexID= index.sibling(index.row(),0);
    idDiameter_=indexID.model()->data(indexID, Qt::DisplayRole).toInt();
    editInstruments->setIdDiameter(idDiameter_);
    editInstruments->setCurrTypeInstruments();
    editInstruments->fillBalance();

}


void diameter::showHistory()
{
    ui->historyTextEdit->clear();
    ui->legendTextEdit->clear();

    QString queryStr;
    QSqlQuery querySql;

    QString dateOperation;
    QString nameInstr;
    QString typeOpeation;
    QString countIsntr;
    QString source;
    QString notes;
    QFont font;


    queryStr=QString("SELECT MovementDiameter.dateOperation, Diameter.numberDiameter, MovementDiameter.typeOperation, MovementDiameter.countInstr,\
             MovementDiameter.source, MovementDiameter.notes  FROM MovementDiameter INNER JOIN Diameter ON (MovementDiameter.idDiameter = Diameter.id) \
              AND (MovementDiameter.idDiameter = Diameter.id) where  MovementDiameter.idDiameter=%1  ORDER BY MovementDiameter.dateOperation DESC ").arg(idDiameter_);

    querySql=dataBase.queryToBase(queryStr);


    font.setPointSize(10);
    ui->legendTextEdit->setFont(font);

    ui->legendTextEdit->setTextColor(QColor(0,155,255));
    //ui->historyTextEdit->append(dateOperation);
    ui->legendTextEdit->insertPlainText("Дата операции ");

    ui->legendTextEdit->setTextColor( QColor(110,155,155));
    //ui->historyTextEdit->insertPlainText(typeOpeation);
    ui->legendTextEdit->insertPlainText("Название инструмента ");

    ui->legendTextEdit->setTextColor( QColor(190,195,55));
    //ui->historyTextEdit->insertPlainText(countIsntr);
    ui->legendTextEdit->insertPlainText("Тип операции ");


    ui->legendTextEdit->setTextColor( QColor(190,55,255));
    //ui->historyTextEdit->insertPlainText(countIsntr);
    ui->legendTextEdit->insertPlainText("Количество ");

    ui->legendTextEdit->setTextColor( QColor(200,155,155));
   // ui->historyTextEdit->insertPlainText(source);
    ui->legendTextEdit->insertPlainText("Источник ");

    ui->legendTextEdit->setTextColor( QColor(180,0,115));
   // ui->historyTextEdit->insertPlainText(notes);
    ui->legendTextEdit->insertPlainText("Примечание ");


    font.setPointSize(12);
     ui->historyTextEdit->setFont(font);


    while (querySql.next()) {
            dateOperation = querySql.value(0).toDateTime().toString("dd.MM.yyyy");
            nameInstr = querySql.value(1).toString();

            if( querySql.value(2).toInt()==1 )
            typeOpeation="Приход";
            else if ( querySql.value(2).toInt()==2 )
            typeOpeation="Расход";
            else
            typeOpeation="";

            countIsntr = querySql.value(3).toString();
            source = querySql.value(4).toString();
            notes = querySql.value(5).toString();


            ui->historyTextEdit->setTextColor(QColor(0,155,255));
            ui->historyTextEdit->append(dateOperation);
            ui->historyTextEdit->insertPlainText("  ");

            ui->historyTextEdit->setTextColor( QColor(110,155,155));
            ui->historyTextEdit->insertPlainText(nameInstr);
            ui->historyTextEdit->insertPlainText("  ");

            ui->historyTextEdit->setTextColor( QColor(190,195,55));
            ui->historyTextEdit->insertPlainText(typeOpeation);
            ui->historyTextEdit->insertPlainText("  ");

            ui->historyTextEdit->setTextColor( QColor(190,55,255));
            ui->historyTextEdit->insertPlainText(countIsntr);
            ui->historyTextEdit->insertPlainText("  ");

            ui->historyTextEdit->setTextColor( QColor(200,155,155));
            ui->historyTextEdit->insertPlainText(source);
            ui->historyTextEdit->insertPlainText(" ");

            ui->historyTextEdit->setTextColor( QColor(180,0,115));
            ui->historyTextEdit->insertPlainText(notes);
            ui->historyTextEdit->insertPlainText("  ");
    }
}

void diameter::updateWindows()
{
     model->setQuery(model->query().lastQuery());
     showHistory();
}
