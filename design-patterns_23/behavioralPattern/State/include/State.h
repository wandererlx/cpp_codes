// State.h

#ifndef _STATE_H_
#define _STATE_H_

class Context;  //前置声明

class State {
 private:
  /* data */

 protected:
  bool ChangeState(Context* con, State* st);

 public:
  State(/* args */);
  virtual ~State();
  virtual void OperationInterface(Context*) = 0;
  virtual void OperationChangeState(Context*) = 0;
};

class ConcreteStateA:public State
{
private:
    /* data */
public:
    ConcreteStateA(/* args */);
    virtual ~ConcreteStateA();
    virtual void OperationInterface(Context*);
    virtual void OperationChangeState(Context*);
};

class ConcreteStateB:public State
{
private:
    /* data */
public:
    ConcreteStateB(/* args */);
    ~ConcreteStateB();
    virtual void OperationInterface(Context*);
    virtual void OperationChangeState(Context*);
};

#endif //~_STATE_H_