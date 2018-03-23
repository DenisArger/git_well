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
    //Добвление записей в мар
    void insertMapTab();
    QString getNameClassIntrument(int index);
    QString getNameInstrument();
public slots:
    void parsingIdInstr(QModelIndex index);
    void showHistory();
    void updateWindows();
    void clickClearButton();
    void clickSumButton();

    void deleteClassInstruments(int index);
    void deleteInstrument();
    void addTab();
    void setCurrentTab(int index);

    void showWindow();
    void showReCoutInstruments(int index);
    void editNameClassInstrument(int index);
    void editNameInstrument();

    void showConfirmDelete(int index);
    void setMapTab();
    void showEditBalanceWindows();
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

    QMap<int,int> mapTab; // информацию о номере владки и ID группы материалов
    int currentTab_; //Хранит текущую выбранную вкладку
    int idInstrument_; //ИД выбранного прибора
};

#endif // STOCKWINDOW_H
