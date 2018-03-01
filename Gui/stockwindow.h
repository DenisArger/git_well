#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QMainWindow>
#include "QSqlQueryModel"
#include "editinstrumentsdialog.h"
#include "addinstruments.h"


#include <vector>
using namespace std;
namespace Ui {
class StockWindow;
}

class StockWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StockWindow(QWidget *parent = 0);
    ~StockWindow();
    void createUI();
    void setupModel(const QStringList &headers);
    void fillDate();

    void insertTabClassInstruments();
    void createUIClassInstruments();
    void setupModelClassInstruments(const QStringList &headers, int idClassInstruments);
    void addClassIntruments(QString nameClassInstruments);

    //Установка модели для всех приборов
    void setupModelBase(const QStringList &headers);
    //Установка модели для всех прибора согласно ID прибора
    void setupModelBaseID(const QStringList &headers, int idClassInstruments);

public slots:
    void parsingIdInstr(QModelIndex index);
    void showHistory();
    void updateWindows();
    void clickClearButton();
    void clickSumButton();
    void clickCurrBalanceButton();
    void clickAdd();
    void clickEdit();
    void clickDelete();
    void clickAddInstruments();

    void addTab();

private:
    Ui::StockWindow *ui;

    QSqlQueryModel    *model;
    EditInstrumentsDialog *editInstruments;
    AddInstruments * addIntruments;

    vector<QTabWidget*>vecTabWidget;

    int idDiameter_;
};

#endif // STOCKWINDOW_H
