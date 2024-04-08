//
// Created by shawnunili on 2020/11/14.
//
#pragma once

#include <vector>

#include "common.h"

namespace xct {
// question 38
int GetNumberOfK(int* data, int length, int k);

// question 39
int TreeDepth(BinaryTreeNode* root);

bool IsBanlanced(BinaryTreeNode* root);

bool IsBanlancedCore(BinaryTreeNode* root, int& depth);

// question 40
void FindNumOfOnce(int* data, int length, int* num1, int* num2);

bool IsBitOne(int num, unsigned int index);

unsigned int FirstOfBitOne(int num);

// question 41
bool FindNumbersWithSum(int* data, int length, int sum, int* num1, int* num2);

bool FindContinuoussSequence(int sum, std::vector<std::vector<int>>& res);

// question 42
void Reverse(char* begin, char* end);

void ReverseSentence(char* sentence);

void LeftRotateString(char* str, unsigned int n);

// question 44
bool IsContinuous(int* data, int length);

// question 45
int LastRemaining(unsigned int n, unsigned int m);

// question 49
int StrToInt(const char* str);

// question 50
TreeNode* GetLatestCommonParent(TreeNode* root, TreeNode* p1, TreeNode* p2);

bool GetTreeNodePath(TreeNode* root, TreeNode* p1, std::vector<TreeNode*>& path);


}
