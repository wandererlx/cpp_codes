// Handle.cpp

#include "../include/Handle.h"
#include <iostream>

using namespace std;

Handle::Handle(/* args */) { _succ = 0; }
Handle::Handle(Handle* succ) { this->_succ = succ; }
Handle::~Handle() { delete _succ; }
void Handle::SetSuccessor(Handle* succ) { _succ = succ; }
Handle* Handle::GetSuccessor() { return _succ; }
void Handle::HandleRequest() {}

ConcreteHandleA::ConcreteHandleA(/* args */) {}
ConcreteHandleA::ConcreteHandleA(Handle* succ) : Handle(succ) {}
ConcreteHandleA::~ConcreteHandleA() {}
void ConcreteHandleA::HandleRequest() {
  if (this->GetSuccessor() != 0) {
    printf("ConcreteHandleA 我把处理权给后继节点..... \n");
    this->GetSuccessor()->HandleRequest();
  } else {
    printf("ConcreteHandleA 没有后继了,我必须自己处理..... \n");
  }
}

ConcreteHandleB::ConcreteHandleB(/* args */) {}
ConcreteHandleB::ConcreteHandleB(Handle* succ) : Handle(succ) {}
ConcreteHandleB::~ConcreteHandleB() {}
void ConcreteHandleB::HandleRequest() {
  if (this->GetSuccessor() != 0) {
    printf("ConcreteHandleB 我把处理权给后继节点..... \n");
    this->GetSuccessor()->HandleRequest();
  } else {
    printf("ConcreteHandleB 没有后继了,我必须自己处理..... \n");
  }
}

