#include<iostream>

using namespace  std;

template<class T>
void selectionsort(T data[], int size)
{
    int i, j,least;

   for(i=0; i<size-1; i++)
   {
       least = i;

       for(j =i+1; j<size; j++ )
       {
              if(data[j]<data[least])   // look for the least
              {
                  least = j;
              }

       }
       T temp = data[i];

       data[i] = data[least];

       data[least] = temp;
       //std::swap(data[temp], data[i]);
   }
}
