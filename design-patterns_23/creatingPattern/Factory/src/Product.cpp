// Product.cpp

#include "../include/Product.h"
#include <iostream>

using namespace std;

Product::Product() {}

Product::~Product() {}

ConcreteProduct::ConcreteProduct() { cout << "ConcreteProduct in Product.cpp" << endl; }

ConcreteProduct::~ConcreteProduct() {}