#include "datetime.h"

DateTime::DateTime() {
    now = time(nullptr);
    lt = localtime(&now);
    m_hour = lt->tm_hour;
    m_minute = lt->tm_min;
    m_second = lt->tm_sec;
    m_day = lt->tm_wday;
    m_month = lt->tm_mon;
    m_year = lt->tm_year;
}

string DateTime::getDate()
{
    return to_string(m_day)+ ":" + to_string(m_month) + ":" + to_string(m_year);
}
string DateTime::getTime()
{
    return to_string(m_hour)+":" + to_string(m_minute) + ":" +to_string(m_second);
}

