#include "canditate.h"
using namespace std;
Canditate::Canditate() {

}
void Canditate::display()
{
    cout<<"Name: "<<m_canditatename<<"\t\t"<<"phno: "<<m_canditatephno<<"\t\t"<<"Requirement: "<<m_requirement<<endl;
}
void Canditate::setName(string n){

    m_canditatename=n;
}
void Canditate::setLang(string lang)
{
    m_requirement=lang;
}
void Canditate::setPhno(string phn)
{
    m_canditatephno=phn;
}
string Canditate::getName()
{
    return m_canditatename;
}
string Canditate::getLang()
{
    return m_requirement;
}
string Canditate::getPhno()
{
    return m_canditatephno;
}

