#include <iostream>

//function declaration
int fact(int n);


int main(){
  //variable declaration
  int n;

  //input
  std::cout<<"Enter n:  "<<std::endl;
  std::cin>>n;

  //recursive fact

  std::cout<<"Recursion: "<< fact(n)<<std::endl;
  //non-recursive fact

    return 0;
  }

  //function definition
  int fact(int n){
    if(n == 0 || n == 1)
      return 1;
    else
      return n * fact(n-1);
  }

