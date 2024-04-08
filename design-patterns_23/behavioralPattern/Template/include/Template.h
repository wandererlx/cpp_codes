// Template.h
#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

class AbstractClass {
 private:
  /* data */

 protected:
  virtual void PrimitiveOperation1() = 0;
  virtual void PrimitiveOperation2() = 0;
  AbstractClass();

 public:
  void TemplateMethod();
  virtual ~AbstractClass();
};

class ConcreteClass1 : public AbstractClass {
 private:
  /* data */

 protected:
  void PrimitiveOperation1();
  void PrimitiveOperation2();

 public:
  ConcreteClass1(/* args */);
  ~ConcreteClass1();
};

class ConcreteClass2 : public AbstractClass {
 private:
  /* data */

 protected:
  void PrimitiveOperation1();
  void PrimitiveOperation2();

 public:
  ConcreteClass2(/* args */);
  ~ConcreteClass2();
};

#endif  //~ TEMPLATE H
