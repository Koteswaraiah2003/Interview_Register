#ifndef INTERVIEWMANAGER_H
#define INTERVIEWMANAGER_H

#include<string>
#include<list>

#include"mylist.h"
#include"canditate.h"
#include"date_time.h"
#include"interviwer.h"
#include "canditatelist.h"
#include "interviewlist.h"
using namespace std;


class Interviewmanager
{
private:

//    list<Canditate> canditate;
    list<Date_Time> datetime;
//    list<Interviwer> myInterviwer;

    string m_adminname;
    string m_adminpassword;
public:
    CanditateList canditatelist;
    InterviweList interviwerlist;
    Interviewmanager();
    void addCanditate();
    void addInterviwer();
    void removeInterviwer();
    void Login();
    void adminLogin();
    void displayCanditate();
    void displayInterviwer();
    bool isValidName(string );
    bool isValidPhno(string);
    bool passwordCheckIn(string);


};

#endif // INTERVIEWMANAGER_H
