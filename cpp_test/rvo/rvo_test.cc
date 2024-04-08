#include <string>
#include <utility>

#include "big_object.h"

BigObject RVOTest() { return BigObject(); }



int main(int argc, char* argv[]) {
  BigObject();
  /*BigObject big_obj = */  // RVOTest();
  //   std::string test;
  //   const std::string& ref = std::move(test);
  return 0;
}