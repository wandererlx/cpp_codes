//Factory.cpp

#include "../include/Factory.h"
#include "../include/Product.h"
#include <iostream>

using namespace std;

Factory::Factory(){}

Factory::~Factory(){};

ConcreteFactory::ConcreteFactory(){
    cout<<"ConcreteFactory in Factory.cpp"<<endl;
}

ConcreteFactory::~ConcreteFactory(){

}

Product* ConcreteFactory::CreateProduct(){
    return new ConcreteProduct();
}