#ifndef CANDITATE_H
#define CANDITATE_H

#include<iostream>
#include<string>

using namespace std;
class Canditate
{
 private:

    int m_canditateid;
    string m_canditatename;
    string m_canditatephno;
    string m_requirement;
public:

    Canditate();
    void setCanditateName(string n);
    void setCanditateId(int i);
    void setCanditatePhno(string phn);
    void setCanditateRequirement(string lang);
    string getCanditateName();
    string getCandiatePhno();
    string getCanditateRequirement();
    int getCabditateId();
    void displayCanditateDetails();
};






#endif // CANDITATE_H
