//
// Created by shawnunili on 2020/11/9.
//
# pragma once

#include "common.h"

#include <stack>

namespace xct {

// question 21
template<typename T>
class StackWithMin {
 public:
  void Push(const T &value);
  void Pop();
  const T &Min() const;
 private:
  std::stack<T> stack1_;
  std::stack<T> stack2_;
};

// question 22
bool IsPopOrder(const int *push, const int *pop, int length);

// question 23
void PrintTreeFromTop2Bottom(BinaryTreeNode *root);

// question 24
bool VerifySquenceOfBST(int sequence[], int length);

// question 25
void FindPathInTree(BinaryTreeNode *root, int except_sum);

void FindPathImpl(BinaryTreeNode *root, int except_sum, std::vector<int> &path, int &current_sum);

// question 26
class CopyComplexList {
 public:
  ComplexListNode* Clone(ComplexListNode* head);
 private:
  void CloneNodes(ComplexListNode* head);

  void ConnectSiblingNodes(ComplexListNode* head);

  ComplexListNode* ReconnectNodes(ComplexListNode* head);
};

// question27
BinaryTreeNode* ConvertBinaryTreeToList(BinaryTreeNode* root);

void ConvertNode(BinaryTreeNode* node, BinaryTreeNode** last_node_in_list);

// question28
template<typename T>
class Permutation {
 public:
  void PermutationData(T data[], size_t len);

  virtual void HandleData(T data[], size_t len);

 private:
  void PermutationImpl(T data[], size_t len, size_t begin);
};

void Combination(char* str);

void Combination(char* str, int num, std::vector<char>& res);

}