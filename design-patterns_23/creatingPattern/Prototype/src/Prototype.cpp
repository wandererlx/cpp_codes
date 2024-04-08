//Prototype.cpp

#include "../include/Prototype.h"
#include <iostream>

using namespace std;

Prototype::Prototype(/* args */) {}
Prototype::~Prototype() {}
Prototype* Prototype::Clone() const{
    return 0;
}

ConcretePrototype::ConcretePrototype(/* args */) {}
ConcretePrototype::~ConcretePrototype() {}
ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp){
    printf("ConcretePrototype copy ... \n");
}
Prototype* ConcretePrototype::Clone() const{
    return new ConcretePrototype(*this);
}
