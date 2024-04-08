// main.cpp

#include <iostream>
#include "../include/Observer.h"
#include "../include/Subject.h"

using namespace std;

int main(int argc, char* argv[]) {
  ConcreteSubject* sub = new ConcreteSubject();
  Observer* o1 = new ConcreteObserverA(sub);
  Observer* o2 = new ConcreteObserverB(sub);
  sub->SetState("old");
  sub->Notify();
  sub->SetState("new");  // 也可以由 Observer 调用
  sub->Notify();

  return 0;
}
