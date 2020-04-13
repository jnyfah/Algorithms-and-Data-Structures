template<class T>
void shellsort(T data[], int size)
{
    int gap, i, j;

   for(gap=size/2; gap>0; gap /= 2)
   {
       for(i = gap; i<size; i++)
       {
             T temp = data[i];

             for(j =i; j>=gap && temp<data[j-gap]; j-=gap )
             {
                    data[j]= data[j-gap];
             }

           data[j] = temp;
       }
   }
}
