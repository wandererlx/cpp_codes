// Proxy.cpp

#include "../include/Proxy.h"
#include <iostream>

using namespace std;

Subject::Subject(/* args */) {}
Subject::~Subject() {}

ConcreteSubject::ConcreteSubject(/* args */) {}
ConcreteSubject::~ConcreteSubject() {}
void ConcreteSubject::Request() { printf("ConcreteSubject......request.... \n"); }

Proxy::Proxy(/* args */) {}
Proxy::Proxy(Subject* sub) { _sub = sub; }
Proxy::~Proxy() { delete _sub; }
void Proxy::Request() {
  printf("Proxy request.... \n");
  _sub->Request();
}