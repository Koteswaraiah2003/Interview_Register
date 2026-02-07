#ifndef MYLIST_H
#define MYLIST_H
#include"canditate.h"
#include"interviwer.h"

template <typename T>
class mylist
{
public:
    T data;
    mylist<T>* next;
    mylist<T>* prev;
    mylist(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

#endif // MYLIST_H
