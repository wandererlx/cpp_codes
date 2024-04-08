#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <typeinfo>
#include <vector>

#include "class_define.h"

struct PODTest {
  PODTest() {}
  char B() { return b; }

 private:
  char a[7];
  char b;
};

struct PODTest2 {
  char a[7];
  char b;
};

int main(int argc, char* argv[]) {
  std::vector<bool> a{true, true};
  auto flag = a[1];
  
  PODTest pod_test;
  PODTest2 pod_test2;
  // std::cout << "std::is_pod<PODTest>:" << std::is_pod<PODTest>::value
  //           << ", sizeof:" << sizeof(pod_test) << std::endl;

  // std::cout << "std::is_pod<PODTest2>:" << std::is_pod<PODTest2>::value
  //           << ", sizeof:" << sizeof(pod_test2) << std::endl;
  std::cout << sizeof(bool) << std::endl;
  Test* test = new Test11();
  std::cout << typeid(a[0]).name() << std::endl;
  std::cout << typeid((new Test11())).name() << std::endl;
  return 0;
}