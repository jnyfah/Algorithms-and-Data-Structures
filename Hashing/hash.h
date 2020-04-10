#include<iostream>
#include<string>

#ifndef HASH_H
#define HASH_H



class hash
{
private:

    static const int tablesize  =10;

     struct node{           //seprate chaning collision
         std::string key;
         std::string item;
         node *next;
     };

    node* hashtable[tablesize];
    int hashy(std::string);

public:
    hash();
    void insert(std::string, std::string);
    void display();
    void find(std::string);
    void remove(std::string);
};


#include "hash.cpp"
#endif // HASH_H
