#ifndef SERVICECARDQUERYMODEL_H
#define SERVICECARDQUERYMODEL_H


#include "QSqlQueryModel"


class ServiceCardQueryModel : public QSqlQueryModel
{
public:
    ServiceCardQueryModel(QObject *parent = Q_NULLPTR);

    QVariant data(const QModelIndex &item, int role) const;

};

#endif // SERVICECARDQUERYMODEL_H
