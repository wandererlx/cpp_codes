//
// Created by shawnunili on 2020/11/12.
//

#include "efficiency.h"

#include <exception>
#include <set>
#include <functional>
#include <climits>

#include "util.h"

namespace xct {

int MoreThanHalfNum(int* num, int length) {
  if (num == nullptr || length < 1) {
    throw std::exception();
  }
  int middle = length/2;
  int start = 0;
  int end = length - 1;
  int index = Partition(num, length, start, end);
  while (index != middle) {
    if (index < middle) {
      start = index + 1;
    } else {
      end = index - 1;
    }
	index = Partition(num, length, start, end);
  }
  return num[index];
}

int MoreThanHalfNum2(int* num, int length) {
  if (num == nullptr || length < 1) {
	throw std::exception();
  }
  int result;
  int times = 0;
  for (size_t i = 0; i < length; ++i) {
    if (times == 0) {
      result = num[i];
      ++times;
    } else {
	  if (num[i] != result) {
	    --times;
	  } else {
	    ++times;
	  }
    }
  }
  return result;
}

void GetLeastNumbers(int* input, int n, int* output, int k) {
  if (input == nullptr || n < 1 || output == nullptr || k <1) {
	return;
  }
  int start = 0;
  int end = n - 1;
  int index = Partition(input, n, start, end);
  while (index != k - 1) {
	if (index < k - 1) {
	  start = index + 1;
	} else {
	  end = index - 1;
	}
	index = Partition(input, n, start, end);
  }
  for (size_t i = 0; i < k; ++i) {
    output[i] = input[i];
  }
}

void GetLeastNumbers2(int* input, int n, int* output, int k) {
  if (input == nullptr || n < 1 || output == nullptr || k <1) {
	return;
  }
  std::multiset<int, std::greater<int>> max_heap;
  for (size_t i = 0; i < n; ++i) {
    if (max_heap.size() < k) {
      max_heap.insert(input[i]);
    } else {
      auto max_it = max_heap.begin();
      if (input[i] < *max_it) {
        max_heap.erase(max_it);
        max_heap.insert(input[i]);
      }
    }
  }
}

int FindGreatestSumOfSubArray(int* data, int len) {
  if (data == nullptr || len < 0) {
    throw std::exception();
  }
  int cur_sum = 0;
  int greatest_sum = INT_MIN;
  for (size_t i = 0; i < len; ++i) {
    if (cur_sum <= 0) {
      cur_sum = data[i];
    } else {
      cur_sum += data[i];
    }
	if (cur_sum > greatest_sum) {
	  greatest_sum = cur_sum;
	}
  }
  return greatest_sum;
}

int Min(int one, int two, int three) {
  int ret = one < two ? one : two;
  ret = ret < three ? ret : three;
  return ret;
}


int GetUglyNumber(int index) {
  if (index < 1) {
    return 0;
  }
  int* data = new int[index];
  data[0] = 1;
  int* ugly2 = data;
  int* ugly3 = data;
  int* ugly5 = data;
  int i = 1;
  while (i < index) {
    int next_ug2 = (*ugly2) * 2;
	int next_ug3 = (*ugly2) * 3;
	int next_ug5 = (*ugly2) * 5;
    data[i] = Min(next_ug2, next_ug3, next_ug5);
    while ((*ugly2) * 2 <= data[i]) {
      ++ugly2;
    }
	while ((*ugly3) * 3 <= data[i]) {
	  ++ugly3;
	}
	while ((*ugly5) * 5 <= data[i]) {
	  ++ugly5;
	}
	++i;
  }
  int result = data[index - 1];
  delete [] data;
  return result;
}

int InversePairs(int* data, int length) {
  if (data == nullptr || length < 1) {
    return 0;
  }
  int* copy = new int[length];
  for (size_t i = 0; i < length; ++i) {
    copy[i] = data[i];
  }
  int res = InverseCore(data, copy, 0, length - 1);
  delete [] copy;
  return res;
}

int InverseCore(int* data, int* copy, int start, int end) {
  if (start == end) {
    copy[start] = data[start];
    return 0;
  }
  int mid = (start + end) / 2;
  // todo 这种 mid 偏左
  int left = InverseCore(copy, data, start, mid);
  int right = InverseCore(copy, data, mid + 1, end);
  int i = mid;
  int j = end;
  int copy_des = end;
  int count = 0;
  while (i >= start && j >= mid + 1) {
    if (data[i] > data[j]) {
      count += (j - mid);
      copy[copy_des] = data[i];
      --i;
    } else {
	  copy[copy_des] = data[j];
	  --j;
    }
	--copy_des;
  }
  while (i >= start) {
	copy[copy_des] = data[i];
	--i;
	--copy_des;
  }
  while (j >= mid + 1) {
	copy[copy_des] = data[j];
	--j;
	--copy_des;
  }
  return left + right + count;
}

ListNode* FindFirstCommonNode(ListNode* p1, ListNode* p2) {
  if(p1 == nullptr || p2 == nullptr) {
    return nullptr;
  }
  auto len1 = GetListLength(p1);
  auto len2 = GetListLength(p2);
  ListNode* long_list = nullptr;
  ListNode* short_list = nullptr;
  auto diff = 0;
  if (len1 > len2) {
    diff = len1 - len2;
    long_list = p1;
    short_list = p2;
  } else {
	diff = len2 - len1;
	long_list = p2;
	short_list = p1;
  }
  for (unsigned i = 0; i < diff; ++i) {
    long_list = long_list->next;
  }
  while (long_list != nullptr && short_list != nullptr && long_list != short_list) {
    long_list = long_list->next;
    short_list = short_list->next;
  }
  return long_list;
}

unsigned int GetListLength(ListNode* node) {
  unsigned int count = 0;
  while (node != nullptr) {
    ++count;
    node = node->next;
  }
  return count;
}


}
