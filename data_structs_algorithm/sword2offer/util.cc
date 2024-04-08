//
// Created by shawnunili on 2020/11/3.
//
#include "util.h"

#include <algorithm>
#include <exception>

namespace xct {

int RandomInRange(int start, int end) { return (start + end) / 2; }

int Partition(int data[], int length, int start, int end) {
  if (data == nullptr || length <= 0 || start > end) {
    throw std::invalid_argument("invalid_argument");
  }
  int index = RandomInRange(start, end);
  std::swap(data[index], data[end]);
  int i = start - 1;
  for (int j = start; j < end; ++j) {
    if (data[j] < data[end]) {
      ++i;
      if (i != j) {
        std::swap(data[i], data[j]);
      }
    }
  }
  ++i;
  std::swap(data[i], data[end]);
  return i;
}

void Quicksort(int data[], int length, int start, int end) {
  if (data == nullptr || length == 0 || start == end) {
    return;
  }
  int index = Partition(data, length, start, end);
  if (index > start) {
    Quicksort(data, length, start, index - 1);
  }
  if (index < end) {
    Quicksort(data, length, index + 1, end);
  }
}

}  // namespace xct
