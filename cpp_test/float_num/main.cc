#include <math.h>

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


int main(int argc, char* argv[]) {
  double data = 8.11;
  printf("%f\n", data);
  printf("%.2f\n", data);
  printf("%.16f\n", data);
  // 默认输出精度是6，不显示后边的0
  std::cout << "std::cout:" << data << std::endl;
  std::cout << "std::cout with precision 19:" << std::setprecision(19) << data << std::endl;
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