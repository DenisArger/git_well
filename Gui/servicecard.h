#ifndef SERVICECARD_H
#define SERVICECARD_H

#include <QMainWindow>
#include "QDateTime"
#include "global.h"
#include "Model/servicecardquerymodel.h"

namespace Ui {
class servicecard;
}


/*struct personaleService{
    QString surname;
    QString name;
    QString patronymic;
    QString phone;
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
 };*/

class servicecard : public QMainWindow
{
    Q_OBJECT

public:
    explicit servicecard(QWidget *parent = 0);
    ~servicecard();

    void setIdClient(int ID);

    void setIdService(int ID);

    //void fillServiceCart(personaleService pers);

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
    void createUI();
    void setupModel(const QStringList &headers);
private slots:

    void fillDistrict();
    void on_pushButton_clicked();

    void on_closeButton_clicked();

    void on_typePumpCombo_currentIndexChanged(int index);

private:

    QDateTime dataService;
    int id_client;
    int id_service;
    Ui::servicecard *ui;

    ServiceCardQueryModel    *model;
};

#endif // SERVICECARD_H
