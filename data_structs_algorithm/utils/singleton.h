//
// Created by shawnunili on 2019/3/25.
//

#ifndef CPP_TOOLS_SINGLETON_H
#define CPP_TOOLS_SINGLETON_H

#include <iostream>
#include <memory>
#include <mutex>

namespace xct {
template <typename T>
class Singleton {
 public:
  static T* getInstance() {
    static T t;
    return &t;
  }

 private:
  Singleton();
  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);
};
}  // namespace xct

// 线程安全的懒汉模式
class Singleton2 {
 public:
  typedef std::shared_ptr<Singleton2> Ptr;
  ~Singleton2() { std::cout << "destructor called!" << std::endl; }
  Singleton2(Singleton2&) = delete;
  Singleton2& operator=(const Singleton2&) = delete;
  static Ptr get_instance() {
    // "double checked lock"
    if (m_instance_ptr == nullptr) {
      std::lock_guard<std::mutex> lk(m_mutex);
      if (m_instance_ptr == nullptr) {
        m_instance_ptr = std::shared_ptr<Singleton2>(new Singleton2);
      }
    }
    return m_instance_ptr;
  }

 private:
  Singleton2() { std::cout << "constructor called!" << std::endl; }
  static Ptr m_instance_ptr;
  static std::mutex m_mutex;
};

// initialization static variables out of class
Singleton2::Ptr Singleton2::m_instance_ptr = nullptr;
std::mutex Singleton2::m_mutex;

#endif  // CPP_TOOLS_SINGLETON_H
