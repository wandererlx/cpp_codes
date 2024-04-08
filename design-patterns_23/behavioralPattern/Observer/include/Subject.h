// Subject.h

#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <list>
#include <string>

using namespace std;

typedef string State;

class Observer;

class Subject {
 private:
  list<Observer*>* _obvs;

 protected:
  Subject(/* args */);

 public:
  virtual ~Subject();
  virtual void Attach(Observer* obv);
  virtual void Detach(Observer* obv);
  virtual void Notify();
  virtual void SetState(const State& st) = 0;
  virtual State GetState() = 0;
};

class ConcreteSubject : public Subject {
 private:
  State _st;

 public:
  ConcreteSubject(/* args */);
  ~ConcreteSubject();
  State GetState();
  void SetState(const State& st);
};

#endif //~_SUBJECT_H_