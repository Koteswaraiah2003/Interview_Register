#include "canditate.h"
using namespace std;
Canditate::Canditate() {

}
void Canditate::displayCanditateDetails()
{
    cout<<"Name: "<<m_canditatename<<"\t\t"<<"phno: "<<m_canditatephno<<"\t\t"<<"Requirement: "<<m_requirement<<endl;
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

