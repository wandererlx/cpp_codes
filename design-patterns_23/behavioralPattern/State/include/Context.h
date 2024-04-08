// Context.h

#ifndef _CONTEXT_H_
#define _CONTEXT_H_

class State;

class Context {
 private:
  //表明在 State 类中可以访问 Context 类的 private 字段
  friend class State;
  bool ChangeState(State* state);
  State* _state;

 public:
  Context(/* args */);
  Context(State* state);
  ~Context();

  void OprationInterface();
  void OperationChangState();
};

#endif //~_CONTEXT_H_
