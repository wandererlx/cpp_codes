#include <iostream>
#include <string>
#include <vector>

class O {
  //  private:
  //   int x;
};

class X {
 public:
  virtual ~X() = default;
  virtual void PrintX() {}

  //  private:
  //   int x;
};

class Y {
 public:
  virtual ~Y() = default;
  virtual void PrintY() {}

  //  private:
  //   int y;
};

class Z : public X {
 public:
  virtual ~Z() = default;
  // virtual void PrintZ() {}

  //  private:
  //   int z;
};
// 多层次继承中，vptr的数目为N-1，N为基类的数目
class ZZ : public X, public Y {
 public:
  virtual ~ZZ() = default;
  // virtual void PrintZZ() {}

  //  private:
  //   int z;
};

class ZZZ : public X, public Y, public O {
 public:
  virtual ~ZZZ() = default;
  // virtual void PrintZZ() {}

  //  private:
  //   int z;
};

bool IsLittleEndin() {
  int a = 0x1234;
  return *(reinterpret_cast<char*>(&a)) == 0x34;
}

int main(int argc, char* argv[]) {
  std::cout << "sizeof(int*):" << sizeof(int*) << std::endl;
  std::cout << "sizeof(X):" << sizeof(X) << std::endl;
  std::cout << "sizeof(Z):" << sizeof(Z) << std::endl;
  std::cout << "sizeof(ZZ):" << sizeof(ZZ) << std::endl;
  std::cout << "sizeof(ZZZ):" << sizeof(ZZZ) << std::endl;
  std::cout << "IsLittleEndin():" << IsLittleEndin() << std::endl;
  return 0;
}