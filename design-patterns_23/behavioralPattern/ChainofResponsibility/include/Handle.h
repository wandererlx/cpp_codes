// Handle.h

#ifndef _HANDLE_H_
#define _HANDLE_H_

class Handle {
 private:
  Handle* _succ;

 protected:
  Handle(/* args */);
  Handle(Handle* succ);

 public:
  virtual ~Handle();
  virtual void HandleRequest() = 0;
  void SetSuccessor(Handle* succ);
  Handle* GetSuccessor();
};

class ConcreteHandleA:public Handle
{
private:
    /* data */
public:
    ConcreteHandleA(/* args */);
    ~ConcreteHandleA();
    ConcreteHandleA(Handle* succ);
    void HandleRequest();
};

class ConcreteHandleB:public Handle
{
private:
    /* data */
public:
    ConcreteHandleB(/* args */);
    ~ConcreteHandleB();
    ConcreteHandleB(Handle* succ);
    void HandleRequest();
};

#endif //~_HANDLE_H_