//
// Created by shawnunili on 2020/7/27.
//
#pragma once

#include <vector>

namespace xct {

struct ListNode {
  int value;
  ListNode *next;
};

struct BinaryTreeNode {
  int value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
};

struct BinaryTreeNodeWithParent {
  int value;
  BinaryTreeNodeWithParent *left;
  BinaryTreeNodeWithParent *right;
  BinaryTreeNodeWithParent *parent;
};

struct ComplexListNode {
  int value;
  ComplexListNode* next;
  ComplexListNode* sibling;
};

struct TreeNode {
  int value;
  std::vector<TreeNode*> children;
};

}