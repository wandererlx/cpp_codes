// AbstractFactory.h

#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_

class AbstractProductA;
class AbstractProductB;

class AbstractFactory {
 private:
  /* data */

 protected:
  AbstractFactory(/* args */);

 public:
  virtual ~AbstractFactory();

  virtual AbstractProductA* CreateProductA() = 0;
  virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
 private:
 protected:
 public:
  ConcreteFactory1();
  ~ConcreteFactory1();
  AbstractProductA* CreateProductA();
  AbstractProductB* CreateProductB();
};

class ConcreteFactory2 : public AbstractFactory {
 private:
 protected:
 public:
  ConcreteFactory2();
  ~ConcreteFactory2();
  AbstractProductA* CreateProductA();
  AbstractProductB* CreateProductB();
};

#endif // ~_ABSTRACTFACTORY_H_


