#ifndef CARDSERVICEWINDOWS_H
#define CARDSERVICEWINDOWS_H

#include <QMainWindow>
#include "QDateTime"
#include "global.h"
#include "Model/servicecardquerymodel.h"

namespace Ui {
class CardServiceWindows;
}

struct personaleService{
    QString surname;
    QString name;
    QString patronymic;
    QString phone;
    QString otherPhone;
    int id_region;
    int id_district;
    QString locality;
    QString street;
    int id_stateService;
    QDateTime dataBeginService;
    int id_statePayment;
    int id_typePump;
    int id_statePump;
    int id_locationPump;
    int id_seasone;

    QString dataBeginServiceStr;
    QDateTime dataNextService;
    QString note;
 };
class CardServiceWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit CardServiceWindows(QWidget *parent = 0);
    ~CardServiceWindows();
    /** Создание и настройка модели данных*/
    void createUI();
    void setupModel(const QStringList &headers);

    void setIdClient(int ID);
    void setIdService(int ID);

    void fillServiceCart(personaleService pers);
    void fillStateService();
    void fillStatePayment();
    void fillTypePump();
    void fillStatePump();
    void fillLocationPump();
    void fillSeasone();
    void fillDistrict_FULL();
    void fillRegion();

    void createNextDataService(int index);
    void updateServiceCard();

signals:
    void closeEvent(QCloseEvent *event);

public slots:
     void fillDistrict();
     void clickSaveButton();
     void changedCurrtentUndex(int index);
     void showWindow();


private:
    Ui::CardServiceWindows *ui;

    QDateTime dataService;
    int id_client;
    int id_service;
    ServiceCardQueryModel    *model;
};

#endif // CARDSERVICEWINDOWS_H
