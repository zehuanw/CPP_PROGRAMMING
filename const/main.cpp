/***********************************************************
 * This file is designed to demonstrate the use of const
 *
 ***********************************************************/

class BIA{
private:
  int a_;
public:
  void foo(int a) const{
    a_ = a; //error: assignment of member ‘BIA::a_’ in read-only object
  }
};

void foo(const int *a){
  //a[0] = 1;//error: assignment of read-only location ‘* a’
  return;
}

int main(){

  int array_a[10];
  int array_b[10];
  const int* a = array_a; //const data
  //a[0] = 1; // assignment of read-only location ‘* a’
  a = array_b; //right
  int* const b = array_a;
  b[0] = 1; //right
  //b = array_b; //error: assignment of read-only variable ‘b’
  int const *c = array_a;
  //c[0] = 1; // error: assignment of read-only location ‘* c’
  c = array_b;

  foo(array_a);
  return 0;
}
