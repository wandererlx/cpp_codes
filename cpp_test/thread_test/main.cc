#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <type_traits>

int main(int argc, char* argv[]) {
  std::thread t([]() {
    int i = 0;
    while (i++ < 30) {
      std::cout << "detach thread i:" << i << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }

  });
  t.join();
  // std::this_thread::sleep_for(std::chrono::seconds(10));
  std::cout << "main thread exit!" << std::endl;
  return 0;
}