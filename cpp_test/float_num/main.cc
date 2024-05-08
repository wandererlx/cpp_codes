#include <math.h>

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


int main(int argc, char* argv[]) {
  double data = 8.11;
  printf("%.2f\n", data);
  printf("%.16f\n", data);
  std::cout << std::setprecision(19) << data << std::endl;
  double data2 = 3.14159;
  printf("data2:%.16f\n", data2);
  printf("3 width data2:%.3f\n", data2);
  double data2_round = round(data2 * 1000);
  printf("data2_round:%.16f\n", data2_round);
  double data2_final = data2_round / 1000;
  printf("16 width data2_final:%.16f\n", data2_final);
  printf("3 width data2_final:%.3f\n", data2_final);
  return 0;
}