#ifndef CLIENTSWINDOWS_H
#define CLIENTSWINDOWS_H

#include <QMainWindow>

#include "global.h"
#include "DataBase/database.h"
#include "Model/heirqsqlquerymodel.h"

#include "cardclientwindows.h"



namespace Ui {
class ClientsWindows;
}

class ClientsWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientsWindows(QWidget *parent = 0);
    ~ClientsWindows();

    /**
    Создание и настройка модели данных
    */
    void setupModel(const QStringList &headers);
    void createUI();

    /** Заполнение комбобоксов*/
    void fillDiameter();
    void fillDistrict_FULL();

    personale fillDataClient(int ID_DataClient);

    /** Доступные фильтры в МД*/
    QString filterLocation();
    QString filterDiameter();
    QString filterPump();
    QString filterService();
    QString filterPersonale();

    /** Парсинг выбраных параметров фильтрации */
    int parsingLocation();
    int parsingPersonale();

    QString filterOtherPhone();
public slots:
    void fillRegion();
    void fillDistrict();

    void clickFilterButton();
    void clickClearFilterButton();
    void clickDoubleClickedTable(QModelIndex index);

    void showWindow();
    void updateModel();
private:
    Ui::ClientsWindows *ui;
    HeirQSqlQueryModel    *model;
    CardClientWindows  *cardClientWindows;
    QString mainQuery; //хранит основной запрос окна

    QMap<int,int> mapComboGegion_; // хранит соответсвие комбо и ID областей
    QMap<int,int> mapComboDistrict_; // хранит соответсвие комбо и ID районов
    QMap<int,int> mapComboInstrument_; // хранит соответсвие комбо и ID инструментов
};

#endif // CLIENTSWINDOWS_H
