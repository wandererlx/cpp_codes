#include <cstdio>

#include "crtp.h"

template <typename D>
class Base {
 public:
  static Base<Derive>* Instance() { return (new Derive()); }
  virtual ~Base() {}
  void Test(int num) { static_cast<D*>(this)->Test(num); }

 protected:
  int i_;
};

class Derive : public Base<Derive> {
 public:
  void Test(int num) { printf("On Derive function:Test num %d\n", num); }
};

DBase* DBase::Instance() {
  DBase* base = new DDerive();
  return base;
}

void DDerive::Test(int num) {
  printf("On DDerive function:Test num %d\n", num);
}

int main(int argc, char* argv[]) {
  // Base<Derive>* b = new Derive();
  // auto b = Base<Derive>::Instance();
  DBase* b = DBase::Instance();
  b->Test(7);
  return 0;
}
