#ifndef DIAMETER_H
#define DIAMETER_H

#include <QMainWindow>
#include "QSqlQueryModel"
#include "editinstrumentsdialog.h"
#include "operationstock.h"

namespace Ui {
class diameter;
}

class diameter : public QMainWindow
{
    Q_OBJECT

public:
    explicit diameter(QWidget *parent = 0);
    ~diameter();

    void createUI();
    void setupModel(const QStringList &headers);
    void fillDate();

public slots:
    void parsingIdInstr(QModelIndex index);
    void showHistory();
    void updateWindows();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_clearButtton_clicked();


private:
    Ui::diameter *ui;
    QSqlQueryModel    *model;
    EditInstrumentsDialog *editInstruments;
    OperationStock * operationStock;

    int idDiameter_;
};

#endif // DIAMETER_H
