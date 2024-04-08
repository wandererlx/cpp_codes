// Product.h
#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class AbstractProductA {
 private:
  /* data */
 protected:
  AbstractProductA(/* args */);

 public:
  virtual ~AbstractProductA();
};

class AbstractProductB {
 private:
  /* data */
 protected:
  AbstractProductB(/* args */);

 public:
  virtual ~AbstractProductB();
};

class ProductA1: public AbstractProductA
{
private:
    /* data */
public:
    ProductA1(/* args */);
    ~ProductA1();
};

class ProductA2: public AbstractProductA
{
private:
    /* data */
public:
    ProductA2(/* args */);
    ~ProductA2();
};

class ProductB1: public AbstractProductB
{
private:
    /* data */
public:
    ProductB1(/* args */);
    ~ProductB1();
};

class ProductB2: public AbstractProductB
{
private:
    /* data */
public:
    ProductB2(/* args */);
    ~ProductB2();
};

#endif //~PRODUCT_H_ECT_H_

