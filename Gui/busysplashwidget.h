#ifndef BUSYSPLASHWIDGET_H
#define BUSYSPLASHWIDGET_H

#include <QSplashScreen>
class BusySplashWidget: public QSplashScreen
{
public:
    BusySplashWidget();
    BusySplashWidget(const QString &t, QWidget *parent);
};

#endif // BUSYSPLASHWIDGET_H
