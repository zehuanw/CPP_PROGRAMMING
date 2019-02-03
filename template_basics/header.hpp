#include <iostream>
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
