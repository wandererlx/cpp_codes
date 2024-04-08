//
// Created by shawnunili on 2020/11/17.
//

#include "additional.h"
#include <vector>
#include <algorithm>
#include <exception>
#include <deque>
#include <climits>
#include <iostream>
#include <stack>

namespace xct {
bool Match(char *str, char *pattern) {
  if (str == nullptr || pattern == nullptr) {
	return false;
  }
  return MatchCore(str, pattern);
}

bool MatchCore(char* str, char* pattern) {
  if(*str == '\0' && *pattern == '\0')
	return true;

  if(*str != '\0' && *pattern == '\0')
	return false;

  if(*(pattern + 1) == '*') {
	if(*pattern == *str || (*pattern == '.' && *str != '\0'))
	  // move on the next state
	  return MatchCore(str + 1, pattern + 2)
		  // stay on the current state
		  || MatchCore(str + 1, pattern)
			  // ignore a '*'
		  || MatchCore(str, pattern + 2);
	else
	  // ignore a '*'
	  return MatchCore(str, pattern + 2);
  }

  if(*str == *pattern || (*pattern == '.' && *str != '\0'))
	return MatchCore(str + 1, pattern + 1);

  return false;
}

void Multiply(const std::vector<int>& vec1, std::vector<int>& vec2) {
  if (vec1.size() == vec2.size() && vec2.size() > 1) {
    vec2[0] = 1;
    for (size_t i = 1; i < vec1.size(); ++i) {
      vec2[i] = vec2[i-1] * vec1[i-1];
    }
    int temp = 1;
    for (size_t i = vec1.size() - 2; i >=0; --i) {
      temp *= temp * vec1[i+1];
      vec2[i] *= temp;
    }
  }
}

bool Duplicate(int nums[], size_t length, int *duplication) {
  if (nums == nullptr || length < 2) {
	return false;
  }
  for (size_t i = 0; i < length; ++i) {
	if (nums[i] < 0 || nums[i] >= length) {
	  return false;
	}
  }
  for (size_t i = 0; i < length; ++i) {
	while (nums[i] != i) {
	  if (nums[i] == nums[nums[i]]) {
		*duplication = nums[i];
		return true;
	  } else {
		std::swap(nums[i], nums[nums[i]]);
	  }
	}
  }
  return false;
}

template<typename T>
void DynamicArray<T>::Insert(T num) {
  if (((max_.size() + min_.size()) & 0x1) == 0) {
	if (max_.size() > 0 && max_[0] > num) {
	  max_.push_back(num);
	  // todo 堆排序
	  std::make_heap(max_.begin(), max_.end(), std::less<T>());
	  num = max_[0];
	  std::pop_heap(max_.begin(), max_.end(), std::less<T>());
	  max_.pop_back();
	}
	min_.push_back(num);
	std::make_heap(min_.begin(), min_.end(), std::greater<T>());
  } else {
	if (min_.size() > 0 && min_[0] < num) {
	  min_.push_back(num);
	  std::make_heap(min_.begin(), min_.end(), std::greater<T>());
	  num = min_[0];
	  std::pop_heap(min_.begin(), min_.end(), std::greater<T>());
	  min_.pop_back();
	}
	max_.push_back(num);
	std::make_heap(max_.begin(), max_.end(), std::less<T>());
  }
}
template<typename T>
T DynamicArray<T>::GetMedian() {
  if (max_.size() + min_.size() == 0) {
	throw std::runtime_error("no data");
  }
  if (((max_.size() + min_.size()) & 0x1) == 0) {
	return (min_[0] + max_[0]) / 2;
  } else {
	return min_[0];
  }
}

std::vector<int> GetMaxInWindow(const std::vector<int> &num, unsigned int size) {
  std::vector<int> result;
  if (num.empty() || num.size() < size) {
	return result;
  }
  std::deque<int> index;
  unsigned int i = 0;
  for (; i < size; ++i) {
	if (index.empty()) {
	  index.push_back(i);
	} else if (num[i] > num[index.back()]) {
	  index.pop_back();
	  index.push_back(i);
	}
  }
  for (unsigned int j = i; j < num.size(); ++j) {
	result.push_back(num[index.front()]);
	while (!index.empty() && num[j] > num[index.back()]) {
	  index.pop_back();
	}
	index.push_back(j);
	if (!index.empty() && j - index.front() + 1 > size) {
	  index.pop_front();
	}
  }
  result.push_back(num[index.front()]);
  return result;
}

bool ScanUnsignedInteger(const char** str) {
  const char* start = *str;
  while (**str >= '0' && **str <= '9') {
    ++(*str);
  }
  return *str > start;
}

bool ScanInteger(const char** str) {
  if (**str == '+' || **str == '-') {
    ++(*str);
  }
  return ScanUnsignedInteger(str);
}

bool IsNumber(const char* str) {
  if (str == nullptr) {
    return false;
  }
  bool is_number = ScanInteger(&str);
  if (*str == '.') {
    ++str;
    is_number = ScanUnsignedInteger(&str) || is_number; // 1.  .9
  }
  if (!is_number) {
    return false;
  }
  if (*str == 'e' || *str == 'E') {
	++str;
    is_number = ScanInteger(&str);
  }
  return is_number && *str == '\0';
}

void CharStatistics::Insert(char num) {
  if (occurence_[num] == -1) {
	occurence_[num] = index_;
  } else if (occurence_[num] >= 0) {
	occurence_[num] = -2;
  }
  ++index_;
}

char CharStatistics::GetFirstNoDuplicatedChar() {
  char ret = '\0';
  int min_index = INT_MAX;
  for (size_t i = 0; i < 256; ++i) {
	if (occurence_[i] >= 0 && occurence_[i] < min_index) {
	  min_index = occurence_[i];
	  ret = (char)i;
	}
  }
  return ret;
}

ListNode* MeetingNode(ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }
  ListNode* slow = head->next;
  if (slow == nullptr) {
    return nullptr;
  }
  ListNode* fast = head->next;
  while (fast != nullptr && slow != nullptr) {
    if (fast == slow) {
      return fast;
    }
    slow = slow->next;
    fast = fast->next;
    if (fast != nullptr) {
	  fast = fast->next;
    }
  }
  return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* head) {
  ListNode* meeting_node = MeetingNode(head);
  if (meeting_node == nullptr) {
    return nullptr;
  }
  ListNode* step = meeting_node->next;
  int circle_length = 1;
  while (step != meeting_node) {
    step = step->next;
    ++circle_length;
  }
  ListNode* fast = head;
  while(circle_length > 0) {
    fast = fast->next;
    --circle_length;
  }
  while (head != fast) {
    head = head->next;
    fast = fast->next;
  }
  return fast;
}

void DeleteDuplication(ListNode** head) {
  if (head == nullptr || *head == nullptr) {
	return;
  }
  ListNode* pre = nullptr;
  ListNode* cur = *head;
  while (cur != nullptr) {
    ListNode* next = cur->next;
    bool need_delete = false;
    if (next != nullptr && next->value == cur->value) {
      need_delete = true;
    }
    if (!need_delete) {
      pre = cur;
      cur = next;
    } else {
      int value = next->value;
      ListNode* tobe_deleted = cur;
      while (tobe_deleted != nullptr && tobe_deleted->value == value) {
        next = tobe_deleted->next;
        delete tobe_deleted;
        tobe_deleted = next;
      }
      // todo important
      if (pre == nullptr) {
        *head = next;
      } else {
		// todo important
        pre->next = next;
      }
	  cur = next;
    }
  }
}

BinaryTreeNodeWithParent* GetNext(BinaryTreeNodeWithParent* head) {
  if (head == nullptr) {
    return nullptr;
  }
  if (head->right != nullptr) {
    auto* right_first = head->right;
    while (right_first->left != nullptr) {
      right_first = right_first->left;
    }
    return right_first;
  }
  auto* cur = head;
  while (cur->parent != nullptr && cur == cur->parent->right) {
    cur = cur->parent;
  }
  return cur->parent;
}

bool IsMirrorBinaryTree(const BinaryTreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  return IsMirrorBinaryTreeImpl(root->left, root->right);
}
bool IsMirrorBinaryTreeImpl(const BinaryTreeNode* p1, const BinaryTreeNode* p2) {
  if (p1 == nullptr && p2 == nullptr) {
    return true;
  }
  if (p1 == nullptr || p2 == nullptr) {
    return false;
  }
  if (p1->value != p2->value) {
    return false;
  }
  return IsMirrorBinaryTreeImpl(p1->left, p2->right) && IsMirrorBinaryTreeImpl(p1->right, p2->left);
}

void PrintTreesInLines(BinaryTreeNode* head) {
  if (head == nullptr) {
	return;
  }
  std::deque<BinaryTreeNode*> que;
  que.push_back(head);
  int tobe_printed = 1;
  int tobe_pushed = 0;
  while (!que.empty()) {
    while (tobe_printed > 0) {
      auto* node = que.front();
      que.pop_front();
      if (node->left != nullptr) {
        ++tobe_pushed;
        que.push_back(node->left);
      }
	  if (node->right != nullptr) {
		++tobe_pushed;
		que.push_back(node->right);
	  }
	  std::cout << node->value << " ";
	  --tobe_printed;
    }
	std::cout << std::endl;
    tobe_printed = tobe_pushed;
    tobe_pushed = 0;
  }
}

void PrintTreesInZigzag(BinaryTreeNode* head) {
  if (head == nullptr) {
	return;
  }
  std::stack<BinaryTreeNode*> stacks[2];
  stacks[0].push(head);
  bool flag = false;
  while (!stacks[0].empty() && !stacks[1].empty()) {
    while (stacks[flag].empty()) {
	  auto* node = stacks[flag].top();
	  stacks[flag].pop();
	  std::cout << node->value << " ";
	  if (!flag) {
	    if (node->left != nullptr) {
	      stacks[!flag].push(node->left);
	    }
		if (node->right != nullptr) {
		  stacks[!flag].push(node->right);
		}
	  } else {
		if (node->right != nullptr) {
		  stacks[!flag].push(node->right);
		}
		if (node->left != nullptr) {
		  stacks[!flag].push(node->left);
		}
	  }
    }
    std::cout << std::endl;
    flag = !flag;
  }
}

BinaryTreeNode* KthNode(BinaryTreeNode* root, unsigned int k) {
  if (root == nullptr || k < 1) {
    return nullptr;
  }
  return KthNodeImpl(root, k);
}

BinaryTreeNode* KthNodeImpl(BinaryTreeNode* root, unsigned int& k) {
  BinaryTreeNode* target = nullptr;
  if (root->left != nullptr) {
    target = KthNodeImpl(root->left, k);
  }
  if (target == nullptr) {
    if (k == 1) {
      target = root;
    }
    --k;
  }
  if (target == nullptr && root->right != nullptr) {
    target = KthNodeImpl(root->right, k);
  }
  return target;
}

}