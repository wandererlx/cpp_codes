// Director.cpp
#include <iostream>
#include "../include/Director.h"

using namespace std;

void Direcror::Create(IBuilder *builder) {
  builder->BuildCpu();
  builder->BuildMainboard();
  builder->BuildRam();
  builder->BuildVideoCard();
}