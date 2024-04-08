// Colleage.cpp

#include "../include/Colleage.h"
#include <iostream>
#include "../include/Mediator.h"

using namespace std;

Colleage::Colleage(/* args */) {}
Colleage::~Colleage() {}
Colleage::Colleage(Mediator* mdt) { this->_mdt = mdt; }

ConcreteColleageA::ConcreteColleageA(/* args */) {}
ConcreteColleageA::~ConcreteColleageA() {}
ConcreteColleageA::ConcreteColleageA(Mediator* mdt) : Colleage(mdt) {}
string ConcreteColleageA::GetState() { return _sdt; }
void ConcreteColleageA::SetState(const string& sdt){_sdt = sdt;}
void ConcreteColleageA::Aciton(){
    _mdt->DoActionFromAtoB();
    cout<<"State of ConcreteColleageB:"<<""<<this->GetState()<<endl;
}

ConcreteColleageB::ConcreteColleageB(/* args */) {}
ConcreteColleageB::~ConcreteColleageB() {}
ConcreteColleageB::ConcreteColleageB(Mediator* mdt) : Colleage(mdt) {}
string ConcreteColleageB::GetState() { return _sdt; }
void ConcreteColleageB::SetState(const string& sdt){_sdt = sdt;}
void ConcreteColleageB::Aciton(){
    _mdt->DoActionFromBtoA();
    cout<<"State of ConcreteColleageB:"<<""<<this->GetState()<<endl;
}
