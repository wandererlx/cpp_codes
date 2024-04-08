#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Widget {};

//函数对象，重载了()运算符
struct DeleteWithLog {
  void operator()(Widget* w) {
    // data++;
    delete w;
    // std::cout << "------ DeleteWithLog delete w" << std::endl;
  }
  char a;
  // int data[10];  //一般不建议在函数对象中定义实例成员
};

void deleteFunction(Widget* w) {
  delete w;
  // std::cout << "------ deleteFunction delete w" << std::endl;
}

void TestUniquePtr() {
  //默认的删除器
  {
    // unique_ptr 内部使用std::tuple<T, deleter> 来存放数据，默认删除器，
    // 使用空基类优化技术，优化掉
    std::unique_ptr<Widget> w1(new Widget());
    std::cout << "size with default delete:" << sizeof(w1) << std::endl;
  }

  //通过函数对象定义删除器
  {
    std::unique_ptr<Widget, DeleteWithLog> w2(new Widget());
    std::cout << "size with function object:" << sizeof(w2) << std::endl;
  }

  // lambda表达式定义删除器
  int data1 = 1, data2 = 2, data3 = 3;
  {
    auto lambda = [=](Widget* w) {
      std::cout << "in lambda:" << data1 << "|" << data2 << "|" << data3
                << std::endl;
      // 捕获这三个参数后，考虑字节对齐后，会多增加16个字节
      delete w;
      // std::cout << "------ lambda delete w" << std::endl;
    };
    std::cout << "size lambda:" << sizeof(lambda) << std::endl;
    std::unique_ptr<Widget, decltype(lambda)> w3(new Widget(), lambda);
    // unique_ptr<Widget, decltype(lambda)> w3(new Widget(100, 200, 300)); //C++
    // 20中构造函数可以省略掉第二个参数，lambda提供了默认构造函数
    std::cout << "size with lambda:" << sizeof(w3) << std::endl;
  }

  //函数指针定义删除器
  {
    std::unique_ptr<Widget, void (*)(Widget*)> w4(new Widget(), deleteFunction);
    std::cout << "size with function pointer:" << sizeof(w4) << std::endl;
  }

  {
    std::function<void(Widget*)> delete_fun = deleteFunction;
    std::cout << "size std::function:" << sizeof(delete_fun) << std::endl;
  }
}

void TestSharedPtr() {
  std::shared_ptr<Widget> a;
  std::shared_ptr<Widget> b(nullptr, deleteFunction);
  int data1 = 1, data2 = 2, data3 = 3;
  auto lambda = [=](Widget* w) {
    std::cout << "in lambda:" << data1 << "|" << data2 << "|" << data3
              << std::endl;
    // 捕获这三个参数后，考虑字节对齐后，会多增加16个字节
    delete w;
    // std::cout << "------ lambda delete w" << std::endl;
  };
  std::shared_ptr<Widget> c(nullptr, lambda);
  std::cout << "sizof a:" << sizeof(a) << std::endl;
  std::cout << "sizof b:" << sizeof(b) << std::endl;
  std::cout << "sizof c:" << sizeof(c) << std::endl;
}

class Test : public std::enable_shared_from_this<Test> {
 public:
  ~Test() { std::cout << "Test Dtor" << std::endl; }

  std::shared_ptr<Test> Get() { return shared_from_this(); }

 private:
  std::string a_;
};
void TestEnsharedFromThis() {
  std::shared_ptr<Test> test(new Test());
  auto t2 = test->Get();
}

int main(int argc, char* argv[]) {
  // TestUniquePtr();
  // TestSharedPtr();
  TestEnsharedFromThis();
  return 0;
}
