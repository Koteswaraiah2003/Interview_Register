#include "datetime.h"

DateTime::DateTime() {
    now = time(nullptr);
    lt = localtime(&now);
    m_hour = lt->tm_hour;
    m_minute = lt->tm_min;
    m_second = lt->tm_sec;
    m_day = lt->tm_mday;
    m_month = lt->tm_mon+1;
    m_year = lt->tm_year+1900;
}

void DateTime::setDate(string d)
{
    m_day = stoi(d.substr(0,2));
    m_month = stoi(d.substr(3,2));
    m_year = stoi(d.substr(6,4));
}
void DateTime::setTime(string t)
{
    m_hour = stoi(t.substr(0,2));
    m_minute = stoi(t.substr(3,2));
}

string DateTime::getDate()
{
    return to_string(m_day)+ ":" + to_string(m_month) + ":" + to_string(m_year);
}
string DateTime::getTime()
{
    return to_string(m_hour)+":" + to_string(m_minute);
}

