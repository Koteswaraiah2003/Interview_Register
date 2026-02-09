#include "interviewmanager.h"
#include"canditate.h"
#include"datetime.h"
#include"interviwer.h"
#include<list>
#include<cstring>
#include"mylist.h"
#include"functions.cpp"

//int flag;
int ifInterviewRegistred;
int canditateId=1;

Interviewmanager::Interviewmanager() {

    canditatehead = nullptr;
    canditateend = nullptr;
    interviwerhead = nullptr;
    interviwerend = nullptr;
}


mylist<Canditate>* Interviewmanager::findCanditate(int id)
{
    mylist<Canditate>*temp = canditatehead;
    while(temp !=nullptr)
    {
        if(temp->data.getCabditateId() == id)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

mylist<Interviwer>* Interviewmanager::findInterviwer(string id)
{
    mylist<Interviwer>* temp = interviwerhead;
    while(temp != nullptr)
    {
        if(temp->data.getInterviwerId()==id)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

bool Interviewmanager::checkTimeValid(const string time)
{
    if (time.length() != 5)
        return false;

    if (time[2] != ':')
        return false;

    if (!isdigit(time[0]) || !isdigit(time[1]) || !isdigit(time[3]) || !isdigit(time[4]))
        return false;

    size_t p1 = time.find(':');

    string hour   = time.substr(0, p1);
    string minute = time.substr(p1 + 1);

    int Hour = stoi(hour);
    int Minute = stoi(minute);

    if ((Hour < 9) || (Hour > 18))
        return false;

    if (Hour == 9 && Minute < 30)
        return false;

    if (Hour == 18 && Minute > 0)
        return false;

    if ((Minute < 0) || (Minute > 59))
        return false;

    return true;
}

bool Interviewmanager::checkDateValid(const string date)
{
    if (date.length() != 10)
        return false;

    if (date[2] != ':' || date[5] != ':')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    int day   = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year  = stoi(date.substr(6, 4));

    if ((month < 1) || (month > 12))
        return false;

    if (day < 1)
        return false;

    int daysInMonth[] ={ 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};

    bool leap =(year % 4 == 0 && year % 100 != 0) ||(year % 400 == 0);

    if (leap)
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    tm userDate = {};
    userDate.tm_mday = day;
    userDate.tm_mon  = month - 1;
    userDate.tm_year = year - 1900;
    userDate.tm_hour = 0;
    userDate.tm_min  = 0;
    userDate.tm_sec  = 0;

    time_t userTime = mktime(&userDate);

    time_t now = time(nullptr);
    tm today = *localtime(&now);

    today.tm_hour = 0;
    today.tm_min  = 0;
    today.tm_sec  = 0;

    time_t todayTime = mktime(&today);

    if (difftime(userTime, todayTime) < 0)
        return false;

    if (userDate.tm_wday == 0 || userDate.tm_wday == 6)
        return false;

    return true;
}

bool Interviewmanager::numberValid(string number)
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
bool Interviewmanager::whitespace(string name)
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
    while(option!=4)
    {
        cout<<"\n1)Admin\t\t2)Canditate\t3)DisplayScheduleInterview\t4)exit\n";
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
            else if(option ==3)
            {
                displayScheduleInterviews();
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
            cout<<"\npassword should combination of capital,small, number ans atleast one special character\n";
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
                cout<<"\n1)Display_canditate_details\t2)Display_Interviwer_details\t3)interviwer\t4)exit\n";
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
                                cout<<"\n1)addinterviewer\t2)removeinterviewer\t3)scheduleInterview\t4)RemoveScheduleInterview\t5)DisplayscheduleInterview\t6)exit\n";
                                getline(cin,option4);
                                if(!(numberValid(option4)))
                                {
                                cout<<"Invalid input"<<endl;
                                }
                                else
                                {
                                    option5=stoi(option4);
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
                                    else if(option5 == 3)
                                    {
                                        ScheduleInterview();
                                    }
                                    else if(option5==4)
                                    {
                                        removeScheduleInterview();
                                    }
                                    else if(option5 == 5)
                                    {
                                        displayScheduleInterviews();
                                    }
                                    else if(option5==6)
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

void Interviewmanager::removeScheduleInterview()
{
    // cout<<"Pending"<<endl;
    if(scheduledInterviews.empty())
    {
        cout<<"\nNo interviews schuled to remove\n";
        return;
    }
    string idInput;
    int id;

    cout<<"\nEnter Canditate ID to remove interview:";
    getline(cin, idInput);

    if(!numberValid(idInput))
    {
        cout<<"Invalid Id\n";
        return ;
    }
    id = stoi(idInput);

    if(scheduledInterviews.erase(id))
    {
        cout<<"Interview removed successfully\n";
    }
    else
    {
        cout<<"No interview scheduled for this canditate\n";
    }
}

bool Interviewmanager::checkCanditateID(int Id)
{
    mylist<Canditate>* temp = canditatehead;

    while(temp!=nullptr)
    {
        if(Id==(temp->data.getCabditateId()))
        {
            cout<<endl;
            temp->data.displayCanditateDetails();
            cout<<endl;
            return true;
        }
        temp=temp->next;
    }
    return false;
}

bool Interviewmanager::checkEmployeId(string Id)
{
    mylist<Interviwer>*temp = interviwerhead;

    while(temp!=nullptr)
    {
        if(Id==(temp->data.getInterviwerId()))
        {
            cout<<endl;
            temp->data.displayInterviwerDetails();
            cout<<endl;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Interviewmanager::displayScheduleInterviews()
{
    if(scheduledInterviews.empty())
    {
        cout<<"\nNo interviews scheduled yet\n";
        return;
    }

    cout<<"\n Scheduled Interviews \n";

    for(auto &pair : scheduledInterviews)
    {
        cout<<"\nCandidate ID: "<<pair.first<<endl;

        cout<<"Candidate Details:\n";
        pair.second.canditate.displayCanditateDetails();

        cout<<"Interviewer Details:\n";
        pair.second.interviwer.displayInterviwerDetails();

        cout<<"Date: "<<pair.second.schedule.getDate()<<endl;
        cout<<"Time: "<<pair.second.schedule.getTime()<<endl;

        cout<<"-----------------------------------------\n";
    }
}


void Interviewmanager::ScheduleInterview()
{
    cout<<"Scheduling interview"<<endl;
    // Canditate canditate;
    // Interviwer interviwer;
    if(!(displayCanditate()))
    {
        cout<<"\nwe can't schedule an interviwer canditates is not available\n"<<endl;
        return;
    }
    if(!(displayInterviwer()))
    {
        cout<<"we can't schedule an interviwe interviwer is not available\n"<<endl;
        return;
    }
    string canditateId;
    string employeId;
    int CanditateId;
    while(true)
    {
        cout<<"Enter Canditate Id"<<endl;
        getline(cin,canditateId);
        if(!(numberValid(canditateId)))
        {
            cout<<"Invalid Input"<<endl;
            continue;
        }
        CanditateId = stoi(canditateId);
        if(checkCanditateID(CanditateId))
        {
            break;
        }
        cout<<"Canditate Id is not available please check"<<endl;
    }
    while(true)
    {
        cout<<"Enter Employe Id"<<endl;
        getline(cin,employeId);
        if(checkEmployeId(employeId))
        {
            break;
        }
        cout<<"Employe Id is not available"<<endl;
    }

    string date,time;

    // cout<<"Date:"<<datetime.getDate()<<endl;
    // cout<<"Time:"<<datetime.getTime()<<endl;
    while(true)
    {
        cout<<"Enter which day you want to take please enter date that date formate should be 06:02:2026"<<endl;
        getline(cin,date);
        if(checkDateValid(date))
        {
            break;
        }
        cout<<"\nsorry the formate is wrong\n"<<endl;
    }
    while(true)
    {
        cout<<"\nEnter at what time you want to take time should be 24 hours formate 10:48"<<endl;
        getline(cin,time);
        if(checkTimeValid(time))
        {
            break;
        }
        cout<<"sorry the formate is wrong"<<endl;
    }

    Interview newInterview;

    mylist<Canditate>* cnode = findCanditate(CanditateId);
    newInterview.canditate = cnode->data;

    mylist<Interviwer>* inode = findInterviwer(employeId);
    newInterview.interviwer = inode->data;

    DateTime dt;
    dt.setDate(date);
    dt.setTime(time);
    newInterview.schedule = dt;

    scheduledInterviews[CanditateId] = newInterview;

    cout<<"Thankyou Interview is scheduled"<<endl;

}

void Interviewmanager::addCanditate()
{
    string name,requirement,phno;
    Canditate canditate;
//    cin.ignore(1000, '\n');

    while(true)
    {
        cout<<"Enter your name"<<endl;
        getline(cin,name);
        if(isValidName(name))
            break;
        cout<<"please Enter correct name"<<endl;
    }
    canditate.setCanditateName(name);

    while(true)
    {
        cout<<"Enter your phno"<<endl;
        getline(cin,phno);
        if(isValidPhno(phno))
            break;
        cout<<"Please enter valid phonenumber"<<endl;
    }

    canditate.setCanditatePhno(phno);

    while(true)
    {
        cout<<"Enter which Language you know"<<endl;
        getline(cin,requirement);
        if((whitespace(requirement))){
            break;
        }
        cout<<"enter valid requirement"<<endl;
    }
    canditate.setCanditateRequirement(requirement);

    canditate.setCanditateId(canditateId);


    // mylist* newNode=new mylist();
    // newNode->canditatedata = &canditate;

    mylist<Canditate>* newNode = new mylist<Canditate>(canditate);

    if(canditatehead == nullptr)
    {
        cout<<"This is your ID: "<<canditateId<<endl;
        canditateId++;
        canditatehead=newNode;
        canditateend=newNode;
        return;
    }
    else
    {
        canditateend->next = newNode;
        newNode->prev =canditateend;
        canditateend = newNode;
    }
    cout<<"This is your ID: "<<canditateId<<endl;
    canditateId++;

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

    while(true)
    {
        cout<<"Enter your Id"<<endl;
        getline(cin,id);
        if(whitespace(id))
        {
            break;
        }
        cout<<"Invalid Input"<<endl;
    }


    interviewer.setInterviwerId(id);

    // mylist* newNode=new mylist();
    // newNode->interviwerdata = &interviwer;

    mylist<Interviwer>* newNode = new mylist<Interviwer>(interviewer);

//    cout<<interviwerlist.head<<endl<<endl;

    if(interviwerhead == nullptr)
    {
        interviwerhead=newNode;
        interviwerend=newNode;
        return;
    }
    else
    {
        interviwerend->next = newNode;
        newNode->prev =interviwerend;
        interviwerend = newNode;
    }

//    myInterviwer.push_back(interviewer);
}

bool Interviewmanager::displayCanditate()
{
    if(canditatehead == nullptr)
    {
        cout<<"Canditate List is empty"<<endl;
        return false;
    }
    cout<<"\nDisplaying Canditate Details"<<endl;
    int i=1;
    mylist<Canditate>*temp = canditatehead;

    while(temp!=nullptr)
    {
        cout<<i<<") ";
        temp->data.displayCanditateDetails();
        temp=temp->next;
        i++;
    }
    cout<<endl;
    return true;
}

bool Interviewmanager::displayInterviwer()
{
    if(interviwerhead == nullptr)
    {
        cout<<"Interviwer List is empty"<<endl;
        return false;
    }

    cout<<"\nDisplaying Interviwer details\n"<<endl;


    mylist<Interviwer>* temp = interviwerhead;

    int i=1;
    while(temp!=nullptr)
    {
        cout<<i<<") ";
        temp->data.displayInterviwerDetails();
        temp=temp->next;
        i++;
    }
    cout<<endl;
    return true;
}

void Interviewmanager::removeInterviwer()
{
    if(interviwerhead == nullptr)
    {
        cout<<"Interviwer List is empty"<<endl;
        return;
    }


    mylist<Interviwer>*temp = interviwerhead;
    int count=0;
    cout<<endl;
    while(temp!=nullptr)
    {
        cout<<count+1<<") ";
        temp->data.displayInterviwerDetails();
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
                temp = interviwerhead;

                while(temp!=nullptr && i<option){
                    temp = temp->next;
                    i++;
                }

                if(interviwerhead == interviwerend)
                {
                    cout<<temp->data.getInterviwerId();
                    delete interviwerhead;
                    interviwerhead = interviwerend = nullptr;
                    cout<<" is deleted"<<endl;
                    return;
                }
                if(temp == interviwerhead)
                {
                    cout<<temp->data.getInterviwerId();
                    interviwerhead = temp->next;
                    interviwerhead->prev =nullptr;
                    delete temp;
                    cout<<" is deleted\n";
                    return;
                }
                if(temp == interviwerend)
                {
                    cout<<temp->data.getInterviwerId();
                    interviwerend = temp->prev;
                    interviwerend->next = nullptr;
                    delete temp;
                    cout<<" is deleted\n";
                    return;
                }
                cout<<temp->data.getInterviwerId();
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                cout<<" is deleted\n";
                break;
            }
        }
    }

}






























