#ifndef SERVICEQSQLQUERYMODEL_H
#define SERVICEQSQLQUERYMODEL_H

#include "QSqlQueryModel"


class ServiceQSqlQueryModel : public QSqlQueryModel
{
public:
    ServiceQSqlQueryModel(QObject *parent = Q_NULLPTR);

    QVariant data(const QModelIndex &item, int role) const;

};

#endif // SERVICEQSQLQUERYMODEL_H
