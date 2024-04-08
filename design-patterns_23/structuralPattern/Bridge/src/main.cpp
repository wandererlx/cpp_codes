// main.cpp

#include <iostream>
#include "../include/Abstraction.h"
#include "../include/AbstractionImp.h"

using namespace std;

int main(int argc, char* argv[]) {
  AbstractionImp* imp = new ConcreteAbstractionImpA();
  Abstraction* abs = new RefinedAbstraction(imp);
  abs->Operation();

  return 0;
}