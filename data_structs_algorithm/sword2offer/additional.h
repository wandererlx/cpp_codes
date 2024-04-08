//
// Created by shawnunili on 2020/11/17.
//
#pragma once

#include <vector>
#include "common.h"

namespace xct {

// question 51
bool Duplicate(int nums[], size_t length, int *duplication);

// question 52
void Multiply(const std::vector<int> &vec1, std::vector<int> &vec2);

// question53
bool Match(char *str, char *pattern);

bool MatchCore(char *string, char *pattern);

// question 54
bool IsNumber(const char *str);

bool ScanUnsignedInteger(const char **str);

bool ScanInteger(const char **str);
// question 55

class CharStatistics {
 public:
  CharStatistics() : index_(0) {
    for (size_t i = 0; i < 256; ++i) {
      occurence_[i]  = -1;
    }
  }
  void Insert(char num);
  char GetFirstNoDuplicatedChar();
 private:
  int index_;
  int occurence_[256];
};

// question 56
ListNode* MeetingNode(ListNode* head);

ListNode* EntryNodeOfLoop(ListNode* head);

// question 57
void DeleteDuplication(ListNode** head);

// question58
BinaryTreeNodeWithParent* GetNext(BinaryTreeNodeWithParent*);

// question 59
bool IsMirrorBinaryTree(const BinaryTreeNode*);
bool IsMirrorBinaryTreeImpl(const BinaryTreeNode*, const BinaryTreeNode*);

// question 60
void PrintTreesInLines(BinaryTreeNode*);

// question 61
void PrintTreesInZigzag(BinaryTreeNode*);

// question 63
BinaryTreeNode* KthNode(BinaryTreeNode* root, unsigned int k);
BinaryTreeNode* KthNodeImpl(BinaryTreeNode* root, unsigned int& k);

//question 64
template<typename T>
class DynamicArray {
 public:
  void Insert(T num);
  T GetMedian();
 private:
  std::vector<T> min_;
  std::vector<T> max_;
};

// question65

std::vector<int> GetMaxInWindow(const std::vector<int> &num, unsigned int size);

}