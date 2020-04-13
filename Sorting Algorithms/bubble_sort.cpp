#include<iostream>

using namespace  std;

template<class T>
void bubblesort(T data[], int size)
{
    bool swap;
    int temp;
      do
    {
        swap = false;

        for (int i = 0; i < (size - 1); i++)
        {
            if (data[i] > data[i + 1])
            {
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;

                swap = true;

            }
        }
    } while (swap);
}

