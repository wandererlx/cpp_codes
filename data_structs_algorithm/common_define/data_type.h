#pragma once

#include <string>

struct ListNode {
  ListNode() : value(0), next(nullptr) {}
  ListNode(int value_, ListNode *next_) : value(value_), next(next_) {}
  ListNode(int value_) : value(value_), next(nullptr) {}
  int value;
  ListNode *next;
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};