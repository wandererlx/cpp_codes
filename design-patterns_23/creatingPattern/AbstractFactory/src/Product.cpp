// Product.cpp
#include "../include/Product.h"
#include <iostream>

using namespace std;

AbstractProductA::AbstractProductA() {}
AbstractProductA::~AbstractProductA() {}

AbstractProductB::AbstractProductB() {}
AbstractProductB::~AbstractProductB() {}

ProductA1::ProductA1() { printf("ProductA1... \n"); }
ProductA1::~ProductA1() {}

ProductA2::ProductA2() { printf("ProductA2... \n"); }
ProductA2::~ProductA2() {}

ProductB1::ProductB1() { printf("ProductB1... \n"); }
ProductB1::~ProductB1() {}

ProductB2::ProductB2() { printf("ProductB2... \n"); }
ProductB2::~ProductB2() {}
