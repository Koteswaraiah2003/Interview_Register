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
    void setName(string name);
    void setEmpId(string empid);
    string getName();
    string getEmpId();
    void display();
};

#endif // INTERVIWER_H
