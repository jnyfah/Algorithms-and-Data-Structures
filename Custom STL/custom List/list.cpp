#ifndef LIST_H
#define LIST_H
#include <iostream>


namespace customSTL
{

template<class T>
class list
{

public:
    class iterator;

    //constructors
    list () :lsize(0), head(nullptr), tail(nullptr) {}



    list(int n, T data)
    {
        node *newNode = help_makenode(data);
        for(int i = 0; i< n; i++)
        {
            help_insert(head, newNode);
        }
    }

    list(const list& other)
    {
        node* nodeptr = head;

        other.lsize = lsize;

        while(nodeptr)
        {
            other.pushback(nodeptr->data);
            nodeptr = nodeptr->next;
        }
    }


// Capacity

    size_t size()
    {
        return lsize;
    }


    bool empty()
    {
        if(head)
            return false;
        else
            return true;
    }


// Modifiers

    void pushback(T data)
    {
        node *newNode = help_makenode(data);

        help_insertBack(head, newNode);
    }


    void popback()
    {
        node *tempnode = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;

        delete tempnode;
        -- lsize;
    }


    void pushfront(T data)
    {
        node* nodeptr = help_makenode(data);
        help_insertFront(head, nodeptr);
    }

    void popfront()
    {
        node* tempnode = head;
        head = head->next;
        head->prev = nullptr;

        delete tempnode;
        --lsize;
    }

    void clear() noexcept
    {
        node *nodeptr =head;
        while(nodeptr != nullptr)
        {

            node *tempptr = nodeptr->next;
            delete nodeptr;
            nodeptr = tempptr;
            --lsize;
        }
    }




    //Element access
    T& front() const
    {
        return head->data;
    }

    T& back() const
    {
        return tail->data;
    }



    //Iterators

    iterator begin() noexcept
    {
        return iterator (head);
    }

    iterator end() noexcept
    {
        return iterator (tail);
    }

    iterator rbegin() noexcept
    {
        return iterator (tail);
    }

    iterator rend() noexcept
    {
        return iterator (head);
    }


    //Const Iterators

    iterator cbegin() const noexcept
    {
        return iterator (head);
    }

    iterator cend() const noexcept
    {
        return iterator (tail);
    }

    iterator crbegin() const noexcept
    {
        return iterator (tail);
    }

    iterator crend() const noexcept
    {
        return iterator (head);
    }

    //inserts
    iterator insert(iterator pos, T value)
    {
        node* nodeptr = head;

        iterator itr = begin();
        if(itr == this->begin())
        {
            this->pushfront(value);
        }
        else if(itr == this->end())
        {
            this->pushback(value);
        }
        else
        {
            for(; itr!=pos; itr++)
            {
                nodeptr = nodeptr->next;
            }

            node*  newnode = help_makenode(value);

            newnode->prev = nodeptr->prev;
            nodeptr->prev->next = newnode;
            nodeptr->prev = newnode;
            newnode->next =nodeptr;


            ++lsize;
        }

        return itr;
    }

    void insert(iterator pos, list&& other)
    {
        node* nodeptr = head;
        for(auto i = this->begin(); i!=pos; ++i)
        {
            nodeptr = nodeptr->next;
        }

        nodeptr->next->prev = other.end();
        nodeptr->next = other.begin();

    }

    //Operators

    list& operator =(list&& other)
    {
        node* nodeptr = head;

        other.lsize = lsize;

        while(nodeptr)
        {
            other.pushback(nodeptr->data);
            nodeptr = nodeptr->next;
        }
    }

    friend bool operator ==(list& first, list &second)
    {
        bool status = true;
        if(first.size() != second.size())
        {
            status = false;
        }
        else
        {
            for(auto itr1 = first.begin(); itr1!=first.end(); ++itr1)
            {
                for(auto itr2 = first.begin(); itr2!=first.end(); ++itr2)
                {
                    if(*itr1 != *itr2)
                    {
                        status = false;
                    }
                }
            }
        }

        return status;
    }

    friend bool operator !=(list& first, list &second)
    {
        return !(first == second);
    }


    friend bool operator < (list &first, list &second)
    {
        if((first.empty() && second.empty()) || (second.empty()) || (first.vsize > second.vsize))
        {
            return false;
        }
        else if (first.empty() || (first.vsize < second.vsize))
        {

            return true;
        }
        else if(first.size() == second.size())
        {
            if(first[0] < second[0])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    friend bool operator > (list &first, list &second)
    {
        return !(first < second);
    }

    friend bool operator <= (list &first, list &second)
    {
        if((first.empty() && second.empty()) || (second.empty()) || (first.vsize > second.vsize))
        {
            return false;
        }
        else if (first.empty() || (first.vsize < second.vsize))
        {

            return true;
        }
        else if(first.size() == second.size())
        {
            if(first[0] <= second[0])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    friend bool operator >= (list &first, list &second)
    {
        return !(first <= second);
    }


//Operators
    void merge(list &other)
    {
        for(auto i = other.begin(); i != other.end(); ++i)
        {
            pushback(*i);
        }
    }


    void remove(const T& value)
    {
        node* nodeptr = head;

        while(nodeptr->data != value)
            nodeptr = nodeptr->next;

        nodeptr->prev->next = nodeptr->next;
        nodeptr->next->prev = nodeptr->prev;

        delete nodeptr;
    }


    ~list()
    {
        clear();
    }
private:
    struct node
    {
        T data;
        node *next;
        node *prev;
    };
    node *head;
    node *tail;
    size_t lsize;



    node* help_makenode(T data)
    {
        node *newNode = nullptr;  // Pointer to a new node

        newNode = new node;

        newNode->data = data;

        newNode->next = nullptr;

        newNode->prev = tail;

        return newNode;
    }



    void help_insertBack(node *&nodePtr, node *&newNode)
    {
        if (nodePtr == nullptr)
        {
            nodePtr = newNode;    // Insert the node
            tail = nodePtr;
            ++lsize;
        }
        else
        {
            help_insertBack(nodePtr->next, newNode);
        }
    }

    void help_insertFront(node *&nodePtr, node *&newNode)
    {
        if (nodePtr == nullptr)
        {
            nodePtr = newNode;    // Insert the node
            ++lsize;
        }
        else
        {
            nodePtr->prev = newNode;
            newNode->next = nodePtr;
            nodePtr = newNode;
            ++lsize;
        }
    }

    bool help_search(node* nodeptr, T value)
    {
        bool status = false;
        while(nodeptr)
        {
            if(nodeptr->data != value)
                nodeptr->next;
            else
                status = true;
            break;
        }

    }
};






template<class T>
class list<T>::iterator
{

public:

    iterator(node* nodeptr)
    {
        ptr = nodeptr;
    }

    //operators

    bool operator !=(const iterator &other)
    {
        if((ptr->data != other.ptr->data) || (ptr->next != other.ptr->next) || (ptr->prev != other.ptr->prev))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator ==(const iterator &other)
    {
        return(!(ptr->data != other.ptr->data));
    }

    bool operator < (const iterator &other)
    {
        if((ptr->next < other.ptr->next) || (ptr->prev < other.ptr->prev))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator >(const iterator &other)
    {
        return(!(ptr->data < other.ptr->data));
    }

    bool operator <= (const iterator &other)
    {
        if((ptr->data <= other.ptr->data) || (ptr->next <= other.ptr->next) || (ptr->prev <= other.ptr->prev))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator >=(const iterator &other)
    {
        return(!(ptr->data <= other.ptr->data));
    }

    iterator& operator ++()  //prefix
    {
        ptr = ptr->next;
        return *this;
    }

    iterator& operator ++(int)  //postfix
    {
        ptr = ptr->next;
        return *this;
    }

    iterator& operator --()   //prefix
    {
        ptr = ptr->prev;
        return  *this;
    }

    iterator& operator --(int) //postfix
    {
        --ptr;
        return  *this;
    }


    iterator& operator +(int x)
    {
        for(int i = 0; i<x; i++)
        {
            ptr++;
        }
        return  *this;
    }
    iterator& operator -(int x)
    {
        for(int i = 0; i<x; i++)
        {
            ptr--;
        }
        return  *this;
    }

    T& operator *()
    {
        return ptr->data;
    }

private:
    node *ptr;

};




}
#endif // LIST_H




/*

#include <iostream>
#include "list.h"




int main()
{
    customSTL::list<int>x;
    customSTL::list<int>x1;
// customSTL::list<int>::iterator itr;

    x.pushback(3);
    x.pushback(4);
    x.pushback(5);
    x.pushback(6);
    x.pushback(7);
    x.pushfront(2);
    x.clear(7);
    
    auto ptr1 = x.end()++;



    for(auto i =x.begin(); i!=x.end(); ++i)
    {
        std::cout<<*i<<std::endl;
    }
    std::cout<<x.size();


}



*/
