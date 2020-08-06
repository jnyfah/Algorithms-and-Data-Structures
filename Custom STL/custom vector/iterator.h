#ifndef ITERATOR_H
#define ITERATOR_H


template<class T>
class iterator
{

public:

    iterator(T* data)
    {
        ptr = data;
    }

    //operators

    bool operator !=(const iterator &other)
    {
        return (this->ptr != other.ptr);
    }

    iterator& operator ++()  //prefix
    {
        ptr++;
        return  *this;
    }

    iterator& operator +(int x)
    {
        ptr+=x;
        return  *this;
    }
    iterator& operator -(int x)
    {
        ptr -= x;
        return  *this;
    }

    iterator& operator ++(int)  //postfix
    {
        ++ptr;
        return  *this;
    }

    iterator& operator --()   //prefix
    {
        ptr--;
        return  *this;
    }

    iterator& operator --(int) //postfix
    {
        --ptr;
        return  *this;
    }

    T& operator *()
    {
        return *ptr;
    }




private:
    T* ptr;
};


#endif // ITERATOR_H
