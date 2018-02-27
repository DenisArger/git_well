#include "heirqsqlquerymodel.h"
#include "QBrush"


HeirQSqlQueryModel::HeirQSqlQueryModel(QObject *parent)
{

}

QVariant HeirQSqlQueryModel::data(const QModelIndex &item, int role) const
{
    QColor color(141,249,220);
    QColor color2(245,249,141);

    QModelIndex index_= item.sibling(item.row(),1);
        if (role == Qt::BackgroundRole) {
            if (index_.model()->data(index_, Qt::DisplayRole).toInt()) {
                   return QBrush(color);
            }
           else {
                return  QBrush(color2);
            }
        }

    return QSqlQueryModel::data(item,role);
}
