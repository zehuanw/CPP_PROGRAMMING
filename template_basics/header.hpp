#include <iostream>
#include <vector>
/*
 * Template parameters can be either "typename / int / template class / pointer"
 */

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


// typefunction
template<typename T>
class ElementT;

template<typename T>
class ElementT<std::vector<T>>{
public:
  typedef T Type;
};


// func requires T to be declared explicitly when instantiation.
template<typename T_>
struct func{
  func(T_ a){
    std::cout << "call ctor" << typeid(T_).name() << std::endl;
  }
};

template<typename T>
void func2(T a){
  std::cout << "func2" << std::endl;
}

////error: invalid use of incomplete type ‘class ElementT<std::vector<int> >’
// template<typename T_, template<typename> class Tclass_>
// class ElementT<Tclass_<T_>>{
// public:
//   typedef T_ Type;
// };

//static inherent
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

//Note* the different between Item and COntainer is:
//The final type of input class is determined within current class.

//template parameters of template
template<template<typename, typename> class _Item>
class Container{
private:
  typedef _Item<Trait<0>, Trait<1>> T01;
  typedef _Item<Trait<1>, Trait<0>> T10;
public:
  static void print_print_type() {
    //_Item::print_type(); Error: template parameter should be instantiate within template class.
    T01::print_type();
    T10::print_type();
  }
};

