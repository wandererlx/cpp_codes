// Memento.h

#ifndef _MEMENTO_H_
#define _MEMENTO_H_

#include <string>

using namespace std;

class Memento;

class Originator {
 public:
  typedef string State;
  Originator();
  Originator(const State& sdt);
  ~Originator();
  Memento* CreateMemento();
  void SetMemento(Memento* men);
  void RestoreToMemento(Memento* mt);
  State GetState();
  void SetState(const State& sdt);
  void PrintState();

 private:
  State _sdt;
  Memento* _mt;
};

class Memento {
 private:
  //这是最关键的地方,将 Originator 为friend 类,可以访问内部
  //信息,但是其他类不能访问
  friend class Originator;
  typedef string State;
  Memento(/* args */);
  Memento(const State& sdt);
  ~Memento();
  void SetState(const State& sdt);
  State GetState();
  State _sdt;

 public:
};

#endif  //~_MEMENTO_H_
