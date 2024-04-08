// main.cpp

#include <iostream>
#include "../include/Component.h"
#include "../include/Composite.h"
#include "../include/Leaf.h"

using namespace std;

int main(int argc, char* argv[]) {
  Leaf* l = new Leaf();
  l->Operation();
  Composite* com = new Composite();
  com->Add(l);
  com->Operation();
  Component* ll = com->GetChild(0);
  ll->Operation();

  return 0;
}