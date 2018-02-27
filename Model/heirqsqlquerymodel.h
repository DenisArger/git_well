#ifndef HEIRQSQLQUERYMODEL_H
#define HEIRQSQLQUERYMODEL_H

#include "QSqlQueryModel"
#include "global.h"

class HeirQSqlQueryModel : public QSqlQueryModel
{
public:
    HeirQSqlQueryModel(QObject *parent = Q_NULLPTR);

     QVariant data(const QModelIndex &item, int role) const;
};

#endif // HEIRQSQLQUERYMODEL_H
