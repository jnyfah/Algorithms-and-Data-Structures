#ifndef SSTACK_H
#define SSTACK_H

template<class T>
class Sstack
{
private:
    T *stackarray;     //pointer t the stack array
    int stacksize;
    int top;         //indicates top of the stack

public:
    Sstack(int);                    //constructor
    Sstack(const Sstack &);         // copy constructor

    void push(T);
    void pop( T &);
    void display();
    bool isfull();
    bool isempty();


    ~Sstack();
};

#include "sstack.cpp"

#endif // SSTACK_H
