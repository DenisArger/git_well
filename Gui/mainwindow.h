#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QtSQl/QSqlRelationalTableModel"
#include "QtSql/QSqlTableModel"
#include "QtSql/QSqlError"
#include "QMessageBox"


#include "DataBase/database.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    /**Формирует модель TableView*/
    void setupModel(const QString &tableName, const QStringList &headers);
    /**Фомирует внешний вид TableView*/
    void createUI();

private:
    Ui::MainWindow *ui;



    /*Ообъект для взаимодействия с информацией в базе данных
    * и моделью представления таблицы базы данных
     * */
    DataBase    *db;
    /* Объект c моделью представления таблицы базы данных
            * */
    QSqlRelationalTableModel    *model;


    QSqlTableModel *m_model;
    QSqlDatabase mDatabase;

public slots:
    clickNewOrderButton();
    clickDiameterButton();
    clickClientCardButton();

private slots:
    void on_pushButton_clicked();
    void on_clientCardButton_clicked();
    void on_diameterButton_clicked();
    void on_serviceClientsButtton_clicked();
};

#endif // MAINWINDOW_H
