#include "servicecardquerymodel.h"
#include "QDebug"
#include "QDate"
#include "QDateTime"

ServiceCardQueryModel::ServiceCardQueryModel(QObject *parent)
{

}

QVariant ServiceCardQueryModel::data(const QModelIndex &item, int role) const
{
    QVariant value=QSqlQueryModel::data(item,role);

    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if(item.column()==2){
            return value.toDate().toString("dd.MM.yyyy").remove(11,4);
        }
        break;
    default:
        break;
    }

   return value;
}
