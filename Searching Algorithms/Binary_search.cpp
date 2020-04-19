#include <iostream>

//function declaration
int binarySearch(int *a, int n, int key);

int main(){
  //variable declaration
  int arr[10], i, key;

  //input
  std::cout<<"Enter elements of the array: "<<std::endl;
  for(i = 0; i < 10; i++)
  {
     std::cin>>arr[i];
  }

  std::cout<<"Enter key: "<<std::endl;
  std::cin>> key;

  //search
  i = binarySearch(arr, 10, key);
  //output
    if(i == -1)
      std::cout<< key<<" not found "<<std::endl;
    else
      std::cout<<key<<" found"<<std::endl;

    return 0;
  }

  //function definition
int binarySearch(int *a, int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    while(start <= end && a[mid] != key)
    {
      if(key < a[mid])
      {
          end = mid - 1;
      }
       else
      {
         start = mid + 1;
      }

      mid = (start + end) / 2;
    }
    if(start > end)
    {
        return -1;  //key not found
    }
return mid;
}
