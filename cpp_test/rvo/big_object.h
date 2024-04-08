#pragma once

#include <stdio.h>

class BigObject {
 public:
  BigObject() {
    printf("BigObject ctor(), in addr:%ld\n", reinterpret_cast<int64_t>(this));
  }

  BigObject(const BigObject& big_object) {
    printf("BigObject copy ctor(), copy %ld ---> addr:%ld\n",
           reinterpret_cast<int64_t>(&big_object),
           reinterpret_cast<int64_t>(this));
  }

  BigObject(BigObject&& big_object) {
    printf("BigObject move ctor(), move %ld ---> addr:%ld\n",
           reinterpret_cast<int64_t>(&big_object),
           reinterpret_cast<int64_t>(this));
  }

  ~BigObject() {
    printf("BigObject dtor(), addr:%ld\n", reinterpret_cast<int64_t>(this));
  }
};