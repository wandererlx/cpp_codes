//Adapter.cpp

#include "../include/Adapter.h"
#include <iostream>

//类模式的Adapter
Adapter::Adapter() {}

Adapter::~Adapter() {}

void Adapter::Request() {
  cout << "Adapter::Request()" << endl;
  this->SpecificRequest();
  cout << "----------------------------" << endl;
}

//对象模式的Adapter
Adapter1::Adapter1() : _adaptee(new Adaptee) {}

Adapter1::Adapter1(Adaptee* _adaptee) { this->_adaptee = _adaptee; }

Adapter1::~Adapter1() {}

void Adapter1::Request() {
  cout << "Adapter1::Request()" << endl;
  this->_adaptee->SpecificRequest();
  cout << "----------------------------" << endl;
}