//
// Created by shawnunili on 2020/11/9.
//

#include "question_thinking.h"
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

namespace xct {

template<typename T>
void StackWithMin<T>::Push(const T &value) {
  stack1_.push(value);
  if (stack2_.empty()) {
	stack2_.push(value);
  } else {
	stack2_.push(stack2_.top() < value ? stack2_.top() : value);
  }
}

template<typename T>
void StackWithMin<T>::Pop() {
  assert(!stack1_.empty() && !stack2_.empty());
  stack1_.pop();
  stack2_.pop();

}

template<typename T>
const T &StackWithMin<T>::Min() const {
  assert(!stack1_.empty() && !stack2_.empty());
  return stack2_.top();

}

bool IsPopOrder(const int *push, const int *pop, int length) {
  bool result = false;
  if (push != nullptr && pop != nullptr && length > 0) {
	std::stack<int> stack_data;
	int push_index = 0;
	int i = 0;
	for (; i < length; ++i) {
	  while (stack_data.empty() || stack_data.top() != pop[i]) {
		if (push_index < length) {
		  stack_data.push(push[push_index]);
		  ++push_index;
		} else {
		  break;
		}
	  }
	  if (stack_data.top() != pop[i]) {
		break;
	  } else {
		stack_data.pop();
	  }
	}
	if (stack_data.empty() && i == length) {
	  result = true;
	}
  }
  return result;
}

void PrintTreeFromTop2Bottom(BinaryTreeNode *root) {
  if (root == nullptr) {
	return;
  }
  std::deque<BinaryTreeNode *> queue;
  queue.push_back(root);
  while (!queue.empty()) {
	auto node = queue.front();
	queue.pop_front();
	std::cout << node->value;
	if (node->left) {
	  queue.push_back(node->left);
	}
	if (node->right) {
	  queue.push_back(node->right);
	}
  }
}

bool VerifySquenceOfBST(int sequence[], int length) {
  if (sequence == nullptr || length <= 0) {
	return false;
  }
  int root = sequence[length - 1];
  int i = 0;
  for (; i < length - 1; ++i) {
	if (sequence[i] > root) {
	  break;
	}
  }
  for (int j = i + 1; j < length - 1; ++j) {
	if (sequence[j] < root) {
	  return false;
	}
  }
  bool left = true;
  if (i > 0) {
	left = VerifySquenceOfBST(sequence, i);
  }
  bool right = true;
  if (i + 1 < length) {
	right = VerifySquenceOfBST(sequence + i, length - i - 1);
  }
  return left && right;
}

void FindPathInTree(BinaryTreeNode *root, int except_sum) {
  if (root == nullptr) {
	return;
  }
  std::vector<int> path;
  int current_sum = 0;
  FindPathImpl(root, except_sum, path, current_sum);
}

void FindPathImpl(BinaryTreeNode *root, int except_sum, std::vector<int> &path, int &current_sum) {
  path.emplace_back(root->value);
  current_sum += root->value;
  bool is_leaf = (root->right == nullptr && root->left == nullptr);
  if (is_leaf) {
	if (current_sum == except_sum) {
	  for (const auto path_node : path) {
		std::cout << path_node << " ";
	  }
	}
  } else {
	if (root->left) {
	  FindPathImpl(root->left, except_sum, path, current_sum);
	}
	if (root->right) {
	  FindPathImpl(root->right, except_sum, path, current_sum);
	}
  }
  path.pop_back();
  current_sum -= root->value;
}

ComplexListNode *CopyComplexList::Clone(ComplexListNode *head) {
  CloneNodes(head);
  ConnectSiblingNodes(head);
  return ReconnectNodes(head);
}

void CopyComplexList::CloneNodes(ComplexListNode *head) {
  if (head == nullptr) {
	return;
  }
  auto *cur = head;
  while (cur != nullptr) {
	auto *clone_node = new ComplexListNode();
	clone_node->value = cur->value;
	clone_node->next = cur->next;
	clone_node->sibling = nullptr;
	cur->next = clone_node;
	cur = clone_node->next;
  }
}

void CopyComplexList::ConnectSiblingNodes(ComplexListNode *head) {
  if (head == nullptr) {
	return;
  }
  auto *cur = head;
  while (cur != nullptr) {
	auto *clone_node = cur->next;
	if (cur->sibling) {
	  clone_node->sibling = cur->sibling->next;
	}
	cur = clone_node->next;
  }
}

ComplexListNode *CopyComplexList::ReconnectNodes(ComplexListNode *head) {
  if (head == nullptr) {
	return nullptr;
  }
  auto *clone_head = head->next;
  auto *cur = head;
  while (cur != nullptr) {
    auto* clone_node = cur->next;
    cur->next = clone_node->next;
    clone_node->next = clone_node->next? clone_node->next->next : nullptr;
    cur = cur->next;
  }
  return clone_head;
}

BinaryTreeNode* ConvertBinaryTreeToList(BinaryTreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  }
  BinaryTreeNode* last_node;
  ConvertNode(root, &last_node);
  while (last_node && last_node->left) {
    last_node = last_node->left;
  }
  return last_node;
}

void ConvertNode(BinaryTreeNode* node, BinaryTreeNode** last_node_in_list) {
  if (node == nullptr) {
	return;
  }
  if (node->left) {
    ConvertNode(node->left, last_node_in_list);
  }
  node->left = *last_node_in_list;
  if (*last_node_in_list != nullptr) {
	(*last_node_in_list)->right = node;
  }
  *last_node_in_list = node;
  if (node->right) {
    ConvertNode(node->right, last_node_in_list);
  }
}

template<typename T>
void Permutation<T>::PermutationData(T *data, size_t len) {
  if (data == nullptr) {
	return;
  }
  PermutationImpl(data, len, 0);
}

template<typename T>
void Permutation<T>::PermutationImpl(T *data, size_t len, size_t begin) {
  if (begin == len) {
    HandleData(data, len);
  }
  for (size_t i = begin; i < len; ++i) {
    std::swap(data[begin], data[i]);
    PermutationImpl(data, len, begin + 1);
	std::swap(data[begin], data[i]);
  }
}

template<typename T>
void Permutation<T>::HandleData(T *data, size_t len) {
// 字符全排列打印即可
// 8个数字正方体，复合条件的打印即可
// 8皇后问题, 一维数组 长度为8, 8个皇后肯定位于8行，下标代表所在行，值代表所在列，初始化为{0, 1, ....7}
// 全排列，任意的 i,j 符合的条件为 (i - j != data[i] - data[j] && j - i != data[i] - data[j])
  bool flag = true;
  for(size_t i = 0; i < len; ++i) {
    for (size_t j = i+1; j < len; ++j) {
      if (i - j == data[i] - data[j] || j - i == data[i] - data[j]) {
        flag = false;
		break;
      }
    }
    if (!flag) {
	  break;
    }
  }
  if (flag) {
    std::cout << "all pos";
  }
}

void Combination(char* str) {
  if (str == nullptr) {
	return;
  }
  size_t len = std::strlen(str);
  std::vector<char> res;
  for (size_t n = 1; n <= len; ++n) {
    Combination(str, n, res);
  }
}

void Combination(char* str, int num, std::vector<char>& res) {
  if (num == 0) {
    std::cout << "res:";
	return;
  }
  if (*str == '\0') {
    // 加入每次都不选，会越界
	return;
  }
  res.push_back(*str);
  Combination(str+1, num - 1, res);
  res.pop_back();
  Combination(str+1, num, res);
}

}
