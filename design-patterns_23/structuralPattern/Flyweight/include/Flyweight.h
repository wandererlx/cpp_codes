// Flyweight.h

#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_

#include <string>

using namespace std;

class Flyweight {
 private:
  string _intrinsicState;

 protected:
  Flyweight(string intrinsicState);

 public:
  Flyweight(/* args */);
  virtual ~Flyweight();

  virtual void Operation(const string& extrinsicState);
  string GetIntrinsicState();
};

class ConcreteFlyweight : public Flyweight {
 private:
  /* data */

 public:
  ConcreteFlyweight(string intrinsicState);
  ~ConcreteFlyweight();
  virtual void Operation(const string& extrinsicState);
};

#endif  //~_FLYWEIGHT_H_
