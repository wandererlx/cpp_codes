// main.cpp

#include <iostream>
#include "../include/Context.h"
#include "../include/Strategy.h"

using namespace std;

int main(int argc, char* argv[]) {
  Strategy* ps;
  ps = new ConcreteStrategyA();
  Context* pc = new Context(ps);
  pc->DoAction();
  if (NULL != pc) delete pc;

  return 0;
}