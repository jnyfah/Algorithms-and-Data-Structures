#include <iostream>

int gcd(int x, int y);

int main(){
  int a, b, g;

  std::cout<<"Enter a and b:\n";
  scanf("%d%d", &a, &b);

  //gcd
  g = gcd(a, b);

  //in case g is negative, then convert it into positive
  if(g < 0){
    g *= -1;
  }

     std::cout<<"GCD("<< a<<","<<b<<")" <<" is " << g<<std::endl;
    return 0;
  }

  int gcd(int x, int y){
    if(y == 0)
        return x;
    else
        gcd(y, x%y);
  }
