
template<class T>
void insertionsort(T data[], int size)
{
    int i, j;

   for(i=1; i<size; i++)
   {
       T temp = data[i];

       for(j =i-1; j>=0 && data[j] > temp; j-- )
       {
              data[j + 1] = data[j];
       }

       data[j+1] =temp;
   }
}
