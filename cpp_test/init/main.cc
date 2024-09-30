#include <iostream>
#include <string>
#include <vector>

class Data {
 public:
  int a;
  float b;
  std::vector<int> c;
};

int main(int argc, char *argv[]) {
  Data* data = new Data();
  std::cout << "a:" << data->a << std::endl;
  std::cout << "b:" << data->b << std::endl;
  return 0;
}