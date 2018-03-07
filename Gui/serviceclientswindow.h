#ifndef SERVICECLIENTSWINDOW_H
#define SERVICECLIENTSWINDOW_H

#include <QMainWindow>

#include "cardservicewindows.h"

namespace Ui {
class ServiceClientsWindow;
}

class ServiceClientsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServiceClientsWindow(QWidget *parent = 0);
    ~ServiceClientsWindow();

    /**    Настройка и создание модели данных    */
    void createUI();
    void setupModel(const QStringList &headers);


    /**    Заполнение данными   */
    personaleService fillDataService(int idClient);
    void fillRegion();
    void fillDistrict();
    void fillDistrict_FULL();
    void fillStateService();
    void fillStatePayment();
    void fillTypePump();
    void fillStatePump();
    void fillLocationPump();
    void fillSeasone();

   /**  Парсинг исходя из выбранных фильтров */
    int parsingLocation();
    int parsingPersonale();


    /** Фильтрация по выбранным критериям*/
    QString filterLocation();
    QString filterStateService();
    QString filterPersonale();
    QString filterStatePayment();
    QString filterTypeInstr();
    QString filterStateInstr();
    QString filterLocationInstr();
    QString filterSeasone();


    QString filterOtherPhone();

public slots:
    void clickFilter();
    void clickClear();
    void doubleClickTable(const QModelIndex &index);
    void updateModel();
    void showWindow();
private:
    Ui::ServiceClientsWindow *ui;
    CardServiceWindows  *cardServiceWindows;

    QSqlQueryModel    *model;

    QString mainQuery; //хранит основной запрос окна

    bool isStateService_;
    bool isStatePayment_;
    bool isTypeInstr_;
    bool isStateInstr_;
    bool isLocationInstr_;
    bool isSeasone_;
};

#endif // SERVICECLIENTSWINDOW_H
