// Element.h

#ifndef _ELEMENT_H_
#define _ELEMENT_H_

class Visitor;

class Element {
 private:
  /* data */

 protected:
  Element(/* args */);

 public:
  virtual ~Element();
  virtual void Accept(Visitor* vis) = 0;
};

class ConcreteElementA:public Element
{
private:
    /* data */
public:
    ConcreteElementA(/* args */);
    ~ConcreteElementA();
    void Accept(Visitor* vis);
};

class ConcreteElementB:public Element
{
private:
    /* data */
public:
    ConcreteElementB(/* args */);
    ~ConcreteElementB();
    void Accept(Visitor* vis);
};

#endif //~_ELEMENT_H_