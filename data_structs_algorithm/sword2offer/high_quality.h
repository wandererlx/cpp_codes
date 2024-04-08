//
// Created by shawnunili on 2020/11/8.
//
#pragma once

#include "test_base.h"
#include "common.h"

namespace xct {

// question 11
double Power(double base, int exponent);

double PowerWithUnsignedExponent(double base, unsigned int exponent);

// question 12
class Print1ToMaxOfNDigits : public TestBase {
 public:
  virtual void Test() override;

  void Print(int n);

  bool Increment(char* num);

  void PrintNum(char* num);
};

// question 13 o(1)
void DeleteNode(ListNode** head, ListNode* to_be_deleted);

void RemoveNode(ListNode** head, int value);

// question 15

ListNode* FindKthToTail(ListNode* head, unsigned k);
// question 16
ListNode* ReverseList(ListNode* head);

// question 17
ListNode* Merger(ListNode* p1, ListNode* p2);

// question 18

class SubstructInTree {
 public:
  bool HasSubTree(BinaryTreeNode* p1, BinaryTreeNode* p2);
 private:
  bool DoesTree1HaveTree2(BinaryTreeNode* p1, BinaryTreeNode* p2);
};

}