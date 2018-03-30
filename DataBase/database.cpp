#include "database.h"
#include <QMessageBox>

DataBase::DataBase(QObject *parent) : QObject(parent),fileName(" ")
{

}

DataBase::~DataBase()
{

}

bool DataBase::connectToDataBase()
{
    bool stateConnect;
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
   if(!QFile("../db/"DATABASE_NAME).exists()){
        QMessageBox::critical(NULL,"Ошибка открытия БД","Файл базы данных не найден.");
        stateConnect=false;
    }
   else {
        stateConnect=this->openDataBase();
    }
    return stateConnect;
}

bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
     if(db.isOpen())
        return true;

    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(ACCESS);

    if(db.open()){
        return true;
    }
    else {

        QMessageBox::critical(NULL,"Ошибка открытия БД",db.lastError().text());
        return false;
    }
}

 void DataBase::setFileName(QString name)
{
    fileName=name;
}


/* Методы закрытия базы данных*/
void DataBase::closeDataBase()
{
    db.close();
}

QSqlQuery DataBase::getQueryRegion()
{

    if(this->openDataBase()){
          QSqlQuery query;
        if(!query.exec("SELECT *from Region"))
           qDebug() << query.lastError().text();
    return query;
    }


}


QSqlQuery DataBase::getQueryDistrict(int id_Region)
{

    if(this->openDataBase()){
          QSqlQuery query;
        if(!query.exec(QString("SELECT *  FROM District\
                               WHERE (((District.[ID])=0)) OR (((District.[ID_REGION])=%1))\
                               ORDER BY District.district;").arg(id_Region)))
       qDebug() << query.lastError().text();
       return query;
    }


}

QSqlQuery DataBase::getQueryDistrict_FULL()
{

    if(this->openDataBase()){
          QSqlQuery query;
        if(!query.exec(QString("SELECT District.*, *FROM District\
                               ORDER BY District.district; ")))
           qDebug() << query.lastError().text();
       return query;
    }


}


QSqlQuery DataBase::getQueryDiameter()
{
    if(this->openDataBase()){
          QSqlQuery query;
        if(!query.exec("SELECT *from Instruments where idClassInstruments=1"))
           qDebug() << query.lastError().text();
       return query;
    }
}

QSqlQuery DataBase::queryToBase(QString queryText)
{

     qDebug()<<queryText;

    if(this->openDataBase()){
          QSqlQuery query;
        if(!query.exec(queryText))
           qDebug() << query.lastError().text();
         return query;

    }
}

QSqlDatabase DataBase::getDatase()
{
    return db;
}
