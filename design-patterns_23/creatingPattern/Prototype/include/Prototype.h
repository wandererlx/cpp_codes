// Prototype.h

#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

class Prototype {
 private:
  /* data */

 protected:
  Prototype(/* args */);

 public:
  virtual Prototype* Clone() const = 0;
  virtual ~Prototype();
};

class ConcretePrototype:public Prototype
{
private:
    /* data */
public:
    ConcretePrototype(/* args */);
    ~ConcretePrototype();

    ConcretePrototype(const ConcretePrototype& cp);
    Prototype* Clone() const;
};

#endif //~_PROTOTYPE_H_
