#include <signal.h>
#include <unistd.h>

#include <iostream>

bool g_flag = true;

void SigHandle(int sig_num) {
  std::cout << "sig hadnle start" << std::endl;
  g_flag = false;
}

int main(int argc, char* argv[]) {
  signal(SIGINT, SigHandle);
  while (g_flag) {
    std::cout << "main thread run" << std::endl;
    sleep(1);
  }
  return 0;
}