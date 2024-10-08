// Factory.h

#ifndef _FACTORY_H_
#define _FACTORY_H_

class Product;

class Factory {
 public:
  virtual ~Factory() = 0;
  virtual Product* CreateProduct() = 0;

 protected:
  Factory();

 private:
};

class ConcreteFactory : public Factory {
 public:
  ConcreteFactory(/* args */);
  ~ConcreteFactory();
  Product* CreateProduct();

 protected:
 private:
  /* data */
};
#endif //~_FACTORY_H_
