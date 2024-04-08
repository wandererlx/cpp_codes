// Iterator.cpp

#include "../include/Iterator.h"
#include <iostream>
#include "../include/Aggregate.h"

using namespace std;

Iterator::Iterator(/* args */) {}
Iterator::~Iterator() {}

ConcreteIterator::ConcreteIterator(Aggregate*ag , int idx) {
    this->_ag = ag;
    this->_idx = idx;
}
ConcreteIterator::~ConcreteIterator() {}
Object ConcreteIterator::CurrentItem(){
    return _ag->GetItem(_idx);
}
void ConcreteIterator::First(){
    _idx = 0;
}
void ConcreteIterator::Next(){
    if (_idx < _ag->GetSize()) _idx++;
}
bool ConcreteIterator::IsDone(){
    return (_idx == _ag->GetSize());
}