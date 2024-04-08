// Template.cpp

#include "../include/Template.h"
#include <iostream>

using namespace std;

AbstractClass::AbstractClass(/* args */) {}
AbstractClass::~AbstractClass() {}
void AbstractClass::TemplateMethod() {
  this->PrimitiveOperation1();
  this->PrimitiveOperation2();
}

ConcreteClass1::ConcreteClass1(/* args */) {}
ConcreteClass1::~ConcreteClass1() {}
void ConcreteClass1::PrimitiveOperation1() { printf("ConcreteClass1...PrimitiveOperation1 \n"); }
void ConcreteClass1::PrimitiveOperation2() { printf("ConcreteClass1...PrimitiveOperation2 \n"); }

ConcreteClass2::ConcreteClass2(/* args */) {}
ConcreteClass2::~ConcreteClass2() {}
void ConcreteClass2::PrimitiveOperation1() { printf("ConcreteClass2...PrimitiveOperation1 \n"); }
void ConcreteClass2::PrimitiveOperation2() { printf("ConcreteClass2...PrimitiveOperation2 \n"); }
