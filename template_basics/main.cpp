/**
 * FILE: this sample demostrate template basics
 * Compile: g++ -std=c++11 main.cpp
 **/

#include "header.hpp"

int main(){
  Item<Trait<0>, Trait<1>>::print_type();
  //using template parameters of template you don't need to put actual parameter into template parameters. Imagine that there can be several templates have the same template parameters list but different behaviors. It looks like another kind of inherence.
  Container<Item>::print_print_type(); 

  typedef ElementT<std::vector<int>>::Type type_;
  std::cout << typeid(type_).name() << std::endl;
  func<int>(10);
  func2(10);
  return 0;
}
