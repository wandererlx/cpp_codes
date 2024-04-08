// State.cpp

#include "../include/State.h"
#include <iostream>
#include "../include/Context.h"

using namespace std;

State::State(/* args */) {}
State::~State() {}
void State::OperationInterface(Context* con) { printf("State::.. \n"); }
bool State::ChangeState(Context* con, State* st) {
  con->ChangeState(st);

  return true;
}
void State::OperationChangeState(Context* con) {}

ConcreteStateA::ConcreteStateA(/* args */) {}
ConcreteStateA::~ConcreteStateA() {}
void ConcreteStateA::OperationInterface(Context* con) {
  printf("ConcreteStateA::OperationInterface... \n");
}
void ConcreteStateA::OperationChangeState(Context* con) {
  OperationInterface(con);
  this->ChangeState(con, new ConcreteStateB());
}

ConcreteStateB::ConcreteStateB(/* args */) {}
ConcreteStateB::~ConcreteStateB() {}
void ConcreteStateB::OperationInterface(Context* con) {
  printf("ConcreteStateB::OperationInterface... \n");
}
void ConcreteStateB::OperationChangeState(Context* con) {
  OperationInterface(con);
  this->ChangeState(con, new ConcreteStateA());
}