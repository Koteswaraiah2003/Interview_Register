#include "canditate.h"
using namespace std;
Canditate::Canditate() {
}

void Canditate::setCanditateId(int i)
{
    m_canditateid = i;
    cout<<m_canditateid<<endl;
}
void Canditate::displayCanditateDetails()
{
    cout<<"CanditateID: "<<m_canditateid<<"\t\t"<<"Name: "<<m_canditatename<<"\t\t"<<"PhoneNumber: "<<m_canditatephno<<"\t\t"<<"Requirement: "<<m_requirement<<endl;
}
void Canditate::setCanditateName(string n){

    m_canditatename=n;
}
void Canditate::setCanditateRequirement(string lang)
{
    m_requirement=lang;
}
void Canditate::setCanditatePhno(string phn)
{
    m_canditatephno=phn;
}
string Canditate::getCanditateName()
{
    return m_canditatename;
}
string Canditate::getCanditateRequirement()
{
    return m_requirement;
}
string Canditate::getCandiatePhno()
{
    return m_canditatephno;
}
int Canditate::getCabditateId()
{
    return m_canditateid;
}

