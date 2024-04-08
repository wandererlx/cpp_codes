// Decorator.cpp

#include "../include/Decorator.h"
#include <iostream>

Component::Component(/* args */) {}
Component::~Component() {}
void Component::Operation() {}

ConcreteComponent::ConcreteComponent(/* args */) {}
ConcreteComponent::~ConcreteComponent() {}
void ConcreteComponent::Operation() { printf("ConcreteComponent operation... \n"); }

Decorator::Decorator(Component* com) { this->_com = com; }
Decorator::~Decorator() { delete _com; }
void Decorator::Operation() {}

ConcreteDecorator::ConcreteDecorator(Component* com):Decorator(com) {}
ConcreteDecorator::~ConcreteDecorator() {}
void ConcreteDecorator::AddedBehavior(){
    printf("ConcreteDecorator::AddedBehavior... \n");
}
void ConcreteDecorator::Operation(){
    _com->Operation();
    this->AddedBehavior();
}