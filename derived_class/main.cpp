#include <iostream>
using namespace std;

class base_class {
private:
  int A;
  void print_A(){cout<< A << endl;}
protected:
  int B;
  void print_B(){cout<< B << endl;}
public:
  int C;
  void print_C(){cout<< C << endl;}
  base_class(): A(0), B(1), C(2){};
};


class derived_class: public base_class{
private:
  int d_A;
  void d_print_A(){cout<< d_A << endl;}
protected:
  int d_B;
  void d_print_B(){cout<< d_B << endl;}
public:
  int d_C;
  void d_print_C(){cout<< d_C << endl;}


  derived_class(): d_A(3), d_B(4), d_C(5){};
  /* can derived_class access members of it own? */
  void d_print_A_om(){cout<< d_A <<endl;}
  void d_print_B_om(){cout<< d_B << endl;}
  void d_print_C_om(){cout<< d_C << endl;}
  
  /* can derived_class access members of it derived? */
  //void d_print_A_bm_p(){cout << A << endl;} //error: ‘int base_class::A’ is private
  void d_print_B_bm_p(){cout << B << endl;} 
  void d_print_C_bm_p(){cout << C << endl;}

  /* can derived_class access functions of it derived? */
  //void d_print_A_bm_f(){print_A();} //error: ‘void base_class::print_A()’ is private
  void d_print_B_bm_f(){print_B();} 
  void d_print_C_bm_f(){print_C();} 

  /* can derived_class access member functions (derived from base class)of the derived class passed in? */
  //void d_print_A_o_bm_f(derived_class& obj){obj.print_A();} //error: ‘void base_class::print_A()’ is private
  void d_print_B_o_bm_f(derived_class& obj){obj.print_B();} 
  void d_print_b_o_bm_f(derived_class& obj){obj.print_C();}

  /* can derived_class access member parameters (derived from base class) of the derived class passed in? */
  //void d_print_A_o_bm_p(derived_class& obj){cout << obj.A << endl;} //error: ‘int base_class::A’ is private
  void d_print_B_o_bm_p(derived_class& obj){cout << obj.B << endl;}
  void d_print_C_o_bm_p(derived_class& obj){cout << obj.C << endl;}

  /* can derived_class access member functions of the derived class passed in? */
  void d_print_A_o_om_f(derived_class& obj){obj.d_print_A();}
  void d_print_B_o_om_f(derived_class& obj){obj.d_print_B();}
  void d_print_C_o_om_f(derived_class& obj){obj.d_print_C();}
  

  /* can derived_class access member parameters of the derived class passed in? */
  void d_print_A_o_om_p(derived_class& obj){cout << obj.d_A << endl;}
  void d_print_B_o_om_p(derived_class& obj){cout << obj.d_B << endl;}
  void d_print_C_o_om_p(derived_class& obj){cout << obj.d_C << endl;}

  /* can derived_class access member functions of the derived class passed in? */
  //void d_print_A_b_f(base_class& obj){obj.print_A();} //error: ‘void base_class::print_A()’ is private
  //void d_print_B_b_f(base_class& obj){obj.print_B();} //error: ‘void base_class::print_B()’ is protected
  void d_print_C_b_f(base_class& obj){obj.print_C();}
  
  /* can derived_class access member parameters of the derived class passed in? */
  //void d_print_A_b_p(base_class& obj){cout << obj.A << endl;} //error: ‘int base_class::A’ is private
  //void d_print_B_b_p(base_class& obj){cout << obj.B << endl;} //error: ‘int base_class::B’ is protected
  void d_print_C_b_p(base_class& obj){cout << obj.C << endl;}

  
};


int main(){
  base_class base;
  derived_class derived;

  return 0;
}
