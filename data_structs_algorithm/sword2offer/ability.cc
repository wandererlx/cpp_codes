//
// Created by shawnunili on 2020/11/14.
//

#include "ability.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

namespace xct {

// question 38
int GetNumberOfK(int *data, int length, int k) {
  if (data == nullptr || length < 1) {
	return 0;
  }
  int first_index = -1;
  int last_index = -1;

  int start = 0;
  int end = length - 1;
  int mid = (start + end) / 2;
  while (start < end) {
	if (data[mid] >= k) {
	  end = mid;
	} else {
	  start = mid + 1;
	}
	mid = (start + end) / 2;
  }
  first_index = data[mid] == k ? mid : -1;

  int start2 = 0;
  int end2 = length - 1;
  int mid2 = (start2 + end2 + 1) / 2;
  while (start2 < end2) {
	if (data[mid2] <= k) {
	  start2 = mid2;
	} else {
	  end2 = mid2 - 1;
	}
	mid2 = (start2 + end2 + 1) / 2;
  }
  last_index = data[mid2] == k ? mid2 : -1;
  if (first_index != -1 && last_index != -1) {
	return last_index - first_index + 1;
  }
  return -1;
}

int TreeDepth(BinaryTreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  int left_depth = TreeDepth(root->left);
  int right_depth = TreeDepth(root->right);
  return (left_depth > right_depth) ? (left_depth + 1) : (right_depth = 1);
}

bool IsBanlanced(BinaryTreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  int depth = 0;
  return IsBanlancedCore(root, depth);
}

bool IsBanlancedCore(BinaryTreeNode* root, int& depth) {
  if (root == nullptr) {
    depth = 0;
    return true;
  }
  int left_depth = 0;
  int right_depth = 0;
  if (IsBanlancedCore(root->left, left_depth) && 
      IsBanlancedCore(root->right, right_depth) &&
      std::abs(left_depth - right_depth) < 1) {
    depth = left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    return true;
  } {
    return false;
  }
}

void FindNumOfOnce(int* data, int length, int* num1, int* num2) {
  if (data == nullptr || length < 2 || num1 == nullptr || num2 == nullptr) {
    return;
  }
  int sum = data[0];
  for (size_t i = 1; i < length; ++i) {
    sum ^= data[i];
  }
  unsigned int index = FirstOfBitOne(sum);
  *num1 = *num2 = 0;
  for (size_t i = 0; i < length; ++i) {
    if (IsBitOne(data[i], index)) {
      *num1 ^= data[i];
    } else {
      *num2 ^= data[i];
    }
  }
}

bool IsBitOne(int num, unsigned int index) {
  int ret = num >> index;
  return (ret & 0x1);
}

unsigned int FirstOfBitOne(int num) {
  unsigned int index = 0;
  while ((num & 0x1 == 0) && index < sizeof(int) * 8) {
    num = num >> 1;
    ++index;
  }
  return index;
}

bool FindNumbersWithSum(int* data, int length, int sum, int* num1, int* num2) {
  if (data == nullptr || length < 2 || num1 == nullptr || num2 == nullptr) {
    return false;
  }
  int left = 0;
  int right = length - 1;
  while (left < right) {
    long long cur_sum = data[left] + data[right];
    if (cur_sum == sum) {
      *num1 = data[left];
      *num2 = data[right];
      return true;
    } else if (cur_sum < sum) {
      ++left;
    } else {
      --right;
    }
  }
  return false;
}

bool FindContinuoussSequence(int sum, std::vector<std::vector<int>>& res) {
  if (sum < 3) {
    return false;
  }
  int small = 1;
  int big = 2;
  int cur_sum = small + big;
  while (small < (sum + 1) / 2) {
    std::vector<int> one_Seq;
    if (cur_sum == sum) {
      for (int i = small; i <= big; ++i) {
        one_Seq.push_back(i);
      }
      ++big;
      cur_sum += big;
    } else if (cur_sum > sum) {
      cur_sum -= small;
      ++small;
    } else {
      ++big;
      cur_sum += big;
    }
  }
  return !res.empty();
}

void Reverse(char* begin, char* end) {
  if (begin == nullptr || end == nullptr) {
    return;
  }
  while (begin < end) {
    std::swap(*begin, *end);
    ++begin;
    --end;
  }
}

void ReverseSentence(char* sentence) {
  if (sentence ==nullptr) {
    return;
  }
  size_t len = std::strlen(sentence);
  Reverse(sentence, sentence + len - 1);
  char* i = sentence;
  char* j = sentence;
  while (*j != '\0') {
    while (*j != ' ' && *j != '\0') {
      ++j;
    }
    Reverse(i, j - 1);
    if (*j != '\0') {
      ++j;
      i = j;
    } else {
      break;
    } 
  } 
}

void LeftRotateString(char* str, unsigned int n) {
  size_t len = std::strlen(str);
  if (str == nullptr || len == 0 || len < n) {
    return;
  }
  char* i = str;
  char* j = str + len - 1;
  Reverse(i, j);
  Reverse(i, i + (len - n) - 1);
  Reverse(i + (len - n), j);
}

bool IsContinuous(int* data, int length) {
  if (data == nullptr || length < 1) {
    return false;
  }
  std::sort(data, data + length);
  int zero_size = 0;
  for (size_t i = 0; i < length; ++i) {
    if (data[i] == 0) {
      ++zero_size;
    }
  }
  size_t small = data[zero_size];
  int absent_size = 0;
  for(size_t j = 1 + zero_size; j < length; ++j) {
    if (data[j] == small) {
      return false;
    } else {
      absent_size += (data[j] - small - 1);
      small = data[j];
    }  
  }
  return zero_size >= absent_size;
}

int LastRemaining(unsigned int n, unsigned int m) {
  if (n < 1 || m < 1) {
    return -1;
  }
  std::vector<unsigned int> data;
  for (unsigned int i = 0; i < n; ++i) {
    data.push_back(i);
  }
  auto it = data.begin();
  unsigned int count = 0;
  while (data.size() > 1) {
    while (count < m - 1) {
	  ++it;
	  if (it == data.end()) {
        it = data.begin();
	  }
	  ++count;
    }
    /*
     * for(auto it = mp.begin(); it != mp.end();) {
     *   if (it->first == 2) {
     *     mp.erase(it++);
     *   } else {
     *     ++it;
     *   }
     * }
     * */
    it = data.erase(it);
    if (it == data.end()) {
      it = data.begin();
    }
    count = 0;
  }
  return data[0];
}

int StrToInt(const char* str) {
  std::string err;
  if (str == nullptr || strlen(str) < 1) {
    err = "input null";
    throw std::invalid_argument(err);
  }
  size_t len = strlen(str);
  size_t i = 0;

  bool is_negative = false;
  bool no_data = true;
  long long result = 0;
  for (size_t j = i; j < len; ++j) {
    if (str[j] < '0' || str[j] > '9') {
      if (j == i && (str[j] == '+' || str[j] == '-')) {
        if (str[j] == '-') {
          is_negative = true;
        }
		continue;
      } else {
        throw std::invalid_argument("invalid arg");
      }
    } else {
      no_data = false;
      int minus = is_negative ? -1 : 1;
      result = result * 10 + minus * (str[j] - '0');
      if ((!minus && result > 0x7fffffff) || (minus && result < (signed int) 0x80000000)) {
		throw std::invalid_argument("invalid arg");
      }
    }
  }
  if (no_data) {
	throw std::invalid_argument("invalid arg");
  }
  return static_cast<int>(result);
}

TreeNode* GetLatestCommonParent(TreeNode* root, TreeNode* p1, TreeNode* p2) {
  if (root == nullptr || p1 == nullptr || p2 == nullptr) {
    return nullptr;
  }
  std::vector<TreeNode*> path1;
  bool ret1 = GetTreeNodePath(root, p1, path1);
  std::vector<TreeNode*> path2;
  bool ret2 = GetTreeNodePath(root, p2, path2);
  if (!ret1 || !ret2) {
    return nullptr;
  }
  int j = 0;
  while (path1[j] == path2[j] && j < path1.size() && j < path2.size()) {
    ++j;
  }
  return path1[j-1];
}

bool GetTreeNodePath(TreeNode* root, TreeNode* p, std::vector<TreeNode*>& path) {
  if (root == nullptr) {
    return false;
  }
  path.push_back(root);
  if (root == p) {
	return true;
  }
  for (auto it = root->children.begin(); it != root->children.end(); ++it) {
    bool ret = GetTreeNodePath(*it, p, path);
    if (ret) {
      return true;
    }
  }
  path.pop_back();
  return false;
}
  
}