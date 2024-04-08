// main.cpp

#include <iostream>
#include "../include/Facade.h"

using namespace std;

int main(int argc, char* argv[]) {
  Facade* f = new Facade();
  f->OperationWrapper();

  return 0;
}