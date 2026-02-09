
#ifndef DATETIME_H
#define DATETIME_H
#include<string>
#include<ctime>
#include<cstring>
#include<sstream>

using namespace std;
class DateTime
{
private:
    time_t now;
    tm *lt;
    int m_day,m_month,m_year;
    int m_hour,m_minute,m_second;
public:
    DateTime();
    void setDate(string);
    void setTime(string);

    string getTime();
    string getDate();
};

#endif // DATETIME_H
