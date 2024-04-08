// main.cpp
#include <iostream>
#include "../include/Singleton.h"

using namespace std;

int main(int argc, char* argv[]) {
  Singleton* sgn = Singleton::Instance();
  
  return 0;
}