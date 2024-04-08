//
// Created by shawnunili on 2019/3/2.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "concurent/ability.h"

using namespace std;
using namespace xct;

class A {
  public:
  void Fun1() {
    Fun2();
    b = 0;
  }
  static void Fun2() {
    // Fun1();
    b = 0;
    // a = 0;
  }
  private:
  int a;
  static int b;
};

int main(int argc, char *argv[]) {
  A a;
  a.Fun2();
  A::Fun2();
  A::Fun1();
  std::string str(1000, 'a');
  cout << sizeof(str) << endl;
  str = "lllllll";
  cout << sizeof(str) << endl;
  
  return 0;
}