#include <iostream>

//function declaration
int fibo(int n);
int nonRecFibo(int n);

int main(){
  //variable declaration
  int n;

  //input
  std::cout<<"Enter n: "<<std::endl;
  std::cin>>n;

  //recursive

  std::cout<<"Recursive Fibo: "<< fibo(n)<<std::endl;
  std::cout<<"NON-Recursive Fibo: "<< nonRecFibo(n)<<std::endl;


    return 0;
  }

  //function definition
  int fibo(int n){
    if(n <= 1)
      return n;
    else
      return fibo(n-1) + fibo(n-2);
  }

  int nonRecFibo(int n){
    int i, a = 0, b = 1, f = 0;
    if(n <= 1)
      return n;
    else{

      for(i = 2; i <= n; i++){
        f = a + b;
        a = b;
        b = f;
      }
    }
    return f;
  }
