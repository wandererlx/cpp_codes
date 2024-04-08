// Observer.h

#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
#include "Subject.h"

using namespace std;

typedef string State;

class Observer {
 private:
  /* data */

 protected:
  Observer(/* args */);
  State _st;

 public:
  virtual ~Observer();
  virtual void Update(Subject* sub) = 0;
  virtual void PrintInfo() = 0;
};

class ConcreteObserverA :public Observer {
 private:
  Subject* _sub;

 public:
  ConcreteObserverA(Subject* sub);
  virtual ~ConcreteObserverA();
  virtual Subject* GetSubject();
  //传入 Subject 作为参数,这样可以让一个View 属于多个的 Subject。
  void Update(Subject* sub);
  void PrintInfo();
};

class ConcreteObserverB :public Observer {
 private:
  Subject* _sub;

 public:
  ConcreteObserverB(Subject* sub);
  virtual ~ConcreteObserverB();
  virtual Subject* GetSubject();
  //传入 Subject 作为参数,这样可以让一个View 属于多个的 Subject。
  void Update(Subject* sub);
  void PrintInfo();
};

#endif //~_OBSERVER_H_