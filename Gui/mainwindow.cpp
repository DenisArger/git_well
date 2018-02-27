#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clientscardwindows.h"
#include "dataclient.h"
#include "global.h"

#include "diameter.h"
#include "service.h"
#include "QDesktopWidget"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QDesktopWidget *d = QApplication::desktop();
    gWidth = d->width();     // returns desktop width
    gHeight = d->height();    // returns desktop height


    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint |  Qt::WindowMaximizeButtonHint|\
                         Qt::WindowCloseButtonHint);


    this->setMinimumSize(gWidth*0.70,gHeight*0.45);
    this->setMaximumSize(gWidth*0.70,gHeight*0.45);
    //this->resize(gWidth * PERCENT_OF_SCREEN_WIDTH, gHeight * PERCENT_OF_SCREEN_HEIGHT);

    connect(ui->newOrderButton, SIGNAL(clicked()), this, SLOT(clickNewOrderButton()));
    connect(ui->diameterButton, SIGNAL(clicked()), this, SLOT(clickDiameterButton()));
    connect(ui->clientCardButton, SIGNAL(clicked()), this, SLOT(clickClientCardButton()));

    //dataBase.connectToDataBase();
}

MainWindow::~MainWindow()
{
    delete ui;
}






MainWindow::clickNewOrderButton()
{
    /*clientsCardWindows  *w=new clientsCardWindows(this);
    w->show();*/

}

MainWindow::clickDiameterButton()
{

}

MainWindow::clickClientCardButton()
{
    dataClient  *w=new dataClient(this);
    w->show();

}

void MainWindow::on_pushButton_clicked()
{
    QString name= ui->lineEdit->text();
    dataBase.setFileName(name);
}

void MainWindow::on_diameterButton_clicked()
{
    diameter  *w=new diameter(this);
    w->show();
}

void MainWindow::on_serviceClientsButtton_clicked()
{
    service  *w=new service(this);
    w->show();
}
