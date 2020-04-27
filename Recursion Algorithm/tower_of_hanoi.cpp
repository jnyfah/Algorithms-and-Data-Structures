#include <iostream>

void t(int n, char beg, char aux, char end);

int main(){
  std::cout<<"Moves" <<std::endl;
  t(3, 'a', 'b', 'c');  //N = 3 (no. of disks)  a, b, c are the three pegs
  return 0;
}//main() ends here

void t(int n, char beg, char aux, char end){
  if(n == 1){
    std::cout<<beg<<"--> "<<end<<std::endl;
  }else{
    t(n-1, beg, end, aux);
    t(1, beg, aux, end);
    t(n-1, aux, beg, end);
  }
}
