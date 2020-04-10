#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

template<class T>
class single_list
{
private:
    struct node{
      T item;
      node *next;
    };
    node *head;
public:
    single_list()
    {
        head = nullptr;
    }

    bool isempty();
    void append_list(T);     //unordered
    void display_list();    //transversing a linked list
    void insert_list(T);    //ordered
    void delete_list(T);
    ~single_list();



};

#include "single_list.cpp"

#endif // SINGLE_LIST_H
