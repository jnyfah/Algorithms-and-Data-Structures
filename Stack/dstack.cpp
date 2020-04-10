#include "dstack.h"
#include<iostream>


template<class T>
void Dstack<T>::push(T value)
{
   node *newnode = nullptr;

   newnode = new node;
   newnode->item = value;

   if(isempty())
   {
       top = newnode;
       newnode->next = nullptr;
   }else {                        // insert NewNode before top.
       newnode->next = top;
       top = newnode;
   }

}

template<class T>
void Dstack<T>::pop(T &value)
{
    node *temp = nullptr;

    if(isempty())
    {
        std::cout<<"stack is empty"<<std::endl;
    }else {
        value= top->next;
         temp = top->next;
         delete top;
         top = temp;
}
}

template<class T>
bool Dstack<T>::isempty()
{
    bool status;
    if(!top)
        status = true;
    else
        status = false;

    return status;
}

template<class T>      // deconstructor
Dstack<T>::~Dstack()
{
    node *nodeptr, *nextnode;

    nodeptr = top;
    while(nodeptr->next != nullptr)
        nextnode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextnode;
}








