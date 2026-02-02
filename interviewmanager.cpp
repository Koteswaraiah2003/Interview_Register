#include "interviewmanager.h"
#include"canditate.h"
#include"date_time.h"
#include"interviwer.h"
#include<list>
#include<cstring>
#include"mylist.h"
#include"functions.cpp"

//int flag;
int ifInterviewRegistred;

Interviewmanager::Interviewmanager() {}

bool Interviewmanager::isValidName(string name)
{
    int length=0;
    for(char ch:name)
    {
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){}
        else
            return false;
        length++;
    }
    if(length>30)
        return false;
    else
        return true;
}

bool Interviewmanager::passwordCheckIn(string pass)
{
    int capitialLetter,smallLetter,number,specialCharacter,length;
    capitialLetter=0;
    smallLetter=0;
    number=0;
    specialCharacter=0;
    length=0;
    for(char ch:pass)
    {
        if(ch>='A' && ch<='Z'){
            capitialLetter=1;
        }
        else if(ch>='a' && ch<='z')
        {
            smallLetter=1;
        }
        else if(ch>='0' && ch<='9')
        {
            number=1;
        }
        else
            specialCharacter=1;
        length++;

    }
    // cout<<"len= "<<l;
    if(capitialLetter && smallLetter && number && specialCharacter && length>=8)
        return true;
    else
        return false;
}


bool Interviewmanager::isValidPhno(string name)
{
    int i=0;
    for(char ch:name)
    {
        if(ch>='0' && ch<='9'){}
        else
            return false;
    }
    for(char ch:name)
    {
        i++;
    }
    if(i!=10){
        return false;
    }

    return true;
}
void Interviewmanager::Login()
{
    int option=0;
    while(option!=3)
    {
        cout<<"1)Admin\t2)Canditate3)exit\n";
        cin>>option;

        if (cin.fail())// manual check without cin.fail
        {
            cin.clear(); //manual clear
            cin.ignore(100, '\n'); // manual
            cout << "Invalid input enter a number\n";

        }
        else if(option==1)
        {
            adminLogin();
        }
        else if(option==2)
        {
            addCanditate();
        }
    }
}
void Interviewmanager::adminLogin()
{
    int option=0;
    string name;
    string password;
    cin.ignore(1000, '\n');

    if(ifInterviewRegistred==0)
    {

        while (true)
        {
            cout << "Enter your name\n";
            getline(cin, name);

            if (isValidName(name))
                break;

            cout << "Please enter correct name\n";
        }
        while(true)
        {
            cout<<"password should combination of capital,small, number ans atleast one special character\n";
            cout<<"Enter password\n";
            getline(cin,password);

            if((passwordCheckIn(password)))
                break;
        }
        m_adminname = name;
        m_adminpassword = password;
        ifInterviewRegistred=1;
    }

    if(ifInterviewRegistred==1)
    {
        cout<<"please login"<<endl;
        while(true)
        {
            cout<<"Enter your name\n";
            getline(cin,name);
            if(!(isValidName(name))){
                cout<<"pleas Enter correct name"<<endl;
                continue;
            }
            if(name != m_adminname){
                cout<<"Name is mismatch"<<endl;
                continue;
            }
            break;

        }
        while(true)
        {
            cout<<"Enter your password\n";
            getline(cin,password);
            if((password==m_adminpassword))
            {
                cout<<"Login Successful"<<endl;
                break;
            }
            cout<<"Password is incorrect please Enter correct password"<<endl;
        }

        while(option!=4)
        {
                cout<<"1)Display_canditate_details\t2)Display_Interviwer_details\t3)interviwer\t4)exit\n";
                cin>>option;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid input enter a number\n";
                    continue;
                }
                if(option==1)
                {
                    displayCanditate();
                }
                if(option==2)
                {
                    displayInterviwer();
                }
                if(option==3)
                {
                    while(true)
                    {
                        int option1;
                        cout<<"1)addinterviewer\t2)removeinterviewer\t3)exit\n";
                        cin>>option1;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(100, '\n');
                            cout << "Invalid input enter a number\n";
                            continue;
                        }

                        if(option1==1){
                            addInterviwer();
                        }
                        if(option1==2)
                        {
                            removeInterviwer();
                        }
                        if(option1==3)
                            break;
                        if((option1!=1)&&(option1!=2)&&(option1!=3))
                        {
                            cout<<"please select correct option\n";
                            break;
                        }
                    }
                }
                if((option!=1)&&(option!=2)&&(option!=3)&&(option!=4))
                {
                    cout<<"please select correct option\n";
                }
            }
        }
    }




void Interviewmanager::addCanditate()
{
    string name,lang,phno;
    Canditate c;
    cin.ignore(1000, '\n');

    while(true)
    {
        cout<<"Enter your name"<<endl;
        getline(cin,name);
        if(isValidName(name))
            break;
        cout<<"please Enter correct name"<<endl;
    }
    c.setName(name);

    while(true)
    {
        cout<<"Enter your phno"<<endl;
        getline(cin,phno);
        if(isValidPhno(phno))
            break;
        cout<<"Please enter valid phonenumber"<<endl;
    }

    c.setPhno(phno);

    cout<<"Enter which Language you know"<<endl;
    getline(cin,lang);
    c.setLang(lang);

    mylist* newNode=new mylist();
    newNode->canditatedata = c;

    if(canditatelist.head == nullptr)
    {
        canditatelist.head=newNode;
        canditatelist.end=newNode;
        return;
    }
    canditatelist.end->next = newNode;
    newNode->prev =canditatelist.end;
    canditatelist.end = newNode;

//    canditate.push_back(c);

}
void Interviewmanager::addInterviwer()
{
    Interviwer interviewer;
    string name;
    string lang;
    cin.ignore(1000, '\n');

    while(true)
    {
        cout<<"Enter your name"<<endl;
        getline(cin,name);
        if(isValidName(name))
            break;
        cout<<"Please Enter correct name"<<endl;
    }

    // L1:
    // cout<<"Enter your name"<<endl;
    // getline(cin,name);
    // if(!(isValidName(name))){
    //     cout<<"please enter correct name\n";
    //     goto L1;
    // }
    interviewer.setName(name);

    cout<<"Enter your Id"<<endl;
    getline(cin,lang);

    interviewer.setEmpId(lang);

    mylist* newNode=new mylist();
    newNode->interviwerdata = interviewer;

//    cout<<interviwerlist.head<<endl<<endl;

    if(interviwerlist.head == nullptr)
    {
        interviwerlist.head=newNode;
        interviwerlist.end=newNode;
        return;
    }
    interviwerlist.end->next = newNode;
    newNode->prev =interviwerlist.end;
    interviwerlist.end = newNode;

//    myInterviwer.push_back(interviewer);
}

void Interviewmanager::displayCanditate()
{
    if(canditatelist.head == nullptr)
    {
        cout<<"Canditate List is empty"<<endl;
    }
    int i=1;
    mylist* temp = canditatelist.head;

    while(temp!=nullptr)
    {
        cout<<i<<") ";
        temp->canditatedata.display();
        temp=temp->next;
        i++;
    }
}

void Interviewmanager::displayInterviwer()
{
    if(interviwerlist.head == nullptr)
    {
        cout<<"Interviwer List is empty"<<endl;
    }

    mylist* temp = interviwerlist.head;
    int i=1;
    while(temp!=nullptr)
    {
        cout<<i<<") ";
        temp->interviwerdata.display();
        temp=temp->next;
        i++;
    }
}

void Interviewmanager::removeInterviwer()
{
    if(interviwerlist.head == nullptr)
    {
        cout<<"Interviwer List is empty"<<endl;
        return;
    }
    mylist* temp = interviwerlist.head;
    int count=0;
    cout<<endl;
    while(temp!=nullptr)
    {
        cout<<count+1<<") ";
        temp->interviwerdata.display();
        temp=temp->next;
        count++;
    }
    cout<<endl;
    int option;
//    L1:
    while(true)
    {
        cout<<"Enter which one you want to remove"<<endl;
        cin>>option;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input enter a number\n";
            continue;
        }

        if((option < 1)|| option >count)
        {
            cout<<"that node is not available"<<endl;
            // goto L1;
            continue;
        }

    int i=1;
    temp = interviwerlist.head;

    while(temp!=nullptr && i<option){
        temp = temp->next;
        i++;
    }

    if(interviwerlist.head == interviwerlist.end)
    {
        delete interviwerlist.head;
        interviwerlist.head = interviwerlist.end = nullptr;
        cout<<"Node is deleted"<<endl;
        return;
    }
    if(temp == interviwerlist.head)
    {
        interviwerlist.head = temp->next;
        interviwerlist.head->prev =nullptr;
        delete temp;
        cout<<"first node is deleted\n";
        return;
    }

    if(temp == interviwerlist.end)
    {
        interviwerlist.end = temp->prev;
        interviwerlist.end->next = nullptr;
        delete temp;
        cout<<"last node is deleted\n";
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    cout<<"Node is deleted\n";
    break;
    }

}






























