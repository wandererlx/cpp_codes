//
// Created by shawnunili on 2020/7/27.
//
#pragma once

#include "test_base.h"
#include "common.h"
#include <stack>
#include <queue>

namespace xct {
// question 3
class SearchIn2DimArray : public TestBase {
 public:
  virtual void Test() override;
  // 注意多维数组的表示方式 cpp primer page101
  bool Find(int *matrix, int rows, int cols, int target);
};

// question 4
class ReplaceBlank : public TestBase {
 public:
  virtual void Test() override;
  //  在原数组替换, length 是原数组长度
  void Replace(char string[], int length);
};

// question 5
class PrintListFromHead : public TestBase {
 public:
  virtual void Test() override;

  void PrintList(ListNode *head);

  void PrintListRecursive(ListNode *head);
};

// question 6
class ConstructBinaryTree : public TestBase {
 public:
  virtual void Test() override;

  BinaryTreeNode *Construct(int *preorder, int *inorder, int length);

  BinaryTreeNode *ConstructCore(int *start_preorder, int *end_preorder, int *start_inorder, int *end_inorder);
};

// question 7
template<typename T>
class QueueWithTwoStacks : public TestBase {
 public:
  virtual void Test() override;
  void AppendTail(const T &node);
  T DeleteHead();

 private:
  std::stack<T> stack1_;
  std::stack<T> stack2_;
};
// todo impl
template<typename T>
class StackWithTwoQueues : public TestBase {
 public:
  virtual void Test() override;
  void Push(const T &node);
  T Pop();

 private:
  std::queue<T> queue1_;
  std::queue<T> queue2_;
};

// question 8
class MiniNumInRotateedArray : public TestBase {
 public:
  virtual void Test() override;

  int Min(int* num, int length);
};

// question 9
class Fibonacci : public TestBase {
 public:
  virtual void Test() override;

  long long GetResult(unsigned int n);

  long long GetResult2(unsigned int n);
};

int NumberOf1(int n);

}