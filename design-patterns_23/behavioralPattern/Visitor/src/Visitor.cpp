// Visitor.cpp

#include "../include/Visitor.h"
#include <iostream>
#include "../include/Element.h"

using namespace std;

Visitor::Visitor(/* args */) {}
Visitor::~Visitor() {}

ConcreteVisitorA::ConcreteVisitorA(/* args */) {}
ConcreteVisitorA::~ConcreteVisitorA() {}
void ConcreteVisitorA::VisitConcreteElementA(Element* elm) {
  printf("I will visit ConcreteElementA... \n");
}
void ConcreteVisitorA::VisitConcreteElementB(Element* elm) {
  printf("I will visit ConcreteElementB... \n");
}

ConcreteVisitorB::ConcreteVisitorB(/* args */) {}
ConcreteVisitorB::~ConcreteVisitorB() {}
void ConcreteVisitorB::VisitConcreteElementA(Element* elm) {
  printf("I will visit ConcreteElementA... \n");
}
void ConcreteVisitorB::VisitConcreteElementB(Element* elm) {
  printf("I will visit ConcreteElementB... \n");
}