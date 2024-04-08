//
// Created by shawnunili on 2020/7/27.
#include "base_knowledge.h"
#include <iostream>
#include <stack>
#include <exception>
#include <algorithm>

namespace xct {
// question3
bool SearchIn2DimArray::Find(int *matrix, int rows, int cols, int target) {
  if (matrix == nullptr || rows <= 0 || cols <= 0) {
	return false;
  }
  int i = 0;
  int j = cols - 1;
  while (i < rows && j >= 0) {
	int number = matrix[i * cols + j];
	if (number == target) {
	  return true;
	} else if (number < target) {
	  ++i;
	} else {
	  --j;
	}
  }
  return false;
}

void SearchIn2DimArray::Test() {
  // 多维数组在内存上是连续的
  int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  bool ret = Find((int *)matrix, 4, 4, 7);
  std::cout << "SearchIn2DimArray::Test(): ret:" << ret << std::endl;
}
// question4
void ReplaceBlank::Replace(char *str, int length) {
  if (str == nullptr || length <= 0) {
	return;
  }
  size_t blank_size = 0;
  size_t str_length = 0;

  for (size_t i = 0; str[i] != '\0'; ++i) {
	++str_length;
	if (str[i] == ' ') {
	  ++blank_size;
	}
  }
  if ((str_length + blank_size * 2 + 1) > length) {
	return;
  }

  size_t i = str_length;
  size_t j = str_length + blank_size * 2;
  while (i >= 0 && j > i) {
	if (str[i] != ' ') {
	  str[j--] = str[i--];
	} else {
	  str[j--] = '0';
	  str[j--] = '2';
	  str[j--] = '%';
	  --i;
	}
  }
}

void ReplaceBlank::Test() {

}

// question5
void PrintListFromHead::PrintList(ListNode *head) {
  if (head == nullptr) {
	return;
  }
  std::stack<int> stack;
  while (head != nullptr) {
	stack.push(head->value);
	head = head->next;
  }
  while (!stack.empty()) {
	std::cout << stack.top() << std::endl;
	stack.pop();
  }
}

void PrintListFromHead::PrintListRecursive(ListNode *head) {
  if (head == nullptr) {
	return;
  }
  PrintListRecursive(head->next);
  std::cout << head->value << std::endl;
}

void PrintListFromHead::Test() {

}

BinaryTreeNode *ConstructBinaryTree::Construct(int *preorder, int *inorder, int length) {
  if (preorder == nullptr || inorder == nullptr || length <= 0) {
	return nullptr;
  }
  return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode *ConstructBinaryTree::ConstructCore(int *start_preorder, int *end_preorder,
												   int *start_inorder, int *end_inorder) {
  std::cout << "----start" << start_preorder[0] << "end" << *end_preorder << " ";
  std::cout << "----start" << *start_inorder << "end" << *end_inorder << std::endl;

  int length = 0;
  while (*(start_inorder + length) != start_preorder[0] && start_inorder + length <= end_inorder) {
	++length;
  }
  if (start_inorder + length > end_inorder) {
	throw std::invalid_argument("invalid input");
  }
  BinaryTreeNode *root = new BinaryTreeNode();
  root->value = start_preorder[0];
  std::cout << "root:" << root->value << std::endl;
  if (length >= 1) {
	root->left = ConstructCore(start_preorder + 1, start_preorder + length,
							   start_inorder, start_inorder + length - 1);
  } else {
	root->left = nullptr;
  }
  if (end_inorder - start_inorder - length >= 1) {
	root->right = ConstructCore(start_preorder + length + 1, end_preorder,
								start_inorder + length + 1, end_inorder);
  } else {
	root->right = nullptr;
  }
  return root;
}

void ConstructBinaryTree::Test() {
  const int length = 8;
  int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
  int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
  try {
	Construct(preorder, inorder, length);
  } catch (const std::exception &ex) {
	std::cout << ex.what() << std::endl;
  }
  std::cout << "-------------------------------" << std::endl;
  {
	const int length = 5;
	int preorder[length] = {1, 2, 3, 4, 5};
	int inorder[length] = {5, 4, 3, 2, 1};
	try {
	  Construct(preorder, inorder, length);
	} catch (const std::exception &ex) {
	  std::cout << ex.what() << std::endl;
	}
  }
  return;
}

template<typename T>
void QueueWithTwoStacks<T>::AppendTail(const T &node) {
  stack1_.push(node);
}

template<typename T>
T QueueWithTwoStacks<T>::DeleteHead() {
  if (stack2_.empty()) {
	while (!stack1_.empty()) {
	  stack2_.push(stack1_.top());
	  stack1_.pop();
	}
  }
  if (stack2_.empty()) {
	throw std::out_of_range("queue is empty");
  }
  T node = stack1_.top();
  stack2_.pop();
  return node;
}

template<typename T>
void QueueWithTwoStacks<T>::Test() {

}

template<typename T>
void StackWithTwoQueues<T>::Test() {

}

template<typename T>
void StackWithTwoQueues<T>::Push(const T &node) {
  if (queue2_.empty()) {
    queue1_.push(node);
  } else {
    queue2_.push(node);
  }
}

template<typename T>
T StackWithTwoQueues<T>::Pop() {
  T value;
  if (queue1_.empty() && queue2_.empty()) {
    throw std::exception();
  }
  std::queue<T>* p1;
  std::queue<T>* p2;
  if (queue1_.empty()) {
    p1 = &queue2_;
    p2 = &queue1_;
  } else {
	p2 = &queue2_;
	p1 = &queue1_;
  }
  while (p1->size() > 1) {
    p2->push(p1->front());
    p1->pop();
  }
  value = p1->front();
  p1->pop();
  return value;
}

int MiniNumInRotateedArray::Min(int *num, int length) {
  if (num == nullptr || length <= 0) {
	throw std::invalid_argument("Invalid value");
  }
  int left = 0;
  int right = length - 1;
  int mid = 0;
  while (num[left] >= num[right]) {
	if (right - left == 1) {
	  mid = right;
	  break;
	}
	mid = (left + right) / 2;
	if (num[left] == num[right] && num[mid] == num[left]) {
	  return *std::min_element(num + left, num + right + 1);
	}
	if (num[mid] < num[right]) {
	  right = mid;
	}
	if (num[mid] > num[left]) {
	  left = mid;
	}
  }
  return num[mid];
}

void MiniNumInRotateedArray::Test() {

}

long long Fibonacci::GetResult(unsigned int n) {
  if (n == 0) {
	return 0;
  }
  if (n == 1) {
	return 1;
  }
  return GetResult(n - 1) + GetResult(n - 2);
}

long long Fibonacci::GetResult2(unsigned int n) {
  if (n == 0) {
	return 0;
  }
  if (n == 1) {
	return 1;
  }
  long long one = 0;
  long long two = 1;
  for (unsigned int i = 2; i <= n; ++i) {
	long long three = one + two;
	one = two;
	two = three;
  }
  return two;
}

void Fibonacci::Test() {

}

int NumberOf1(int n) {
  unsigned int flag = 1;
  int count = 0;
  while (flag) {
	if (n & flag) {
	  ++count;
	  flag << 1;
	}
  }
  return count;
}

}
