#include "busysplashwidget.h"
#include <QPixmap>
#include <QPainter>

BusySplashWidget :: BusySplashWidget(const QString & t, QWidget * parent) :
    QSplashScreen(parent)
{
   const int margin = 5;
   QFontMetrics fm = fontMetrics();
   QRect r(0,0,margin+fm.width(t)+margin, margin+fm.ascent()+fm.descent()+1+margin);
   QPixmap pm(r.width(), r.height());
   pm.fill(Qt::white);

   // these braces ensure that ~QPainter() executes before setPixmap()
   {
      QPainter p(&pm);
      p.setPen(Qt::black);
      p.drawText(r, Qt::AlignCenter, t);
      p.drawRect(QRect(0,0,r.width()-1,r.height()-1));
   }
   setPixmap(pm);
}

BusySplashWidget::BusySplashWidget()
{

}
