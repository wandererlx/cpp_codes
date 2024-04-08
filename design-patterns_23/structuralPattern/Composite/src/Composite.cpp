// Composite.cpp

#include "../include/Composite.h"
#include "../include/Component.h"

Composite::Composite() { vector<Component*>::iterator itend = comVec.end(); }
Composite::~Composite() {}
void Composite::Operation() {
  vector<Component*>::iterator comIter = comVec.begin();
  for (; comIter != comVec.end(); comIter++) {
    (*comIter)->Operation();
  }
}
void Composite::Add(Component* com) { comVec.push_back(com); }
void Composite::Remove(Component* com) {
    comVec.pop_back();
}
Component* Composite::GetChild(int index) { return comVec[index]; }