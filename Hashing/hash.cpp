#include<iostream>
#include<string>
#include "hash.h"


hash::hash()
{
    for (int i = 0; i < tablesize; i++) {

        hashtable[i] = new node;
        hashtable[i]->key = "empty";
        hashtable[i]->item = "empty";
        hashtable[i]->next = nullptr;

    }
}



int hash::hashy(std::string key)   //hash function
{
    int index, hash = 0;

    for(int i = 0; i< static_cast<int>(key.length()); i++)
    {
        hash += static_cast<int>(key[i]);
    }

    index = hash % tablesize;

    return index;

}



void hash::insert(std::string key, std::string value)
{
    int index = hashy(key);

    if(hashtable[index]->key == "empty")
    {
       hashtable[index]->key = key;
       hashtable[index]->item = value;

    } else {
        node* nodeptr = hashtable[index];

        node* newnode = new node;
        newnode->key = key;
        newnode->item = value;
        newnode->next = nullptr;

        while(nodeptr->next != nullptr)  //traverse the list
        {
            nodeptr = nodeptr->next;
        }

        nodeptr->next = newnode;  // add  new node
}

}



void hash::display()
{
    for(int i = 0; i<tablesize; i++)
    {
        std::cout<<hashtable[i]->key<<"    ";
        std::cout<<hashtable[i]->item<<std::endl;

        if(hashtable[i]->next != nullptr)
        {

            node* nodeptr = hashtable[i];

            while(nodeptr->next!= nullptr)
            {
                nodeptr = nodeptr->next;
                std::cout<<nodeptr->key<<"    ";
                std::cout<<nodeptr->item<<std::endl;

            }
        }
    }
}


void hash::find(std::string key)
{
     int index = hashy(key);
     node* nodeptr = hashtable[index];

     while(nodeptr != nullptr)
     {
         if(nodeptr->key == key)
         {

             std::cout<<key<<"    ";
             std::cout<<nodeptr->item<<std::endl;
             std::cout<<std::endl;

         }

         nodeptr= nodeptr->next;
     }
}



void hash::remove(std::string key)
{
    int index = hashy(key);
    node* delptr;
    node* prevptr;
    node* nodeptr;

    //if bucket is empty
    if(hashtable[index]->key == "empty" && hashtable[index]->item == "empty")
    {
        std::cout<< key <<" was not found"<<std::endl;
        std::cout<<std::endl;
    }
    else if(hashtable[index]->key == key && hashtable[index]->next == nullptr)
    {

        hashtable[index]->key = "empty";

        hashtable[index]->item = "empty";

        std::cout<<"done"<<std::endl;
        std::cout<<std::endl;

    }
    else if(hashtable[index]->key == key && hashtable[index]->next != nullptr)
    {
        delptr = hashtable[index];

        hashtable[index] = hashtable[index]->next;

        delete delptr;

        std::cout<<"done"<<std::endl;
        std::cout<<std::endl;
    }

    else {
        prevptr = hashtable[index];
        nodeptr = hashtable[index]->next;

        while (nodeptr != nullptr && nodeptr->key != key )
        {
            prevptr = nodeptr;
            nodeptr = nodeptr->next;
        }

        if(nodeptr == nullptr)
        {
            std::cout<< key <<" was not found"<<std::endl;
        }
        else {

            delptr = nodeptr;

            nodeptr = nodeptr->next;

            prevptr->next = nodeptr;

            delete delptr;

            std::cout<<"done"<<std::endl;
            std::cout<<std::endl;
        }
    }
}
