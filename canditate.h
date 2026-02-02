#ifndef CANDITATE_H
#define CANDITATE_H

#include<iostream>
#include<string>
using namespace std;
class Canditate
{
 private:

    string m_canditatename;
    string m_canditatephno;
    string m_requirement;
public:

    Canditate();
    void setName(string n);
    void setPhno(string phn);
    void setLang(string lang);
    string getName();
    string getPhno();
    string getLang();
    void display();
};






#endif // CANDITATE_H
