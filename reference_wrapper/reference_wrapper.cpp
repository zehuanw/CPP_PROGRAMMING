#include <iostream>
#include <functional>
#include <vector>

int main(){
  /* test 1: pass reference_wrapper to vector */
  int a(10), b(20), c(30);
  std::vector<std::reference_wrapper<int>> v;
  v.push_back(std::ref(a));
  v.push_back(std::ref(b));
  v.push_back(std::ref(c));
  
  for(std::vector<std::reference_wrapper<int>>::iterator iter = v.begin(); iter != v.end(); iter++){
    iter->get() = 1;
  }
  //111
  std::cout << a << b << c;
  return 0;
}
