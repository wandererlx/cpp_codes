// Strategy.cpp

#include "../include/Strategy.h"
#include <iostream>

using namespace std;

Strategy::Strategy(/* args */) {}
Strategy::~Strategy() { printf("~Strategy.... \n"); }
void Strategy::AlgrithmInterface() {}

ConcreteStrategyA::ConcreteStrategyA(/* args */) {}
ConcreteStrategyA::~ConcreteStrategyA() { printf("~ConcreteStrategyA..... \n"); }
void ConcreteStrategyA::AlgrithmInterface() {
  printf("test ConcreteStrategyA......AlgrithmInterface \n");
}

ConcreteStrategyB::ConcreteStrategyB(/* args */) {}
ConcreteStrategyB::~ConcreteStrategyB() { printf("~ConcreteStrategyB..... \n"); }
void ConcreteStrategyB::AlgrithmInterface() {
  printf("test ConcreteStrategyB......AlgrithmInterface \n");
}