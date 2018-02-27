#ifndef DATACLIENT_H
#define DATACLIENT_H

#include <QMainWindow>
#include "global.h"
#include "DataBase/database.h"
#include "clientscardwindows.h"
#include "Model/heirqsqlquerymodel.h"

#include "cardclientwindows.h"


class clientsCardWindows;
namespace Ui {
class dataClient;
class clientsCardWindows;
}


class dataClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit dataClient(QWidget *parent = 0);
    ~dataClient();

    void setupModel(const QStringList &headers);
    void createUI();

    int parsingLocation();
    void fillDiameter();
    void fillDistrict_FULL();
    QString filterLocation();
    QString filterDiameter();
    QString filterPump();
    QString filterService();
    int parsingPersonale();
    QString filterPersonale();
    personale fillDataClient(int ID_DataClient);
private slots:
    void fillRegion();
    void fillDistrict();


    void on_closeButton_clicked();
    void on_filterButton_clicked();
    void on_clearFilterButton_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::dataClient *ui;
    HeirQSqlQueryModel    *model;



};

#endif // DATACLIENT_H
