#ifndef MYLIST_H
#define MYLIST_H
#include"canditate.h"
#include"interviwer.h"

class mylist
{
public:
    Canditate canditatedata;
    Interviwer interviwerdata;
    mylist* next;
    mylist* prev;
    mylist();
};

#endif // MYLIST_H
