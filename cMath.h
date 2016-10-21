#ifndef CMATH_H
#define CMATH_H

#include "QString"
#include "QDateTime"

class cMath
{
public:
    static qint64  getMsec();

    static QString msecToString(qint64  t);
    static void current_utc_time(struct timespec *ts);
};

#endif // CMATH_H
