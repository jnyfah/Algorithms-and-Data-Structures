#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include "const_iterator.h"



namespace customSTL
{

template<class T>
class vector
{


public:

    friend class iterator;


    vector(): vsize(0), capacity_size(1)
    {
        try
        {
            data = new T[capacity_size];

        }
        catch(std::bad_alloc)
        {
            memError();
        }
    }

    vector (const vector& other)
    {
        vsize = other.vsize;
        capacity_size = other.capacity_size;

        if(other.vsize > 0)
        {
            data = new T* [other.vsize];
            for(size_t i = 0; i < vsize; i++)
            {
                data[i] = other[i];
            }
        }
        else
        {
            data = nullptr;
        }
    }

    //returns size of vector
    size_t size() const noexcept
    {
        return vsize;
    }

    // returns vector capacity
    size_t capacity() const noexcept
    {
        return capacity_size;
    }

    // returns status of the vector
    bool empty() const noexcept
    {
        return(data != nullptr);
    }



    void assign(int newsize, const T& value )
    {
        vsize = newsize;

        for(size_t i = 0; i<vsize; i++)
        {
            data[i] = value;
        }
    }

    void push_back(const T& item)
    {
        if(vsize <= capacity_size)
        {
            expand();
        }
        data[vsize] = item;
        vsize++;
    }

    void pop_back()
    {
        vsize--;
    }



    //inserting at any location
    iterator<T> insert( iterator<T> pos, const T& value )
    {
        int i = vsize;
        if(capacity_size <= vsize)
        {
            expand();
        }

        for(iterator<T> it = end(); it != pos; it--)
        {
            i--;
            data [i+1] = data [i];

        }

        *pos = value;
        vsize++;
    }


    // inserts count copies of the value before pos
    void insert( iterator<T> pos, size_t count, const T& value )
    {
        int i = vsize;
        if((capacity_size -vsize) < count)
        {
            expand();
        }

        for(iterator<T> it = end(); it != vsize; it--)
        {
            i--;
            data [i+count] = data [i];

        }
        for( size_t j = 0; j < count; j++)
        {
            data[ i+j ] = value;
        }

        vsize+=value;
    }


    void insert(iterator<T> pos, iterator<T> first, iterator<T> last )
    {
        size_t i=0, n=0;
        size_t j = vsize;

        for(auto it = first; it!=last; it++)   //get number of elements in range
        {
            i++;
        }
        if((capacity_size - vsize) < i )  //increase the capacity if necessary
        {
            expand();
        }

        T* temp = new T[i];

        for(auto it = first; it!=last; it++)
        {
            temp[n] = *it ;
            n++;
        }

        for(iterator<T>it = end(); it != pos; it--)
        {
            j--;
            data [j+i] = data [j];

        }

        for( size_t n = 0; n < i; n++)
        {
            data [j + n] = temp[n];
        }
        vsize+=i;
        delete []temp;

    }

    void swap(vector& other1, vector& other2) noexcept
    {
        vector<T> temp;
        temp = other1;
        other1 = other2;
        other2 =temp;

        delete temp;

    }




    /**Element access
       *operator[]
       * at
       * front
       * back
    **/

    T& operator[]( size_t pos ) const
    {

        return data[pos];
    }

    T& at( size_t pos ) const
    {
        if(pos < 0 || pos > vsize)   //if subscript is out of bound
        {
            std::cout << "ERROR: Subscript out of range. \n";

            exit(EXIT_FAILURE);
        }

        return data[pos];
    }

    T& front() const
    {
        return data[0];
    }

    T& back() const
    {
        return data[0];
    }





    //operators

    vector& operator=(vector&& other ) noexcept
    {

        vsize = other.vsize;
        capacity_size = other.capacity_size;

        data = new T[capacity_size];

        for(unsigned int i=0; i<other.vsize; i++)
        {
            data[i]=other.data[i];
        }
        return *this;
    }

    friend bool operator ==(vector &first, vector &second)
    {
        if(first.size() != second.size())
        {
            return false;
        }
        else
        {
            for(size_t i = 0; i < first.size(); i++)
            {
                if(first[i] != second[i])
                    return false;
            }
        }

        return true;
    }

    friend bool operator !=(vector &first, vector &second)
    {
        return !(first == second);
    }


    friend bool operator < (vector &first, vector &second)
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

    friend bool operator > (vector &first, vector &second)
    {
        return !(first < second);
    }

    friend bool operator <= (vector &first, vector &second)
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

    friend bool operator >= (vector &first, vector &second)
    {
        return !(first <= second);
    }


    // non const iterators

    iterator<T> begin() noexcept
    {
        return iterator<T>(data);
    }

    iterator<T> end() noexcept
    {
        return iterator<T>(data + vsize);
    }

    iterator<T> rend() noexcept
    {
        return iterator<T>(data);
    }

    iterator<T> rbegin() noexcept
    {
        return iterator<T>(data + vsize);
    }

    // const iterators

    iterator<T>  cbegin() const noexcept
    {
        return iterator<T> (data);
    }


    iterator<T>  cend() const noexcept
    {
        return iterator<T> (data + vsize);
    }

    const_iterator<T> crbegin() const noexcept
    {
        return const_iterator<T>(data + vsize);
    }

    iterator<T>  crend() const noexcept
    {
        return iterator<T> (data);
    }


    void clear() noexcept
    {
        vsize = 0;
        capacity_size = 1;
        delete [] data;
    }

    ~vector()
    {
        delete [] data;
        vsize = 0;
        capacity_size = 1;
    }



private:
    T* data;
    size_t vsize;
    size_t capacity_size;
    void expand()
    {
        capacity_size *= 2;

        T* newdata = new T[capacity_size];

        for(size_t i = 0; i < vsize; i++)
        {
            newdata[i] = data[i];
        }
        delete [] data;
        data = newdata;


    }

    void subsError()
    {
        std::cout << "ERROR: Subscript out of range. \n";

        exit(EXIT_FAILURE);
    }



    void memError()
    {
        std::cout << "ERROR:Cannot allocate memory \n";

        exit(EXIT_FAILURE);
    }

};


}
#endif // VECTOR_H
