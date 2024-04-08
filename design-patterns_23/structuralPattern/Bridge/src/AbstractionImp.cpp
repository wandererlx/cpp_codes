// AbstractionImp.cpp

#include "../include/AbstractionImp.h"
#include <iostream>

using namespace std;

AbstractionImp::AbstractionImp(/* args */) {}
AbstractionImp::~AbstractionImp() {}
void AbstractionImp::Operation(){
    printf("AbstractionImp....imp... \n");
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA(/* args */) {}
ConcreteAbstractionImpA::~ConcreteAbstractionImpA() {}
void ConcreteAbstractionImpA::Operation(){
    printf("ConcreteAbstractionImpA....imp... \n");
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB(/* args */) {}
ConcreteAbstractionImpB::~ConcreteAbstractionImpB() {}
void ConcreteAbstractionImpB::Operation(){
    printf("ConcreteAbstractionImpB....imp... \n");
}