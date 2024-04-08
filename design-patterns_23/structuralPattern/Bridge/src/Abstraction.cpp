//Abstraction.cpp

#include "../include/Abstraction.h"
#include "../include/AbstractionImp.h"

#include <iostream>
using namespace std;

Abstraction::Abstraction(/* args */) {}
Abstraction::~Abstraction() {}

RefinedAbstraction::RefinedAbstraction(AbstractionImp* imp) {
    _imp = imp;
}
RefinedAbstraction::~RefinedAbstraction() {}
void RefinedAbstraction::Operation(){
    _imp->Operation();
}