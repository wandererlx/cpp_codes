#include <cstdlib>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
// #include <codecvt>
// #include <locale>
// #include <filesystem>

using namespace std;

class TestData {
 public:
  TestData(int a, int b) : a_(a), b_(b) {
    std::cout << "create constructer" << std::endl;
  }
  TestData(const TestData& data) : a_(data.a_), b_(data.b_) {
    std::cout << "copy constructer" << std::endl;
  }

  TestData(const TestData&& data) {
    a_ = std::move(data.a_);
    b_ = std::move(data.b_);
    std::cout << "move constructer" << std::endl;
  }

  ~TestData() { std::cout << "destructer" << std::endl; }

 private:
  int a_;
  int b_;
};

enum class ETest : int8_t {
  // error: enumerator value 32767 is too large for underlying type ‘int8_t
 // Invalid = 0x7FFF,
};

int main(int argc, char* argv[]) {
  // ifstream infile;
  // infile.open("./cpxx02020808.txt", ios::in);
  // if (!infile) {
  //   cout << "open file error" << endl;
  //   return 0;
  // }
  // unordered_set<int> index_set{0, 3, 7, 8, 19, 21, 22, 23, 28};
  // string line;
  // int index = 0;
  // while (!infile.eof() && index < 1) {
  //   ++index;
  //   getline(infile, line, '\n');  //读取一行，以换行符结束
  //   if (line.length() == 0) continue;
  //   char *ptmp;
  //   const char *d = "|";
  //   ptmp = strtok((char *)line.c_str(), d);
  //   int i = 0;
  //   while (ptmp) {
  //     if (index_set.count(i)) {
  //       cout << "<[" << i << "]---" << ptmp << "--->" << endl;
  //     }
  //     ptmp = strtok(NULL, d);
  //     i++;
  //   }
  // }
  // std::vector<int> a;
  // a.assign(10, 7);
  // cout << a[0] << "-" << a[9] << endl;
  // cout << a.capacity() << "," << a.size() << endl;
  // a.assign(10, 8);
  // cout << a[0] << "-" << a[9] << endl;
  // cout << a.capacity() << "," << a.size() << endl;
  // a.resize(5);
  // cout << a.capacity() << "," << a.size() << endl;
  // a.reserve(20);
  // cout << a.capacity() << "," << a.size() << endl;
  // std::string path("./file_time.cc");
  // std::filesystem::path fpath = std::filesystem::u8path(path);
  // std::ifstream ifs(fpath);
  // std::cout << "loc:" << ifs.getloc().name() << std::endl;
  std::cout << "sizeof(ETest):" << sizeof(ETest) << std::endl;
  
  return 0;
}