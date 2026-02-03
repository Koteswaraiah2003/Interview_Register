#include "interviwer.h"
#include"canditate.h"

void Interviwer::setInterviwerId(string empid)
{
    m_employeid = empid;
}
void Interviwer::setInterviwerName(string name)
{
    m_name = name;
}
string Interviwer::getInterviwerId()
{
    return m_employeid;
}
string Interviwer::getinterviwerName()
{
    return m_name;
}
void Interviwer::displayInterviwerDetails()
{
    cout<<"InterviewerName: "<<m_name<<"\t\t"<<"EmpId: "<<m_employeid<<endl;
}
