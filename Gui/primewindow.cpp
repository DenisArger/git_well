#include "primewindow.h"
#include "ui_primewindow.h"

PrimeWindow::PrimeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PrimeWindow)
{
    ui->setupUi(this);

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
    connect(ui->clientsBaseButton,SIGNAL(clicked(bool)),clientsWindows,SLOT(showMaximized()));
    connect(ui->newOrderButton,SIGNAL(clicked(bool)),cardWindows,SLOT(show()));
    connect(ui->serviceClientsButtton,SIGNAL(clicked(bool)),serviceClientWindows,SLOT(showMaximized()));
    connect(ui->stockButton,SIGNAL(clicked(bool)),stockWindows,SLOT(showMaximized()));


    connect(keyF5, SIGNAL(activated()), cardWindows,SLOT(show()));
    connect(keyF6, SIGNAL(activated()), stockWindows,SLOT(show()));
    connect(keyF7, SIGNAL(activated()), clientsWindows,SLOT(showMaximized()));
    connect(keyF8, SIGNAL(activated()), serviceClientWindows,SLOT(showMaximized()));


 }

PrimeWindow::~PrimeWindow()
{
    delete ui;
}
