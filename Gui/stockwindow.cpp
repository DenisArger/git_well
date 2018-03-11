#include "stockwindow.h"
#include "ui_stockwindow.h"

#include <QToolButton>
#include "global.h"
#include "QFont"
#include <QInputDialog>

StockWindow::StockWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StockWindow)
{
    ui->setupUi(this);
    editInstruments=new EditInstrumentsDialog();


    dataBase.connectToDataBase();
    this->setupModelBase(QStringList() << trUtf8("ID")
                         << trUtf8("Класс")
                         << trUtf8("Название")
                         << trUtf8("Остаток")
                         );

    /* Инициализируем внешний вид таблицы с данными
     * */
    this->createUI();

    QToolButton *tb = new QToolButton();
    addIntruments=new AddInstruments();

    tb->setText("+");
    tb->setAutoRaise(true);
    connect(tb, SIGNAL(clicked()), this, SLOT(addTab()));
    connect(ui->editBalanceButton,SIGNAL(clicked(bool)),editInstruments, SLOT(showWindow()));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(parsingIdInstr(QModelIndex)));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(showHistory()));
    connect(editInstruments,SIGNAL(applyClick()),this,SLOT(updateWindows()));
    connect(addIntruments,SIGNAL(closeSignal()),this,SLOT(updateWindows()));
    connect(ui->closeButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->addInstrButton,SIGNAL(clicked(bool)),addIntruments,SLOT(showWindow()));

    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(setCurrentTab(int)));


    ui->tabWidget->addTab(new QLabel("You can add tabs by pressing <b>\"+\"</b>"), QString());
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->tabBar()->setTabButton(1, QTabBar::RightSide, tb);

    insertTabClassInstruments();
}

StockWindow::~StockWindow()
{
    delete ui;
}


void StockWindow::showWindow()
{
    this->showMaximized();
}

void StockWindow::addTab()
{
    bool ok;
    QString nameClassInstruments = QInputDialog::getText(this, tr("Создание вкладки"),
                                                         tr("Название вкладки:"), QLineEdit::Normal,
                                                         "", &ok);
    if (!ok) {
        return;
        // Была нажата кнопка Cancel
    }
    else
        addClassIntruments(nameClassInstruments);

    ui->tab = new QWidget();
    ui->tab->setObjectName(QStringLiteral("tab_2"));
    ui->verticalLayout_4 = new QVBoxLayout(ui->tab);
    ui->verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
    ui->tableView = new QTableView(ui->tab);
    ui->tableView->setObjectName(QStringLiteral("tableView_2"));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
    sizePolicy2.setHeightForWidth(ui->tableView->sizePolicy().hasHeightForWidth());
    ui->tableView->setSizePolicy(sizePolicy2);
    ui->tableView->setMinimumSize(QSize(0, 150));

    QFont font1;
    font1.setPointSize(12);
    ui->tableView->setFont(font1);

    ui->verticalLayout_4->addWidget(ui->tableView);
    ui->tabWidget->insertTab( ui->tabWidget->count() - 1, ui->tab, nameClassInstruments);


}

void StockWindow::setCurrentTab(int index)
{
    addIntruments->setCurrentTab(index);
    editInstruments->setCurrentTab(index);
}

void StockWindow::addClassIntruments(QString nameClassInstruments)
{
    QString queryStr;
    if(idLoginGlobal!=1)
        queryStr= QString("INSERT INTO ClassInstruments (NameClass) SELECT '%1'").arg(nameClassInstruments);
    else
        queryStr= QString("INSERT INTO ClassInstruments_Antony (NameClass) SELECT '%1'").arg(nameClassInstruments);

    dataBase.queryToBase(queryStr);
}

void StockWindow::setupModelBaseID(const QStringList &headers, int idClassInstruments)
{
    QString query;
    if(idClassInstruments!=1){
        if(idLoginGlobal!=1){
            query=QString("SELECT Instruments.id, ClassInstruments.NameClass,\
                          Instruments.nameInstruments, Instruments.balance\
                          FROM ClassInstruments INNER JOIN Instruments \
                          ON ClassInstruments.ID = Instruments.idClassInstruments \
                    where  Instruments.id>0 and  Instruments.idClassInstruments=%1\
                    GROUP BY Instruments.id, ClassInstruments.NameClass,\
                          Instruments.nameInstruments, Instruments.balance;").arg(idClassInstruments);
        }
        else{
            query=QString("SELECT Instruments_Antony.id, ClassInstruments_Antony.NameClass,\
                          Instruments_Antony.nameInstruments, Instruments_Antony.balance\
                          FROM ClassInstruments_Antony INNER JOIN Instruments_Antony \
                          ON ClassInstruments_Antony.ID = Instruments_Antony.idClassInstruments \
                    where  Instruments_Antony.id>0 and  Instruments_Antony.idClassInstruments=%1\
                    GROUP BY Instruments_Antony.id, ClassInstruments_Antony.NameClass,\
                          Instruments_Antony.nameInstruments, Instruments_Antony.balance;").arg(idClassInstruments);
        }
    }
    else{
        if(idLoginGlobal!=1){
            query=QString("SELECT Instruments.id,ClassInstruments.NameClass, \
                          Instruments.nameInstruments, Count(Instruments.id) AS [Count-id], \
                    Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
                    FROM ClassInstruments INNER JOIN (ClientsCard INNER JOIN Instruments \
                                                      ON ClientsCard.id_instruments = Instruments.id) ON ClassInstruments.ID = Instruments.idClassInstruments\
                    where Instruments.id >0 and  Instruments.idClassInstruments=%1\
                    GROUP BY Instruments.id, ClassInstruments.NameClass,  \
                    Instruments.nameInstruments, Instruments.balance;").arg(idClassInstruments);
        }
        else{
            query=QString("SELECT Instruments_Antony.id,ClassInstruments_Antony.NameClass, \
                          Instruments_Antony.nameInstruments, Count(Instruments_Antony.id) AS [Count-id], \
                    Sum(ClientsCard.dept) AS [Sum-dept], Instruments_Antony.balance\
                    FROM ClassInstruments_Antony INNER JOIN (ClientsCard INNER JOIN Instruments_Antony \
                                                             ON ClientsCard_Antony.id_instruments = Instruments_Antony.id) ON ClassInstruments_Antony.ID = Instruments_Antony.idClassInstruments\
                    where Instruments_Antony.id >0 and  Instruments_Antony.idClassInstruments=%1\
                    GROUP BY Instruments_Antony.id, ClassInstruments_Antony.NameClass,  \
                    Instruments_Antony.nameInstruments, Instruments_Antony.balance;").arg(idClassInstruments);
        }
    }

    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    modelTemp = new QSqlQueryModel(this);
    modelTemp->setQuery(query , dataBase.getDatase());

    qDebug()<<query;
    /* Устанавливаем названия колонок в таблице с сортировкой данных*/

    for(int i = 0, j = 0; i <modelTemp->columnCount(); i++, j++){
        modelTemp->setHeaderData(i,Qt::Horizontal,headers[j]);

    }
    vecQueryModelTab.push_back(modelTemp);
}


void StockWindow::insertTabClassInstruments()
{
    QString queryStr;
    if(idLoginGlobal!=1){
        queryStr="SELECT ClassInstruments.ID,ClassInstruments.NameClass \
                FROM ClassInstruments where ClassInstruments.ID>0 ;";
    }
    else{
        queryStr="SELECT ClassInstruments_Antony.ID,ClassInstruments_Antony.NameClass \
                FROM ClassInstruments_Antony where ClassInstruments_Antony.ID>0 ;";
    }
    QSqlQuery query=dataBase.queryToBase(queryStr);
    while(query.next()) {

        QString nameClassInstruments= query.value(1).toString();

        ui->tab = new QWidget();
        ui->tab->setObjectName(QStringLiteral("tab_2"));
        ui->verticalLayout_4 = new QVBoxLayout(ui->tab);
        ui->verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        ui->tableView = new QTableView(ui->tab);
        ui->tableView->setObjectName(QStringLiteral("tableView_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHeightForWidth(ui->tableView->sizePolicy().hasHeightForWidth());
        ui->tableView->setSizePolicy(sizePolicy2);
        ui->tableView->setMinimumSize(QSize(0, 150));

        QFont font1;
        font1.setPointSize(12);
        ui->tableView->setFont(font1);

        ui->verticalLayout_4->addWidget(ui->tableView);
        ui->tabWidget->insertTab( ui->tabWidget->count() - 1, ui->tab, nameClassInstruments);
        connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(parsingIdInstr(QModelIndex)));
        connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(showHistory()));


        if(query.value(0).toInt()!=1){
            this->setupModelBaseID(                   QStringList() << trUtf8("ID")
                                                      << trUtf8("Класс")
                                                      << trUtf8("Название")
                                                      << trUtf8("Остаток")
                                                      ,query.value(0).toInt());
        }
        else{
            this->setupModelBaseID(                QStringList() << trUtf8("ID")
                                                   << trUtf8("Класс")
                                                   << trUtf8("Название")
                                                   << trUtf8("Кол-во заказов за период")
                                                   << trUtf8("Потрачено за период")
                                                   << trUtf8("Остаток")
                                                   ,query.value(0).toInt());
        }
        createUIClassInstruments();
    }
}

void StockWindow::fillDate()
{
    QDate dateToday = QDate::currentDate();
    QDate dateTodayBack= dateToday.addDays(-7);
    ui->dataBegindateEdit->setDate(dateTodayBack);
    ui->dataEnddateEdit->setDate(dateToday);
}


void StockWindow::setupModel(const QStringList &headers)
{
    QDate dateToday = QDate::currentDate();
    QDate dateTodayBack= dateToday.addDays(-7);
    ui->dataBegindateEdit->setDate(dateTodayBack);
    ui->dataEnddateEdit->setDate(dateToday);

    QString dateTodayStr= ui->dataEnddateEdit->text().replace(".","/");
    QString dateTodayBackStr= ui->dataBegindateEdit->text().replace(".","/");
    QString query=QString("SELECT Instruments.id,ClassInstruments.NameClass, \
                          Instruments.nameInstruments, Count(Instruments.id) AS [Count-id], \
            Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
            FROM ClassInstruments INNER JOIN (ClientsCard INNER JOIN Instruments \
                                              ON ClientsCard.id_instruments = Instruments.id) ON ClassInstruments.ID = Instruments.idClassInstruments\
            where Instruments.id >0\
            GROUP BY Instruments.id, ClassInstruments.NameClass,  \
            Instruments.nameInstruments, Instruments.balance;") .arg(dateTodayBackStr).arg(dateTodayStr);

    //WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))

    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(query , dataBase.getDatase());

    qDebug()<<query;
    /* Устанавливаем названия колонок в таблице с сортировкой данных*/

    for(int i = 0, j = 0; i <model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);

    }
}


void StockWindow:: setupModelBase(const QStringList &headers)
{
    if(idLoginGlobal!=1){
        mainQuery=QString("SELECT Instruments.id, ClassInstruments.NameClass,\
                          Instruments.nameInstruments, Instruments.balance\
                          FROM ClassInstruments INNER JOIN Instruments \
                          ON ClassInstruments.ID = Instruments.idClassInstruments where  Instruments.id>0\
                GROUP BY Instruments.id, ClassInstruments.NameClass,\
                          Instruments.nameInstruments, Instruments.balance;");
    }
    else{
        mainQuery=QString("SELECT Instruments_Antony.id, ClassInstruments_Antony.NameClass,\
                          Instruments_Antony.nameInstruments, Instruments_Antony.balance\
                          FROM ClassInstruments_Antony INNER JOIN Instruments_Antony \
                          ON ClassInstruments_Antony.ID = Instruments_Antony.idClassInstruments where  Instruments_Antony.id>0\
                GROUP BY Instruments_Antony.id, ClassInstruments_Antony.NameClass,\
                          Instruments_Antony.nameInstruments, Instruments_Antony.balance;");
    }

    /* Производим инициализацию модели представления данных
    * с установкой имени таблицы в базе данных, по которому
    * будет производится обращение в таблице
    * */
    modelMain = new QSqlQueryModel(this);
    modelMain->setQuery(mainQuery , dataBase.getDatase());

    qDebug()<<mainQuery;

    /* Устанавливаем названия колонок в таблице с сортировкой данных*/

    for(int i = 0, j = 0; i <modelMain->columnCount(); i++, j++){
        modelMain->setHeaderData(i,Qt::Horizontal,headers[j]);

    }
}

void StockWindow::setupModelClassInstruments(const QStringList &headers, int idClassInstruments)
{
    QDate dateToday = QDate::currentDate();
    QDate dateTodayBack= dateToday.addDays(-7);
    ui->dataBegindateEdit->setDate(dateTodayBack);
    ui->dataEnddateEdit->setDate(dateToday);

    //QString dateTodayStr= ui->dataEnddateEdit->text().replace(".","/");
    //QString dateTodayBackStr= ui->dataBegindateEdit->text().replace(".","/");
    QString query=QString("SELECT Instruments.id,ClassInstruments.NameClass, \
                          Instruments.nameInstruments, Count(Instruments.id) AS [Count-id], \
            Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
            FROM ClassInstruments INNER JOIN (ClientsCard INNER JOIN Instruments \
                                              ON ClientsCard.id_instruments = Instruments.id) ON ClassInstruments.ID = Instruments.idClassInstruments\
            where Instruments.id >0 and  Instruments.idClassInstruments=%1\
            GROUP BY Instruments.id, ClassInstruments.NameClass,  \
            Instruments.nameInstruments, Instruments.balance;").arg(idClassInstruments);
    vecQueryTab.push_back(query);


    //WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))

    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(query , dataBase.getDatase());

    vecQueryModelTab.push_back(model);

    qDebug()<<query;
    /* Устанавливаем названия колонок в таблице с сортировкой данных*/

    for(int i = 0, j = 0; i <model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);

    }
}

void StockWindow::createUI()
{
    //vecTabWidget->push_back(ui->tableView);

    ui->tableView->setModel(modelMain);     // Устанавливаем модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    //ui->tableView->setColumnHidden(2, true);    // Скрываем колонку c количеством заказов за период
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    modelMain->setQuery(modelMain->query().lastQuery());


}


void StockWindow::createUIClassInstruments()
{
    ui->tableView->setModel(modelTemp);     // Устанавливаем модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    //ui->tableView->setColumnHidden(2, true);    // Скрываем колонку c количеством заказов за период
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    modelTemp->setQuery(modelTemp->query().lastQuery());
}

void StockWindow::parsingIdInstr(QModelIndex index)
{
    //Получаем индекс нужного ИД
    QModelIndex indexID= index.sibling(index.row(),0);
    idDiameter_=indexID.model()->data(indexID, Qt::DisplayRole).toInt();
    editInstruments->setIdDiameter(idDiameter_);
    editInstruments->setCurrTypeInstruments();
    editInstruments->fillBalance();

}


void StockWindow::showHistory()
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

    if(idLoginGlobal!=1){
        queryStr=QString("SELECT MovementInstruments.dateOperation, Instruments.nameInstruments, \
                         MovementInstruments.typeOperation, MovementInstruments.countInstr,MovementInstruments.source,\
                         MovementInstruments.notes  FROM MovementInstruments INNER JOIN Instruments ON\
                         (MovementInstruments.idInstruments = Instruments.id) \
                         AND (MovementInstruments.idInstruments = Instruments.id) where  \
                         MovementInstruments.idInstruments=%1  ORDER BY MovementInstruments.dateOperation DESC ").arg(idDiameter_);
    }
    else{

        queryStr=QString("SELECT MovementInstruments_Antony.dateOperation, Instruments_Antony.nameInstruments, \
                         MovementInstruments_Antony.typeOperation, MovementInstruments_Antony.countInstr,\
                         MovementInstruments_Antony.source,\
                         MovementInstruments_Antony.notes  FROM MovementInstruments_Antony INNER JOIN Instruments_Antony ON\
                         (MovementInstruments_Antony.idInstruments = Instruments_Antony.id) \
                         AND (MovementInstruments_Antony.idInstruments = Instruments_Antony.id) where  \
                         MovementInstruments_Antony.idInstruments=%1  ORDER BY MovementInstruments_Antony.dateOperation DESC ").arg(idDiameter_);
    }

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

void StockWindow::updateWindows()
{
    modelMain->setQuery(modelMain->query().lastQuery());

    for(int i=0;i<vecQueryModelTab.size();i++){
        vecQueryModelTab[i]->setQuery(vecQueryModelTab[i]->query().lastQuery());
    }

    showHistory();
}

void StockWindow::clickClearButton()
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
    if(idLoginGlobal!=1){
        modelMain->setQuery( QString("SELECT Instruments.id, Instruments.nameInstruments, Count(Instruments.id) \
                                     AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
                FROM ClientsCard INNER JOIN Instruments ON ClientsCard.id_instruments = Instruments.id\
                WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))\
                GROUP BY Instruments.id, Instruments.nameInstruments, Instruments.balance;")
        .arg(dateTodayBackStr).arg(dateTodayStr), dataBase.getDatase());
    }
    else{
        modelMain->setQuery( QString("SELECT Instruments_Antony.id, Instruments_Antony.nameInstruments, Count(Instruments_Antony.id) \
                                     AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Instruments_Antony.balance\
                FROM ClientsCard INNER JOIN Instruments_Antony ON ClientsCard.id_instruments = Instruments_Antony.id\
                WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))\
                GROUP BY Instruments_Antony.id, Instruments_Antony.nameInstruments, Instruments_Antony.balance;")
        .arg(dateTodayBackStr).arg(dateTodayStr), dataBase.getDatase());
    }

    modelMain->setQuery(modelMain->query().lastQuery());
    qDebug() << modelMain->query().lastError().text();
}

void StockWindow::clickSumButton()
{
    QString dateTodayStr= ui->dataEnddateEdit->text().replace(".","/");
    QString dateTodayBackStr= ui->dataBegindateEdit->text().replace(".","/");

    QString query;
    if(idLoginGlobal!=1){
        query= QString("SELECT Instruments.id, Instruments.nameInstruments, Count(Instruments.id) \
                       AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
                FROM ClientsCard INNER JOIN Instruments ON ClientsCard.id_instruments = Instruments.id\
                WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))\
                GROUP BY Instruments.id, Instruments.nameInstruments, Instruments.balance;")
        .arg(dateTodayBackStr).arg(dateTodayStr);
    }
    else{
        query= QString("SELECT Instruments_Antony.id, Instruments_Antony.nameInstruments, Count(Instruments_Antony.id) \
                       AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Instruments_Antony.balance\
                FROM ClientsCard INNER JOIN Instruments_Antony ON ClientsCard.id_instruments = Instruments_Antony.id\
                WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))\
                GROUP BY Instruments_Antony.id, Instruments_Antony.nameInstruments, Instruments_Antony.balance;")
        .arg(dateTodayBackStr).arg(dateTodayStr);
    }




        /* Производим инициализацию модели представления данных
      * с установкой имени таблицы в базе данных, по которому
      * будет производится обращение в таблице
      * */
        //model = new QSqlQueryModel(this);
        modelMain->setQuery(query, dataBase.getDatase());

        qDebug()<<query;
        QSqlQuery queryRun=modelMain->query();

        modelMain->setQuery(queryRun.lastQuery());


        //qDebug() << model->query().lastError().text();
    }

    void StockWindow::clickCurrBalanceButton()
    {

    }


    void StockWindow::clickAdd()
    {

    }


    void StockWindow::clickEdit()
    {

    }

    void StockWindow::clickDelete()
    {

    }

    void StockWindow::clickAddInstruments()
    {

    }
