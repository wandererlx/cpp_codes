// FlyweightFactory.h

#ifndef _FLYWEIGHTFACTORY_H_
#define _FLYWEIGHTFACTORY_H_

#include <string>
#include <vector>
#include "Flyweight.h"

using namespace std;

class FlyweightFactory {
 private:
  vector<Flyweight*> _fly;

 public:
  FlyweightFactory(/* args */);
  ~FlyweightFactory();

  Flyweight* GetFlyweight(const string& key);
};

#endif  //~_FLYWEIGHTFACTORY_H_
