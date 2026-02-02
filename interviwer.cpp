#include "interviwer.h"
#include"canditate.h"

void Interviwer::setEmpId(string empid)
{
    m_employeid = empid;
}
void Interviwer::setName(string name)
{
    m_name = name;
}
string Interviwer::getEmpId()
{
    return m_employeid;
}
string Interviwer::getName()
{
    return m_name;
}
void Interviwer::display()
{
    cout<<"InterviewerName: "<<m_name<<"\t\t"<<"EmpId: "<<m_employeid<<endl;
}
