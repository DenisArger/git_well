#include "serviceqsqlquerymodel.h"
#include "QDebug"


ServiceQSqlQueryModel::ServiceQSqlQueryModel(QObject *parent)
{

}

QVariant ServiceQSqlQueryModel ::data(const QModelIndex &item, int role) const
{

    QVariant value=QSqlQueryModel::data(item,role);

    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if(item.column()==6){
            if (value.toInt()==0)
                return "";
            if (value.toInt()==1)
                return "На рассмотрении";
            if (value.toInt()==2)
                return "На обслуживании";
            if (value.toInt()==3)
                return "Отказ";
        }
        break;
    default:
        break;
    }

   return value;
}
