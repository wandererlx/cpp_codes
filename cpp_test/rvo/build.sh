#!/bin/bash
# -fno-elide-constructors可以完全关闭RVO和NRVO  -o0呢？
g++ -o rvo_test -std=c++11 -O0 -Wall rvo_test.cc