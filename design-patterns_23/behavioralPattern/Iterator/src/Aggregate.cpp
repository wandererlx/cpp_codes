// Aggregate.cpp

#include "../include/Aggregate.h"
#include <iostream>
#include "../include/Iterator.h"

using namespace std;

Aggregate::Aggregate(/* args */) {}
Aggregate::~Aggregate() {}

ConcreteAggregate::ConcreteAggregate(/* args */) {
  for (int i = 0; i < SIZE; i++) _objs[i] = i;
}
ConcreteAggregate::~ConcreteAggregate() {}
Iterator* ConcreteAggregate::CreateIterator() { return new ConcreteIterator(this); }
Object ConcreteAggregate::GetItem(int idx) {
  if (idx < this->GetSize())
    return _objs[idx];
  else
    return -1;
}
int ConcreteAggregate::GetSize(){
    return SIZE;
}
