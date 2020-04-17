#include <iostream>

//const
const int MAX = 10;

//function declaration
void display(int[], int);
int getMax(int[], int);
void countingSort(int[], int);

int main() {
  //unsorted elements
  int arr[] = {10,15,1,60,5,100,25,50};

  //size of the array
  int n = sizeof(arr)/sizeof(arr[0]);

  //output unsorted elements
  display(arr, n);

  //sort the elements
  countingSort(arr, n);

    //display sorted elements
    display(arr, n);

    return 0;
  }

void display(int arr[], int size)
{

    for(int i = 0; i < size; i++) {
     std::cout<<arr[i]<<" ";
    }
    printf("\n");
  }

int getMax(int arr[], int size)
{
    int i, max = arr[0];
    for(i = 1; i < size; i++)
    {
      if(arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }

void countingSort(int arr[], int size)
{
    int i, max, temp[MAX], count[10], expo = 1;

      max = getMax(arr, size);  //get the max value element in the unsorted array

      while(max / expo > 0) {
        //reset count
        for(i = 0; i < 10; i++)
        {
          count[i] = 0;
        }

        //save count of the occurrence
        for(i = 0; i < size; i++) {
          count[ (arr[i] / expo) % 10 ]++;
        }

        //set count to contain the actual position of the digits
        for(i = 1; i < size; i++) {
          count[i] += count [i - 1];
        }

        //build the result
            for(i = size - 1; i >= 0; i--) {
              temp[ count[ (arr[i]/expo) % 10 ]  - 1] = arr[i];
              count[ (arr[i]/expo) % 10 ]--;
            }

            //copy the result to arr
            for(i = 0; i < size; i++) {
              arr[i] = temp[i];
            }

            //increase expo, 10^x
            expo *= 10;
          }
        }
