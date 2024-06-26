// main.cpp

#include <iostream>
#include "../include/Element.h"
#include "../include/Visitor.h"

using namespace std;

int main(int argc, char* argv[]) {
  Visitor* vis = new ConcreteVisitorA();
  Element* elm = new ConcreteElementA();
  elm->Accept(vis);
  
  return 0;
}