/**
 * Compile: g++ -std=c++11 main.cpp
 **/

#include <iostream>

int main(){
  class Func{
  public:
    Func(int* out, int in){
      *out = in + 1;
    }
  };

  ////error: a function-definition is not allowed here before ‘{’ token
  // void func2(){
  //   std::cout << "func" << std::endl;
  // }

  int out = 0;
  int in = 1;
  Func(&out, in);
  std::cout << "out = " << out << std::endl;
  return 0;
}
