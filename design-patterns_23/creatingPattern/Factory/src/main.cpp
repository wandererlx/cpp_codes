// main.cpp
#include <iostream>
#include "../include/Factory.h"
#include "../include/Product.h"
using namespace std;

int main(int argc, char* argv[]) {
  Factory* fac = new ConcreteFactory();
  Product* p = fac->CreateProduct();

  return 0;
}