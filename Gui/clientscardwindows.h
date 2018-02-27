#ifndef CLIENTSCARDWINDOWS_H
#define CLIENTSCARDWINDOWS_H

#include <QMainWindow>
#include "global.h"

namespace Ui {
class clientsCardWindows;
}


/*struct personale{
    QString surname;
    QString name;
    QString patronymic;
    QString phone;
    int id_region;
    int id_district;
    QString locality;
    QString street;
    QString dept;
    int id_diameter;
    bool pump;
    bool service;
    QDateTime dataBegin;
    QDateTime dataEnd;
    QString note;
   // QString phone;
};*/

class clientsCardWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientsCardWindows(QWidget *parent = 0);
    ~clientsCardWindows();

    void fillRegion();
    //void fillClientCart(personale pers);
    void fillDiameter();
    void fillDate();
    void fillDistrict_FULL();
    //Ui::clientsCardWindows *getUIClientsCardWindows();

    void setStateSave(bool state);

    void setIdClient(int id);
    void createNewClient();
    void updateClient();
    void createServiceClient(int idClient);
private slots:
   void fillDistrict();

   void on_closeButton_clicked();

   void on_pushButton_clicked();

   void on_dataBeginCheckBox_clicked();

   void on_dataEndCheckBox_clicked();

private:

   /**
    Хранит состояние работы кнопки сохранить
    \param true   Сохранить нового клиента
    \param false  Сохранить отредактированного клиента
   */
   bool stateSave;
   int id_client;

   Ui::clientsCardWindows *ui;
};

#endif // CLIENTSCARDWINDOWS_H
