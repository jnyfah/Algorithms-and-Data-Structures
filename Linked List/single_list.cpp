#include "single_list.h"
#include<iostream>

template<class T>
bool single_list<T>::isempty()
{
    bool status;
     if(head == nullptr)
     {
         status = true;
     }else {
        status = false;
     }

     return  status;
}

template<class T>
void single_list<T>::append_list(T num)
{
    node *newnode;
    node *nodeptr;

    newnode = new node;
    newnode->item = num;
    newnode->next = nullptr;

    if(isempty())
    {
       head = newnode;
    }else {
       nodeptr = head;
       while(nodeptr->next != nullptr)
       {
           nodeptr= nodeptr->next;
       }

       nodeptr->next = newnode;
    }
}

template<class T>
void single_list<T>::display_list()
{

    if(isempty())
    {
       std::cout<<"list is empty"<<std::endl;

    }else {

      node *nodeptr;
      nodeptr = head;

       while(nodeptr)
       {
           std::cout<<nodeptr->item<<std::endl;

           nodeptr= nodeptr->next;
       }
    }
}

template<class T>
void single_list<T>::insert_list(T num)
{
    node *newnode, *nodeptr, *prevnode = nullptr;


    newnode = new node;
    newnode->item = num;
    newnode->next = nullptr;

    if(isempty())
    {
       head = newnode;

    }else {
       nodeptr = head;

       while(nodeptr->next != nullptr && nodeptr->item < num)     // Skip all nodes whose value is less than num
       {
           prevnode = nodeptr;
           nodeptr= nodeptr->next;
       }

       if (prevnode == nullptr)  // if the new element is the smallest
       {

         head = newnode;
         newnode->next = nodeptr;

       }else {

         prevnode->next = newnode;
         newnode->next = nullptr;

       }
    }
}

template<class T>
void single_list<T>::delete_list(T num)
{
    node *nodeptr, *prevnode = nullptr;


    if(isempty())
    {
        std::cout<<"list is empty"<<std::endl;
    }

    if(head->item==num)    // determine if the first node is the one
    {
        nodeptr = head->next;
        delete head;
        head = nodeptr;

    }else {

          nodeptr = head;
          while(nodeptr != nullptr && nodeptr->item != num)
          {
              prevnode = nodeptr;
              nodeptr = nodeptr->next;
          }

          if(nodeptr)
          {
              prevnode->next = nodeptr->next;
              delete nodeptr;
          }
    }
}

template<class T>
single_list<T>::~single_list()
{
    node *nodeptr, *nextnode;

    nodeptr = head;
    while(nodeptr->next != nullptr)
    {
        nextnode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextnode;
    }

}
