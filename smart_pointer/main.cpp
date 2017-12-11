/*******************************************************************************
 * FILE: this file is designed to test the features of smart pointer of CPP
 * Author: Zehuan Wang zehuanw@nvidia.com
 * Compile: g++ -std=c++14 main.cpp
 ******************************************************************************/

#include <iostream>
#include <memory> //need to include this
using namespace std;


class Foo{
private:
  int a_;
public:
  Foo(int a):a_(a) {cout << "call constructor" << endl;}
  ~Foo(){cout << "call destructor" << endl;}

};


int main(){
  /* test shared_ptr */
  shared_ptr<Foo> spt = make_shared<Foo>(10); //a good way to new a shared pointer
  cout << spt.unique() << endl; //1

  shared_ptr<Foo> spt2 = spt;
  cout << spt.unique() << endl; //0
  cout << spt2.unique() << endl; //0
  cout << spt.use_count() << endl; //2
  cout << spt2.use_count() << endl; //2
  
  {
    shared_ptr<Foo> spt3(spt2); //same as =
    cout << spt2.use_count() << endl; //3
    cout << spt3.use_count() << endl; //3
  }
  cout << spt2.use_count() << endl; //2

  spt2.reset();
  cout << spt2.use_count() << endl; //0
  cout << spt.use_count() << endl;  //1

 
  /* test unique_ptr*/
  unique_ptr<Foo> upt = make_unique<Foo>(10); //suppored in C++14
  //unique_ptr<Foo> upt2 = upt; //copy is not allow in unique_ptr
  
  return 0;
}
