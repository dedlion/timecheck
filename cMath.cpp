#include "cMath.h"
#include "time.h"



qint64 cMath::getMsec()
{
    QDateTime now = QDateTime::currentDateTime();
    return now.toMSecsSinceEpoch();
}

QString cMath::msecToString(qint64 t)
{
    QDateTime time;
    time.setMSecsSinceEpoch(t);
    QString res =  time.toString("yyyy dd.MM HH:mm:ss zzz");
    return res;
}

void cMath::current_utc_time(timespec *ts)
{
      clock_gettime(CLOCK_REALTIME, ts);
}


