#ifndef PRIMEWINDOW_H
#define PRIMEWINDOW_H

#include <QMainWindow>
#include <QShortcut>

#include "Gui/clientswindows.h"
#include "Gui/cardclientwindows.h"
#include "Gui/serviceclientswindow.h"
#include "Gui/stockwindow.h"

namespace Ui {
class PrimeWindow;
}

class PrimeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PrimeWindow(QWidget *parent = 0);
    ~PrimeWindow();



private:
    Ui::PrimeWindow *ui;
    ClientsWindows *clientsWindows;
    CardClientWindows *cardWindows;
    ServiceClientsWindow *serviceClientWindows;
    StockWindow *stockWindows;

    QShortcut       *keyF5;    // объект горячей клавиши F5
    QShortcut       *keyF6;    // объект горячей клавиши F6
    QShortcut       *keyF7;    // объект горячей клавиши F7
    QShortcut       *keyF8;    // объект горячей клавиши F8
};

#endif // PRIMEWINDOW_H
