//Adaptee.h

#ifndef ADAPTEE_H
#define ADAPTEE_H

#include <iostream>

using namespace std;

//需要适配的类
class Adaptee {
 public:
  Adaptee();
  ~Adaptee();
  void SpecificRequest();
};

#endif  // ADAPTEE_H