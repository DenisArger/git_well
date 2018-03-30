#include "stockwindow.h"
#include "ui_stockwindow.h"

#include <QToolButton>
#include "global.h"
#include "QFont"
#include <QInputDialog>

StockWindow::StockWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StockWindow),
    idInstrument_(-1)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile(QStringLiteral("../icon/well.png"), QSize(), QIcon::Disabled, QIcon::Off);
    this->setWindowIcon(icon);
    editInstruments=new EditInstrumentsDialog();


    if(!dataBase.connectToDataBase())
        return;
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
    connect(ui->editBalanceInstrButton,SIGNAL(clicked(bool)),this, SLOT(showEditBalanceWindows()));

    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(parsingIdInstr(QModelIndex)));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(showHistory()));

    connect(editInstruments,SIGNAL(applyClick()),this,SLOT(updateWindows()));
    connect(addIntruments,SIGNAL(closeSignal()),this,SLOT(updateWindows()));
    connect(ui->closeButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->addInstrButton,SIGNAL(clicked(bool)),addIntruments,SLOT(showWindow()));
    connect(ui->addInstrButton,SIGNAL(clicked(bool)),this,SLOT(setMapTab()));
    connect(ui->editNameInstrButton,SIGNAL(clicked(bool)),this,SLOT(editNameInstrument()));
    connect(ui->deleteInstrButton,SIGNAL(clicked(bool)),this,SLOT(deleteInstrument()));


    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(setCurrentTab(int)));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(showReCoutInstruments(int)));

    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(showConfirmDelete(int)));
    connect(ui->tabWidget,SIGNAL(tabBarDoubleClicked(int)),this,SLOT(editNameClassInstrument(int)));


    ui->tabWidget->addTab(new QLabel("You can add tabs by pressing <b>\"+\"</b>"), QString());
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->tabBar()->setTabButton(1, QTabBar::RightSide, tb);

    //Добавление владок для групп материалов
    insertTabClassInstruments();
    //Заполнение словаря
    insertMapTab();
}

StockWindow::~StockWindow()
{
    delete ui;
}


void StockWindow::showWindow()
{
    this->showMaximized();
    ui->groupBox_3->hide();
}

void StockWindow::addTab()
{
    bool ok;
    QFont  font;
    font.setPointSize(11);
    QApplication::setFont(font);
    QString nameClassInstruments = QInputDialog::getText(this, tr("Добавление группы материалов"),
                                                         tr("Введите название группы материалов:"), QLineEdit::Normal,
                                                         "", &ok);
    if (!ok) {
        return;
        // Была нажата кнопка Cancel
    }
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

    addClassIntruments(nameClassInstruments);
    //Заполнить словарь
    insertMapTab();
    //Изменить текущую вкладку
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 2);
}

void StockWindow::setCurrentTab(int index)
{
    idInstrument_=-1;
    addIntruments->setCurrentTab(index);
    editInstruments->setCurrentTab(index);
    currentTab_=index;
}

void StockWindow::editNameClassInstrument(int index)
{
    if (!index)
        return;

    bool ok;
    QFont  font;
    QString nameClass;
    font.setPointSize(11);
    QApplication::setFont(font);

    QInputDialog inputDialog(this);

    nameClass=inputDialog.getText(this, tr("Изменить название группы материалов"),
                        tr("Введите название группы материалов:"), QLineEdit::Normal,
                        getNameClassIntrument(index), &ok);


    if (!ok) {
        return;
        // Была нажата кнопка Cancel
    }

    //Переименовать группу материалов
    int idClassInstrument;
    QString queryStr;

    ui->tabWidget->setTabText(index,nameClass);
    idClassInstrument=mapTab.value(index);
    queryStr=QString("update ClassInstruments\
    set NameClass = '%1'  where ID=%2").arg(nameClass).arg(idClassInstrument);
    dataBase.queryToBase(queryStr);

    updateWindows();


}

void StockWindow::editNameInstrument()
{
    if(idInstrument_==-1){
        QMessageBox::information(NULL,"Подсказка", "Выберите материал для редактирования.");
        return;
    }


    editInstruments->showEditInstrumentWindow();
    updateWindows();
}

void StockWindow::addClassIntruments(QString nameClassInstruments)
{
    QString queryStr= QString("INSERT INTO ClassInstruments (NameClass) SELECT '%1'").arg(nameClassInstruments);
    QSqlQuery query=dataBase.queryToBase(queryStr);
    //Получаем последний ID
    queryStr="SELECT @@Identity";
    query=dataBase.queryToBase(queryStr);
    query.first();
    int idClassInstrument=query.value(0).toInt();

    this->setupModelBaseID(                   QStringList() << trUtf8("ID")
                                              << trUtf8("Класс")
                                              << trUtf8("Название")
                                              << trUtf8("Остаток")
                                              ,idClassInstrument);
    this->createUIClassInstruments();
    //Перезапись комбо
    addIntruments->fillClassInstruments();
}

void StockWindow::setupModelBaseID(const QStringList &headers, int idClassInstruments)
{
    QString query;
    if(idClassInstruments!=1){

        query=QString("SELECT Instruments.id, ClassInstruments.NameClass,\
                      Instruments.nameInstruments, Instruments.balance\
                      FROM ClassInstruments INNER JOIN Instruments \
                      ON ClassInstruments.ID = Instruments.idClassInstruments \
                where  Instruments.id>0 and  Instruments.idClassInstruments=%1\
                GROUP BY Instruments.id, ClassInstruments.NameClass,\
                      Instruments.nameInstruments, Instruments.balance;").arg(idClassInstruments);;
    }
    else{
        query=QString("SELECT Instruments.id,ClassInstruments.NameClass, \
                      Instruments.nameInstruments, Count(Instruments.id) AS [Count-id], \
                Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
                FROM ClassInstruments INNER JOIN (ClientsCard INNER JOIN Instruments \
                                                         ON ClientsCard.id_instruments = Instruments.id) ON ClassInstruments.ID = Instruments.idClassInstruments\
                where Instruments.id >0 and  Instruments.idClassInstruments=%1\
                GROUP BY Instruments.id, ClassInstruments.NameClass,  \
                Instruments.nameInstruments, Instruments.balance;").arg(idClassInstruments);
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
    QString queryStr="SELECT ClassInstruments.ID,ClassInstruments.NameClass \
            FROM ClassInstruments where ClassInstruments.ID>0 ;";
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


void StockWindow:: setupModelBase(const QStringList &headers)
{

    mainQuery=QString("SELECT Instruments.id, ClassInstruments.NameClass,\
                      Instruments.nameInstruments, Instruments.balance\
                      FROM ClassInstruments INNER JOIN Instruments \
                      ON ClassInstruments.ID = Instruments.idClassInstruments where  Instruments.id>0\
            GROUP BY Instruments.id, ClassInstruments.NameClass,\
                      Instruments.nameInstruments, Instruments.balance;");

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
    QString query=QString("SELECT Instruments.id,ClassInstruments.NameClass, \
                          Instruments.nameInstruments, Count(Instruments.id) AS [Count-id], \
            Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
            FROM ClassInstruments INNER JOIN (ClientsCard INNER JOIN Instruments \
                                                     ON ClientsCard.id_instruments = Instruments.id) ON ClassInstruments.ID = Instruments.idClassInstruments\
            where Instruments.id >0 and  Instruments.idClassInstruments=%1\
            GROUP BY Instruments.id, ClassInstruments.NameClass,  \
            Instruments.nameInstruments, Instruments.balance;").arg(idClassInstruments);
    vecQueryTab.push_back(query);

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
    idInstrument_=indexID.model()->data(indexID, Qt::DisplayRole).toInt();
    editInstruments->setIdInstrument(idInstrument_);
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


    queryStr=QString("SELECT MovementInstruments.dateOperation, Instruments.nameInstruments, \
                     MovementInstruments.typeOperation, MovementInstruments.countInstr,MovementInstruments.source,\
                     MovementInstruments.notes  FROM MovementInstruments INNER JOIN Instruments ON\
                     (MovementInstruments.idInstruments = Instruments.id) \
                     AND (MovementInstruments.idInstruments = Instruments.id) where  \
                     MovementInstruments.idInstruments=%1  ORDER BY MovementInstruments.dateOperation DESC ").arg(idInstrument_);
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
        QString query=vecQueryModelTab[i]->query().lastQuery();
        qDebug()<< query;
        vecQueryModelTab[i]->setQuery(query);
    }

    showHistory();
}






void StockWindow::showConfirmDelete(int index)
{
    QString nameClass=getNameClassIntrument(index);

    QMessageBox mb(QString("Подтверждение удаления"),
                   QString("Вы уверены, что хотите удалить группу материалов \"%1\"? Действия отменить будет невозможно.").arg(nameClass),
                   QMessageBox::Warning,
                   QMessageBox::Yes,
                   QMessageBox::No | QMessageBox::Default | QMessageBox::Escape ,
                   QMessageBox::NoButton );
    //Переименовать названия кнопок на русский язык
    mb.setButtonText(QMessageBox::Yes, tr("Да"));
    mb.setButtonText(QMessageBox::No, tr("Отмена"));

    //Если нажата кнопку Да
    if( mb.exec() == QMessageBox::Yes ){

        int idClassInstruments= mapTab.value(currentTab_);
        //Удалить группу материалов из БД и связанные с ней записи
        deleteClassInstruments(idClassInstruments);
        //Удалить вкладку
        ui->tabWidget->removeTab(currentTab_);
        //Перезаписать комбобох с группами материалов
        addIntruments->fillClassInstruments();
        //Обновить вкладки
        updateWindows();
        //Заполнить словарь
        insertMapTab();
        //Изменить текушую вкладку
        ui->tabWidget->setCurrentIndex(0);
    }

}

void StockWindow::setMapTab()
{
    addIntruments->setMapTab(mapTab);
}

void StockWindow::deleteClassInstruments(int index)
{
    QString queryStr;
    QSqlQuery  querySql;

    //Получить список инструментов относящихся к удаляемой группе
    queryStr=QString("SELECT Instruments.* FROM Instruments\
                     WHERE (((Instruments.idClassInstruments)=%1))").arg(index);
    dataBase.queryToBase(queryStr);

   //Удаляем записи с ID инструмента, относящегося к удаляемой группе
    while (querySql.next()) {
            queryStr=QString("DELETE MovementInstruments.* FROM MovementInstruments\
            WHERE (((MovementInstruments.idInstruments)=%1))").arg(querySql.value(0).toInt());

    }

    //Удаляем список инструментов, относящихся к удаляемой группе
    queryStr=QString("DELETE Instruments.*FROM Instruments\
                     WHERE (((Instruments.idClassInstruments)=%1))").arg(index);
    dataBase.queryToBase(queryStr);

    //Удаляем группу иструментов
    queryStr=QString("DELETE ClassInstruments.*\
                     FROM ClassInstruments\
                     WHERE (((ClassInstruments.ID)=%1))").arg(index);
    dataBase.queryToBase(queryStr);

}

void StockWindow::deleteInstrument()
{
    if(idInstrument_==-1){
        QMessageBox::information(NULL,"Подсказка", "Выберите материал для удаления.");
        return;
    }

    QMessageBox mb(QString("Подтверждение удаления"),
                   QString("Вы уверены, что хотите удалить выбранный материал \"%1\"? Действия отменить будет невозможно.").arg(getNameInstrument()),
                   QMessageBox::Warning,
                   QMessageBox::Yes,
                   QMessageBox::No | QMessageBox::Default | QMessageBox::Escape ,
                   QMessageBox::NoButton );
    //Переименовать названия кнопок на русский язык
    mb.setButtonText(QMessageBox::Yes, tr("Да"));
    mb.setButtonText(QMessageBox::No, tr("Отмена"));

    //Если нажата кнопку Да
    if( mb.exec() == QMessageBox::Yes ){
        QString queryStr;
        queryStr=QString("DELETE Instruments.*FROM Instruments\
                         WHERE (((Instruments.id)=%1))").arg(idInstrument_);
        dataBase.queryToBase(queryStr);

        updateWindows();
    }

}


void StockWindow::insertMapTab()
{
    mapTab.clear();
    QString queryStr="SELECT ClassInstruments.ID,ClassInstruments.NameClass \
            FROM ClassInstruments where ClassInstruments.ID>0 ;";
    QSqlQuery query=dataBase.queryToBase(queryStr);
    int i=1;
    while(query.next()&& i<=ui->tabWidget->count()+1) {
        mapTab.insert(i,query.value(0).toInt());
        i++;
    }
}


QString StockWindow::getNameClassIntrument(int index)
{
    int idClassInstrument;
    QString queryStr;
    QSqlQuery query;
    QString nameClassInstr;


    idClassInstrument=mapTab.value(index);
    queryStr=QString("SELECT ClassInstruments.*\
            FROM ClassInstruments\
            WHERE (((ClassInstruments.ID)=%1));").arg(idClassInstrument);
    query=dataBase.queryToBase(queryStr);
    query.first();
    nameClassInstr=query.value(1).toString();

    return nameClassInstr;
}

QString StockWindow::getNameInstrument()
{
    QString queryStr;
    QSqlQuery query;
    QString nameInstr;

    queryStr=QString("SELECT Instruments.*\
            FROM Instruments\
            WHERE (((Instruments.id)=%1));").arg(idInstrument_);
    query=dataBase.queryToBase(queryStr);
    query.first();
    nameInstr=query.value(2).toString();

    return nameInstr;
}


void StockWindow::showEditBalanceWindows()
{
    if(idInstrument_==-1){
        QMessageBox::information(NULL,"Подсказка", "Выберите материал для редактирования остатка.");
        return;
    }
    editInstruments->showEditBalanseWindow();
}

void StockWindow::showReCoutInstruments(int index)
{
    if(index==1)
        ui->groupBox_3->show();
    else
        ui->groupBox_3->hide();
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

        modelMain->setQuery( QString("SELECT Instruments.id, Instruments.nameInstruments, Count(Instruments.id) \
                                     AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
                FROM ClientsCard INNER JOIN Instruments ON ClientsCard.id_instruments = Instruments.id\
                WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))\
                GROUP BY Instruments.id, Instruments.nameInstruments, Instruments.balance;")
        .arg(dateTodayBackStr).arg(dateTodayStr), dataBase.getDatase());

    modelMain->setQuery(modelMain->query().lastQuery());
    qDebug() << modelMain->query().lastError().text();
}

void StockWindow::clickSumButton()
{
    QString dateTodayStr= ui->dataEnddateEdit->text().replace(".","/");
    QString dateTodayBackStr= ui->dataBegindateEdit->text().replace(".","/");

    QString query;

        query= QString("SELECT Instruments.id, Instruments.nameInstruments, Count(Instruments.id) \
                       AS [Count-id], Sum(ClientsCard.dept) AS [Sum-dept], Instruments.balance\
                FROM ClientsCard INNER JOIN Instruments ON ClientsCard.id_instruments = Instruments.id\
                WHERE (((ClientsCard.dataEnd) Between #%1# and  #%2#))\
                GROUP BY Instruments.id, Instruments.nameInstruments, Instruments.balance;")
        .arg(dateTodayBackStr).arg(dateTodayStr);


}
