#ifndef ADDINSTRUMENTS_H
#define ADDINSTRUMENTS_H

#include <QWidget>
#include <QSqlQuery>

#include "global.h"

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

    void  setCurrentTab(int currentTab);

signals:
    void closeSignal();

public slots:
    void showWindow();
    void addNewInstr();
private:
    Ui::AddInstruments *ui;

    int currentTab_; //хранит выбранную текущую вкладку
};

#endif // ADDINSTRUMENTS_H
