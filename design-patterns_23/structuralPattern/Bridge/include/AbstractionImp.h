// AbstractionImp.h

#ifndef _ABSTRACTIONIMP_H_
#define _ABSTRACTIONIMP_H_

class AbstractionImp {
 private:
  /* data */

 protected:
  AbstractionImp(/* args */);

 public:
  virtual ~AbstractionImp();
  virtual void Operation() = 0;
};

class ConcreteAbstractionImpA: public AbstractionImp
{
private:
    /* data */
public:
    ConcreteAbstractionImpA(/* args */);
    ~ConcreteAbstractionImpA();
    virtual void Operation();
};

class ConcreteAbstractionImpB: public AbstractionImp
{
private:
    /* data */
public:
    ConcreteAbstractionImpB(/* args */);
    ~ConcreteAbstractionImpB();
    virtual void Operation();
};

#endif //~_ABSTRACTIONIMP_H_


