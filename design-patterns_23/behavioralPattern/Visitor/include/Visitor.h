// Visitor.h

#ifndef _VISITOR_H_
#define _VISITOR_H_

class ConcreteElementA;
class ConcreteElementB;
class Element;

class Visitor {
 private:
  /* data */

 protected:
  Visitor(/* args */);

 public:
  virtual ~Visitor();
  virtual void VisitConcreteElementA(Element* elm) = 0;
  virtual void VisitConcreteElementB(Element* elm) = 0;
};

class ConcreteVisitorA : public Visitor {
 private:
  /* data */

 public:
  ConcreteVisitorA(/* args */);
  virtual ~ConcreteVisitorA();
  virtual void VisitConcreteElementA(Element* elm);
  virtual void VisitConcreteElementB(Element* elm);
};

class ConcreteVisitorB : public Visitor {
 private:
  /* data */
 public:
  ConcreteVisitorB(/* args */);
  ~ConcreteVisitorB();
  virtual void VisitConcreteElementA(Element* elm);
  virtual void VisitConcreteElementB(Element* elm);
};

#endif //~_VISITOR_H_