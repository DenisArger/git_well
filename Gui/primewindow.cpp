#include "primewindow.h"
#include "ui_primewindow.h"

PrimeWindow::PrimeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PrimeWindow)
{
    ui->setupUi(this);

    //Скрывает строку настройки БД
    ui->label->hide();
    ui->lineEdit->hide();
    ui->pushButton->hide();

    clientsWindows = new ClientsWindows;
    cardWindows = new CardClientWindows;
    serviceClientWindows = new ServiceClientsWindow;
    stockWindows = new StockWindow;

    keyF5 = new QShortcut(this);   // Инициализируем объект
    keyF6 = new QShortcut(this);   // Инициализируем объект
    keyF7 = new QShortcut(this);   // Инициализируем объект
    keyF8 = new QShortcut(this);   // Инициализируем объект

    keyF5->setKey(Qt::Key_F5);    // Устанавливаем код клавиши
    keyF6->setKey(Qt::Key_F6);    // Устанавливаем код клавиши
    keyF7->setKey(Qt::Key_F7);    // Устанавливаем код клавиши
    keyF8->setKey(Qt::Key_F8);    // Устанавливаем код клавиши



    /*showMaximized - открывать окно развернуто*/
    connect(ui->clientsBaseButton,SIGNAL(clicked(bool)),clientsWindows,SLOT(showWindow()));
    connect(ui->newOrderButton,SIGNAL(clicked(bool)),cardWindows,SLOT(showWindow()));
    connect(ui->serviceClientsButtton,SIGNAL(clicked(bool)),serviceClientWindows,SLOT(showWindow()));
    connect(ui->stockButton,SIGNAL(clicked(bool)),stockWindows,SLOT(showWindow()));


    connect(keyF5, SIGNAL(activated()), cardWindows,SLOT(showWindow()));
    connect(keyF6, SIGNAL(activated()), stockWindows,SLOT(showWindow()));
    connect(keyF7, SIGNAL(activated()), clientsWindows,SLOT(showWindow()));
    connect(keyF8, SIGNAL(activated()), serviceClientWindows,SLOT(showWindow()));


 }

PrimeWindow::~PrimeWindow()
{
    delete ui;
}
