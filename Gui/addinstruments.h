#ifndef ADDINSTRUMENTS_H
#define ADDINSTRUMENTS_H

#include <QWidget>
#include <QSqlQuery>

#include "global.h"
#include <QMap>

namespace Ui {
class AddInstruments;
}

class AddInstruments : public QWidget
{
    Q_OBJECT

public:
    explicit AddInstruments(QWidget *parent = 0);
    ~AddInstruments();

    void closeEvent(QCloseEvent *event);

    void fillClassInstruments();

    void setCurrentTab(int currentTab);


    void clearForm();
signals:
    void closeSignal();

public slots:
    void setMapTab(QMap<int,int> mapTab);
    void showWindow();
    void addNewInstr();
private:
    Ui::AddInstruments *ui;

    QMap<int,int> mapCombo_; // хранит соответсвие комбо и ID групп материалов
    QMap<int,int> mapTab_; // хранит соответсвие владок и ID групп материалов
    int currentTab_; //хранит выбранную текущую вкладку
};

#endif // ADDINSTRUMENTS_H
