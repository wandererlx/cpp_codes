// Decorator.h

#ifndef _DECORATOR_H_
#define _DECORATOR_H_

class Component {
 private:
  /* data */

 protected:
  Component(/* args */);

 public:
  virtual ~Component();
  virtual void Operation();
};

class ConcreteComponent : public Component {
 private:
  /* data */
 public:
  ConcreteComponent(/* args */);
  ~ConcreteComponent();
  void Operation();
};

class Decorator : public Component {
 private:
  /* data */

 protected:
  Component* _com;

 public:
  Decorator(Component* com);
  ~Decorator();
  void Operation();
};

class ConcreteDecorator: public Decorator
{
private:
    /* data */
public:
    ConcreteDecorator(Component* com);
    ~ConcreteDecorator();
    void Operation();
    void AddedBehavior();
};

#endif  //~_DECORATOR_H_
