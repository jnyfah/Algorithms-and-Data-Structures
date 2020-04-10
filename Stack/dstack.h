#ifndef DSTACK_H
#define DSTACK_H

template<class T>
class Dstack
{
private:

    struct node{     //linked list
        T item;
        node *next;
    };

     node *top;
public:
    Dstack(){
       top = nullptr;
    }
    void push(T);
    void pop(T &);
    bool isempty();
    ~Dstack();
};

#include "dstack.cpp"
#endif // DSTACK_H
