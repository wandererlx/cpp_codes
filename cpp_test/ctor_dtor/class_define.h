#pragma once

#include <stdio.h>

class Test {
 public:
  Test() { printf("Test ctor()\n"); }
  virtual void Foo() {}
  int a;
};

class Test11 : public Test {
 public:
  Test11() { printf("Test11 ctor()\n"); }
  //virtual void Foo() override {}
  int a11;
};

class Test12 : public Test {
 public:
  Test12() { printf("Test12 ctor()\n"); }
  int a12;
};

class Test2 : public Test11, public Test12 {
 public:
  Test2() { printf("Test2 ctor()\n"); }
  int a2;
};

class Test31 : virtual public Test {
 public:
  Test31() { printf("Test31 ctor()\n"); }
  int a11;
};

class Test32 : virtual public Test {
 public:
  Test32() { printf("Test32 ctor()\n"); }
  int a12;
};

class Test4 : public Test31, public Test32 {
 public:
  Test4() { printf("Test4 ctor()\n"); }
  int a2;
};