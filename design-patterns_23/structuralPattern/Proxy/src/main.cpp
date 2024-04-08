// main.cpp

#include <iostream>
#include "../include/Proxy.h"

using namespace std;

int main(int argc, char* argv[]) {
  Subject* sub = new ConcreteSubject();
  Proxy* p = new Proxy(sub);
  p->Request();

  return 0;
}