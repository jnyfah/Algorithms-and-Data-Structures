#include "sstack.h"
#include<iostream>

template<class T>
Sstack<T>::Sstack(int size)         // constructor
{
    stackarray =  new T [size];
    stacksize = size;
    top = -1;
}

template<class T>
Sstack<T>::Sstack(const Sstack &obj)   //copy constructor
{
    if(obj.stacksize > 0)
        stackarray = new T [obj.stacksize];
    else
        stackarray =nullptr;

    stacksize = obj.stacksize;

    for(int i=0; i<obj.stacksize; i++)
    {
        stackarray[i]=obj.stackarray[i];
    }

    top = obj.top;
}

template<class T>
void Sstack<T>::push(T item)
{
    if(isfull())
        std::cout<<"stack is full"<<std::endl;
    else
        top++;
        stackarray[top] = item;
}

template<class T>
void Sstack<T>::pop(T &item)
{
    if(isempty())
        std::cout<<"stack is empty"<<std::endl;
    else
        item = stackarray[top];
        top--;
}

template<class T>
bool Sstack<T>::isfull()
{
    bool status;

    if (top == stacksize-1)
        status = true;
    else
        status = false;

return status;

}

template<class T>
bool Sstack<T>::isempty()
{
    bool status;

    if (top == -1)
        status = true;
    else
        status = false;

return status;

}

template<class T>
Sstack<T>::~Sstack<T>()    //deconstructor
{
    if (stackarray>0)
        delete [] stackarray;
}
