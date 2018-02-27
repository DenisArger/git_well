#ifndef SERVICE_H
#define SERVICE_H

#include <QMainWindow>
#include "Model/serviceqsqlquerymodel.h"
#include "servicecard.h"

namespace Ui {
class service;
}

class service : public QMainWindow
{
    Q_OBJECT

public:
    explicit service(QWidget *parent = 0);
    ~service();

    void createUI();
    void setupModel(const QStringList &headers);
    //personaleService fillDataService(int idClient);
    void fillRegion();
    void fillDistrict();
    void fillDistrict_FULL();
    void fillStateService();
    void fillStatePayment();
    void fillTypePump();
    void fillStatePump();
    void fillLocationPump();
    void fillSeasone();

    QString filterLocation();
    QString filterStateService();
    int parsingLocation();
    QString filterPersonale();
    int parsingPersonale();
    QString filterStatePayment();
    QString filterTypeInstr();
    QString filterStateInstr();
    QString filterLocationInstr();
    QString filterSeasone();
public slots:
    void clickFilter();
    void clickClear();
private slots:
    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::service *ui;
    QSqlQueryModel    *model;

    bool isStateService_;
    bool isStatePayment_;
    bool isTypeInstr_;
    bool isStateInstr_;
    bool isLocationInstr_;
    bool isSeasone_;

};

#endif // SERVICE_H
