// main.cpp
#include <iostream>
#include "../include/Prototype.h"
using namespace std;

int main(int argc, char* argv[]) {
  Prototype* p = new ConcretePrototype();
  Prototype* p1 = p->Clone();
  return 0;
}