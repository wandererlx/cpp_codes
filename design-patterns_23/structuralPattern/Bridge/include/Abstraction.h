// Abstraction.h

#ifndef _ABSTRACTION_H_
#define _ABSTRACTION_H_

class AbstractionImp;

class Abstraction {
 private:
  /* data */

 protected:
  Abstraction(/* args */);

 public:
  virtual ~Abstraction();
  virtual void Operation() = 0;
};

class RefinedAbstraction: public Abstraction
{
private:
    AbstractionImp* _imp;

public:
    RefinedAbstraction(AbstractionImp* imp);
    ~RefinedAbstraction();
    void Operation();
};

#endif //~_ABSTRACTION_H_

