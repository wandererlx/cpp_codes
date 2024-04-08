// Context.cpp

#include "../include/Context.h"
#include "../include/State.h"

Context::Context(/* args */) {}
Context::Context(State* state) { this->_state = state; }
Context::~Context() { delete _state; }
void Context::OprationInterface() { _state->OperationChangeState(this); }
bool Context::ChangeState(State* state) {
  this->_state = state;
  return true;
}
void Context::OperationChangState() { _state->OperationChangeState(this); }
