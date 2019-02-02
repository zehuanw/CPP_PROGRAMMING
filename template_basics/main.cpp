/**
 * FILE: this sample demostrate template basics
 * Compile: g++ -std=c++11 main.cpp
 **/

#include "header.hpp"

int main(){
  Item<Trait<0>, Trait<1>>::print_type();
  return 0;
}
