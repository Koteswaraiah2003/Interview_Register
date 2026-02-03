#ifndef INTERVIWER_H
#define INTERVIWER_H

#include<iostream>
#include<string>
#include"canditate.h"
using namespace std;

class Interviwer
{
    string m_name;
    string m_employeid;
public:
    // Interviwer(int i,string n);
    void setInterviwerName(string name);
    void setInterviwerId(string empid);
    string getinterviwerName();
    string getInterviwerId();
    void displayInterviwerDetails();
};

#endif // INTERVIWER_H
