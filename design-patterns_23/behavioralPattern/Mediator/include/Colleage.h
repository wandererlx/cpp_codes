// Colleage.h

#ifndef _COLLEAGE_H_
#define _COLLEAGE_H_

#include <string>

using namespace std;

class Mediator;

class Colleage {
 private:
  /* data */

 protected:
  Colleage(/* args */);
  Colleage(Mediator* mdt);
  Mediator* _mdt;

 public:
  virtual ~Colleage();
  virtual void Aciton() = 0;
  virtual void SetState(const string& sdt) = 0;
  virtual string GetState() = 0;
};

class ConcreteColleageA : public Colleage {
 private:
  string _sdt;

 public:
  ConcreteColleageA(/* args */);
  ConcreteColleageA(Mediator* mdt);
  ~ConcreteColleageA();
  void Aciton();
  void SetState(const string& sdt);
  string GetState();
};

class ConcreteColleageB : public Colleage {
 private:
  string _sdt;

 public:
  ConcreteColleageB(/* args */);
  ConcreteColleageB(Mediator* mdt);
  ~ConcreteColleageB();
  void Aciton();
  void SetState(const string& sdt);
  string GetState();
};

#endif //~_COLLEAGE_H_