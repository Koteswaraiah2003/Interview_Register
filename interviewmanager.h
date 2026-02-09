#ifndef INTERVIEWMANAGER_H
#define INTERVIEWMANAGER_H

#include<string>
#include<list>
#include<map>

#include"mylist.h"
#include"canditate.h"
#include"datetime.h"
#include"interviwer.h"
#include"interview.h"



using namespace std;


class Interviewmanager
{
private:

    string m_adminname;
    string m_adminpassword;
public:
    mylist<Canditate>* canditatehead;
    mylist<Canditate>* canditateend;

    mylist<Interviwer>*interviwerhead;
    mylist<Interviwer>*interviwerend;
    map<int, Interview>scheduledInterviews;

    // CanditateList canditatelist;
    // InterviweList interviwerlist;
    Interviewmanager();
    void addCanditate();
    void addInterviwer();
    void removeInterviwer();
    void Login();
    void adminLogin();
    bool displayCanditate();
    bool displayInterviwer();
    bool isValidName(string );
    bool isValidPhno(string);
    bool numberValid(string);
    bool whitespace(string name);
    bool passwordCheckIn(string);
    void ScheduleInterview();
    bool checkCanditateID(int);
    bool checkEmployeId(string);
    void removeScheduleInterview();
    bool checkTimeValid(const string time);
    bool checkDateValid(const string date);
    mylist<Canditate>* findCanditate(int id);
    mylist<Interviwer>* findInterviwer(string id);
    void displayScheduleInterviews();



};

#endif // INTERVIEWMANAGER_H
