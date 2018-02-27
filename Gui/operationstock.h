#ifndef OPERATIONSTOCK_H
#define OPERATIONSTOCK_H

#include <QWidget>

namespace Ui {
class OperationStock;
}

class OperationStock : public QWidget
{
    Q_OBJECT

public:
    explicit OperationStock(QWidget *parent = 0);
    ~OperationStock();

    void closeEvent(QCloseEvent *event);

signals:
    void closeSignal();

public slots:
    void addNewInstr();
private:
    Ui::OperationStock *ui;
};

#endif // OPERATIONSTOCK_H
