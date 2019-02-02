#include <iostream>

//template specialization
template<int ID>
class Trait;

template<>
class Trait<1>{
public:
  typedef int OP;
};

template<>
class Trait<0>{
public:
  typedef float OP;
};

//template class
template<typename T1, typename T2>
class Item{
public:
  typedef typename T1::OP OP1; //whenever use member of template param should add typename key words.
  typedef typename T2::OP OP2;
  static void print_type() {
    std::cout << "OP1: " << typeid(OP1).name() << std::endl;
    std::cout << "OP2: " << typeid(OP2).name() << std::endl;
  }
};

//template over write
