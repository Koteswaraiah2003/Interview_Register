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

bool numberValid(string number)
{
    int length=0;
    for(char ch:number)
    {
        if(ch>='0' && ch<='9'){}
        else
            return false;
        length++;
    }
//    cout<<"Length="<<length<<endl;
    if(length>2)
        return false;
    return true;
}
bool whitespace(string name)
{
    if(name[0] == ' ')
        return false;

    else
    {
        int i=1;
        while(name[i]!='\0')
        {
            if(name[i]==' ' && name[i+1]==' ')
                return false;
            i++;
        }
    }
    return true;
}

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
    string option1;
    int option=0;
    while(option!=3)
    {
        cout<<"1)Admin\t2)Canditate\t3)exit\n";
        getline(cin,option1);
        if(!(numberValid(option1)))
        {
            cout<<"Invalid input"<<endl;
        }
        else
        {
            option=option1[0]-'0';
            if(option == 0)
                cout<<" 0 will not accept"<<endl;
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
}
void Interviewmanager::adminLogin()
{
    int option=0;
    string name;
    string password;

//    cin.clear();
    // cin.ignore(1000, '\n');

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
        string option1;
        while(option!=4)
        {
                cout<<"1)Display_canditate_details\t2)Display_Interviwer_details\t3)interviwer\t4)exit\n";
                getline(cin,option1);
                if(!(numberValid(option1)))
                {
                    cout<<"Invalid input"<<endl;
                }
                else
                {
                    option=option1[0]-'0';
                    if(option == 0)
                    {
                        cout<<" 0 will not accept"<<endl;
                    }
                        else if(option==1)
                        {
                            displayCanditate();
                        }
                        else if(option==2)
                        {
                            displayInterviwer();
                        }
                        else if(option==3)
                        {
                            while(true)
                            {
                                string option4;
                                int option5;
                                cout<<"1)addinterviewer\t2)removeinterviewer\t3)exit\n";
                                getline(cin,option4);

                                if(!(numberValid(option4)))
                                {
                                cout<<"Invalid input"<<endl;
                                }
                                else
                                {
                                    option5=option4[0]-'0';
                                    if(option5 == 0)
                                    {
                                    cout<<" 0 will not accept"<<endl;
                                    }

                                    else if(option5==1){
                                    addInterviwer();
                                    }

                                    else if(option5==2)
                                    {
                                        removeInterviwer();
                                    }
                                    else if(option5==3)
                                        break;

                                }
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
    string name,requirement,phno;
    Canditate c;
//    cin.ignore(1000, '\n');

    while(true)
    {
        cout<<"Enter your name"<<endl;
        getline(cin,name);
        if(isValidName(name))
            break;
        cout<<"please Enter correct name"<<endl;
    }
    c.setCanditateName(name);

    while(true)
    {
        cout<<"Enter your phno"<<endl;
        getline(cin,phno);
        if(isValidPhno(phno))
            break;
        cout<<"Please enter valid phonenumber"<<endl;
    }

    c.setCanditatePhno(phno);

    while(true)
    {
        cout<<"Enter which Language you know"<<endl;
        getline(cin,requirement);
        if((whitespace(requirement))){
            break;
        }
        cout<<"enter valid requirement"<<endl;
    }
    c.setCanditateRequirement(requirement);

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
    string id;
    while(true)
    {
        cout<<"Enter your name"<<endl;
        getline(cin,name);
        if(isValidName(name))
            break;
        cout<<"Please Enter correct name"<<endl;
    }
    interviewer.setInterviwerName(name);

    cout<<"Enter your Id"<<endl;
    getline(cin,id);

    interviewer.setInterviwerId(id);

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
        temp->canditatedata.displayCanditateDetails();
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
        temp->interviwerdata.displayInterviwerDetails();
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
        temp->interviwerdata.displayInterviwerDetails();
        temp=temp->next;
        count++;
    }
    cout<<endl;
    int option;

    while(true)
    {
        string option1;
        cout<<"Enter which one you want to remove"<<endl;
        getline(cin,option1);

        if(!(numberValid(option1)))
        {
            cout<<"Invalid input"<<endl;
        }
        else
        {
            option=option1[0] - '0';
            if((option < 1)|| option >count)
            {
                cout<<"that node is not available"<<endl;
                // goto L1;
            }
            else
            {
                int i=1;
                temp = interviwerlist.head;

                while(temp!=nullptr && i<option){
                    temp = temp->next;
                    i++;
                }

                if(interviwerlist.head == interviwerlist.end)
                {
                    cout<<temp->interviwerdata.getInterviwerId();
                    delete interviwerlist.head;
                    interviwerlist.head = interviwerlist.end = nullptr;
                    cout<<" is deleted"<<endl;
                    return;
                }
                if(temp == interviwerlist.head)
                {
                    cout<<temp->interviwerdata.getInterviwerId();
                    interviwerlist.head = temp->next;
                    interviwerlist.head->prev =nullptr;
                    delete temp;
                    cout<<" is deleted\n";
                    return;
                }

                if(temp == interviwerlist.end)
                {
                    cout<<temp->interviwerdata.getInterviwerId();
                    interviwerlist.end = temp->prev;
                    interviwerlist.end->next = nullptr;
                    delete temp;
                    cout<<" is deleted\n";
                    return;
                }
                cout<<temp->interviwerdata.getInterviwerId();
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                cout<<" is deleted\n";
                break;
            }
        }
    }

}






























