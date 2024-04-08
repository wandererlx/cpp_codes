// Mediator.h

#ifndef _MEDIATOR_H_
#define _MEDIATOR_H_

class Colleage;

class Mediator {
 private:
  /* data */

 protected:
  Mediator(/* args */);

 public:
  virtual ~Mediator();
  virtual void DoActionFromAtoB() = 0;
  virtual void DoActionFromBtoA() = 0;
};

class ConcreteMediator:public Mediator
{
private:
    Colleage* _clgA;
    Colleage* _clgB;

public:
    ConcreteMediator(/* args */);
    ConcreteMediator(Colleage*clgA,Colleage* clgB);
    ~ConcreteMediator();
    void SetConcreteColleageA(Colleage*clgA);
    void SetConcreteColleageB(Colleage*clgB);
    Colleage* GetConcreteColleageA();
    Colleage* GetConcreteColleageB();
    void IntroColleage(Colleage*clgA,Colleage* clgB);
    void DoActionFromAtoB();
    void DoActionFromBtoA();
};

#endif //~_MEDIATOR_H