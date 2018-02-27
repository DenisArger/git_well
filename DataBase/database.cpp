#include "database.h"
#include <QMessageBox>

DataBase::DataBase(QObject *parent) : QObject(parent),fileName(" ")
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
   if(!QFile("../db/" DATABASE_NAME).exists()){
       qDebug()<< "Файл базы данных не найден";
        //QMessageBox::critical(this,'Ошибка открытия БД',"Файл базы данных не найден.");
    } else {
        this->openDataBase();
    }
}

bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */

    QString fileDataBase = QDir::currentPath()+"\\db\\DatabaseWell.mdb";

    if(db.isOpen())
        return true;

    db = QSqlDatabase::addDatabase("QODBC");
   QString file;
   // qDebug()<<file;
    if(fileName== " ")
     db.setDatabaseName(ACCESS);
   // }
    else{
         file= ACCESS_SHORT+fileName;
          db.setDatabaseName(file);
    }
     qDebug()<<file;
    if(db.open()){
        return true;
    } else {
       // QMessageBox::critical(this,"Ошибка открытия БД","Не  возможно открыть файл базы данных.");
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
        if(!query.exec(QString("SELECT *from District where ID=0 OR ID_REGION=%1").arg(id_Region)))
           qDebug() << query.lastError().text();
       return query;
    }


}

QSqlQuery DataBase::getQueryDistrict_FULL()
{

    if(this->openDataBase()){
          QSqlQuery query;
        if(!query.exec(QString("SELECT *from District ")))
           qDebug() << query.lastError().text();
       return query;
    }


}


QSqlQuery DataBase::getQueryDiameter()
{
    if(this->openDataBase()){
          QSqlQuery query;
        if(!query.exec("SELECT *from Instruments where idClassInstruments=0"))
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
