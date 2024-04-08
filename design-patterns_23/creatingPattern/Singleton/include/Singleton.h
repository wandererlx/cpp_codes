// Singleton.h

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

using namespace std;

class Singleton {
 private:
  static Singleton* _instance;

 protected:
  Singleton(/* args */);

 public:
  ~Singleton();
  static Singleton* Instance();
};

#endif //~_SINGLETON_H_
