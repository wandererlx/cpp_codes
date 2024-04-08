//
// Created by shawnunili on 2020/11/12.
//
#pragma once

#include "common.h"

namespace xct {

// question29
int MoreThanHalfNum(int* num, int length);

int MoreThanHalfNum2(int* num, int length);

// question 30

void GetLeastNumbers(int* input, int n, int* output, int k);

void GetLeastNumbers2(int* input, int n, int* output, int k);

// question 31 todo 动态规划
int FindGreatestSumOfSubArray(int* data, int len);

// question 34
int GetUglyNumber(int index);

int Min(int one, int two, int three);

// question 36

int InversePairs(int* data, int length);

int InverseCore(int* data, int* copy, int start, int end);

// question 37
ListNode* FindFirstCommonNode(ListNode* p1, ListNode* p2);

unsigned int GetListLength(ListNode* node);

}
