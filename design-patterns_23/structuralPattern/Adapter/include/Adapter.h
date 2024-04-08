//Adapter.h

#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "Target.h"
#include "Adaptee.h"

//类模式，适配器类，通过public继承获得接口继承的效果，通过private继承获得实现继承的效果
class Adapter : public Target, private Adaptee {
 public:
  Adapter();
  ~Adapter();
  virtual void Request();  //实现Target定义的Request接口
};

//对象模式，适配器类，继承Target类，采用组合的方式实现Adaptee的复用
class Adapter1 : public Target {
 public:
  Adapter1(Adaptee* adaptee);
  Adapter1();
  ~Adapter1();
  virtual void Request();  //实现Target定义的Request接口
 private:
  Adaptee* _adaptee;
};

#endif