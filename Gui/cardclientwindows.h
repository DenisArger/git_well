#ifndef CARDCLIENTWINDOWS_H
#define CARDCLIENTWINDOWS_H

#include <QMainWindow>
#include "global.h"
#include <QCompleter>



namespace Ui {
class CardClientWindows;
}


struct personale{
    QString surname;
    QString name;
    QString patronymic;
    QString phone;
    QString otherPhone;
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
};

class CardClientWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit CardClientWindows(QWidget *parent = 0);
    ~CardClientWindows();

    /**
    Заполнение комбобоксов данными
    */
    void fillRegion();
    void fillClientCart(personale pers);
    void fillDiameter();
    void fillDate();
    void fillDistrict_FULL();

    /**
    Установка типа сохранения данных
    \param false Обновление данных
    \param true  Сохрание новых данных
    */
    void setStateSave(bool state);

    void createNewClient();
    void updateClient();

    void setIdClient(int id);
    void createServiceClient(int idClient);
    void closeEvent(QCloseEvent *event);

    void deleteServiceClient(int idClient);
 public slots:
    void fillDistrict();

    void clickSaveButton();
    void clickDataBeginCheckBox();
    void clickDataEndCheckBox();
    void defaultContenWindow();
    void showWindow();


signals:
    void closeSignal();
private:
    /**
     Хранит состояние работы кнопки сохранить
     \param true   Сохранить нового клиента
     \param false  Сохранить отредактированного клиента
    */
    bool stateSave;
    int id_client;
    Ui::CardClientWindows *ui;
};

#endif // CARDCLIENTWINDOWS_H
