// Element.cpp

#include "../include/Element.h"
#include <iostream>
#include "../include/Visitor.h"

using namespace std;

Element::Element(/* args */) {}
Element::~Element() {}
void Element::Accept(Visitor* vis) {}

ConcreteElementA::ConcreteElementA(/* args */) {}
ConcreteElementA::~ConcreteElementA() {}
void ConcreteElementA::Accept(Visitor* vis) {
  vis->VisitConcreteElementA(this);
  printf("visiting ConcreteElementA... \n");
}

ConcreteElementB::ConcreteElementB(/* args */) {}
ConcreteElementB::~ConcreteElementB() {}
void ConcreteElementB::Accept(Visitor* vis) {
  vis->VisitConcreteElementA(this);
  printf("visiting ConcreteElementA... \n");
}