    #ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include "QtSql"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#include <QMessageBox>

/* Директивы имен таблицы, полей таблицы и базы данных */

#define DATABASE_NAME       "DatabaseWell.mdb"

#define CLIENT_CARD_TABLE       "ClientsCard "
#define DISTRICT_TABLE          "District "
#define REGION_TABLE            "Region "
#define DIAMETER_TABLE          "Diameter "
#define INSERT_INTO             "Insert into "
#define UPDATE                  "Update "
#define SELECT                  "Select "


#define CLIENT_CARD_SURNAME     "surname "
#define CLIENT_CARD_NAME        "name_ "
#define CLIENT_CARD_PATRONYMIC  "patronymic "
#define CLIENT_CARD_HOME_PHONE  "homePhone "
#define CLIENT_CARD_MOBIL_PHONE "mobilPhone "
#define CLIENT_CARD_OTHER_PHONE "otherPhone "
#define CLIENT_CARD_ID_DISTRICT "id_district "
#define CLIENT_CARD_LOCALITY    "locality "
#define CLIENT_CARD_STREET      "street "
#define CLIENT_CARD_DEPT        "dept "
#define CLIENT_CARD_ID_DIAMETER "id_diameter "
#define CLIENT_CARD_PUMP        "pump "
#define CLIENT_CARD_SERVISE     "service "
#define CLIENT_CARD_DATA_BEGIN  "dataBegin "
#define CLIENT_CARD_DATA_END    "dataEnd "
#define CLIENT_CARD_NOTES       "notes "



//Вставить относительные пути к БД
#define ACCESS  "DRIVER={Microsoft Access Driver (*.mdb)};"\
    "FIL={MS Access};DBQ=C:\\Users\\pol\\Documents\\DatabaseWell.mdb"

#define ACCESS_SHORT  "DRIVER={Microsoft Access Driver (*.mdb)};"\
    "FIL={MS Access};DBQ="

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);

    ~DataBase();

    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    void connectToDataBase();

    void closeDataBase();
    QSqlQuery getQueryRegion();
    QSqlQuery getQueryDistrict_FULL();
    QSqlQuery getQueryDistrict(int id_Region);
    QSqlQuery getQueryDiameter();

    QSqlDatabase getDatase();
    void setFileName(QString name);



    QSqlQuery queryToBase(QString queryText);
private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;

    QSqlQuery query;
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase();
    /*
    Формирование текстовой строки запроса к БД
    */
    QString getLastExecutedQuery(const QSqlQuery &query);
    bool restoreDataBase();



    QString fileName;

signals:

public slots:


};

#endif // DATABASE_H
