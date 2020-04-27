#include <iostream>

//function declaration
int linearSearch(int *a, int n, int key);

int main(){
  //variable declaration
    int arr[5] = {2,5,7,4,1};
    int i, key = 7;


    i = linearSearch(arr, 5, key);

    //output
    if(i == -1)
      std::cout<<"Key not found.\n";
    else
      std::cout<<"Key at index:" <<i<<std::endl;

    return 0;
  }

  //function definition
  int linearSearch(int *a, int n, int key){

    for(int i = 0; i <= n-1; i++)
    {
      if(a[i] == key)

        return i+1;
    }
     return -1;
   }
