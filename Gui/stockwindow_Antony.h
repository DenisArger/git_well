#ifndef STOCKWINDOW_ANTONY_H
#define STOCKWINDOW_ANTONY_H

#include <QMainWindow>
#include "QSqlQueryModel"
#include "editinstrumentsdialog.h"
#include "addinstruments.h"


#include <vector>
using namespace std;
namespace Ui {
class StockWindow;
}

class StockWindow_Antony : public QMainWindow
{
    Q_OBJECT

public:
    explicit StockWindow_Antony(QWidget *parent = 0);
    ~StockWindow_Antony();
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
    void setCurrentTab(int index);

    void showWindow();
private:
    Ui::StockWindow *ui;

    QSqlQueryModel *modelTemp; //временная модель данных
    QSqlQueryModel    *modelMain;// модель данных  вкладки Все
    EditInstrumentsDialog *editInstruments;
    AddInstruments * addIntruments;

    vector<QTabWidget*>vecTabWidget;

    QString mainQuery; //запрос  вкладки Все
    vector<QString>vecQueryTab; //запросы остальных вкладок
    vector<QSqlQueryModel *> vecQueryModelTab; //модели остальных вкладок

    int idDiameter_;
};

#endif // STOCKWINDOW_ANTONY_H
