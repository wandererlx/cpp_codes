// FlyweightFactory.cpp

#include "../include/FlyweightFactory.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

FlyweightFactory::FlyweightFactory(/* args */) {}
FlyweightFactory::~FlyweightFactory() {}
Flyweight* FlyweightFactory::GetFlyweight(const string& key) {
  vector<Flyweight*>::iterator it = _fly.begin();

  for (; it != _fly.end(); it++) {
    //找到了,就一起用,^_^
    if ((*it)->GetIntrinsicState() == key) {
      printf("already created by users... \n");

      return *it;
    }
  }

  Flyweight* fn = new ConcreteFlyweight(key);
  _fly.push_back(fn);

  return fn;
}