//
// Created by shawnunili on 2020/11/8.
//
#include "high_quality.h"
#include <cmath>
#include <exception>
#include <cstring>
#include <cstdio>

namespace xct {

double Power(double base, int exponent) {
  if (!std::isless(base, 0.0) && !std::isgreater(base, 0.0) && exponent < 0) {
	throw std::exception();
  }
  double result;
  int ex = exponent;
  if (exponent < 0) {
	ex = -exponent;
  }
  result = PowerWithUnsignedExponent(base, -exponent);
  if (exponent < 0) {
    result = 1 / result;
  }
  return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
//  double result = 1.0;
//  while (exponent > 0) {
//	result *= base;
//	--exponent;
//  }
//  return result;
  if (exponent == 0) {
    return 1;
  }
  if (exponent == 1) {
    return base;
  }
  double result;
  result = PowerWithUnsignedExponent(base, exponent >> 1);
  result *= result;
  if (exponent & 0x1 == 1) {
    result *= base;
  }
  return result;
}

void Print1ToMaxOfNDigits::Print(int n) {
  if (n < 1) {
	return;
  }
  char* num = new char[n+1];
  std::memset(num, '0', n);
  num[n] = '\0';
  while (Increment(num)) {
    PrintNum(num);
  }
  delete [] num;
}

bool Print1ToMaxOfNDigits::Increment(char* num) {
  auto len = std::strlen(num);
  int value = num[len-1] - '0';
  bool is_flow = false;
  int carry = 0;
  if (value < 9) {
    num[len-1] = value + 1 + '0';
    return true;
  } else {
    carry = 1;
	num[len-1] = '0';
	int i = len - 2;
	for (; i >= 0; --i) {
	  int value = num[i] - '0';
	  if (value + carry <= 9) {
		num[len-2] = value + carry + '0';
	    return true;
	  } else {
		num[len-2] = '0';
		carry = 1;
	  }
	}
	if (i == 0 && carry == 1) {
	  return false;
	}
  }
}

void Print1ToMaxOfNDigits::PrintNum(char* num) {
  bool is_first_0 = true;
  for (int i = 0; i < std::strlen(num); ++i) {
    if (is_first_0 && num[i] != '0') {
      is_first_0 = false;
    }
    if (!is_first_0) {
      std::printf("%c", num[i]);
    }
  }
  std::printf("\n");
}

void Print1ToMaxOfNDigits::Test() {
  Print(2);
}

void DeleteNode(ListNode** head, ListNode* to_be_deleted) {
  if (head == nullptr || to_be_deleted == nullptr) {
	return;
  }
  if (to_be_deleted->next != nullptr) {
    auto next = to_be_deleted->next;
    to_be_deleted->value = to_be_deleted->next->value;
	to_be_deleted->next = to_be_deleted->next->next;
	delete next;
  } else if (*head == to_be_deleted) {
    delete to_be_deleted;
    to_be_deleted = nullptr;
    *head = nullptr;
  } else {
    auto i = *head;
    while (i->next != to_be_deleted) {
      i = i->next;
    }
    i->next = nullptr;
    delete to_be_deleted;
  }
}

void RemoveNode(ListNode** head, int value) {
  if (head == nullptr || *head == nullptr) {
	return;
  }
  auto i = *head;
  // head is target
  if (i->value == value) {
	*head = i->next;
    delete i;
	return;
  }
  // head is not target
  while (i->next != nullptr && i->next->value != value) {
    i = i->next;
  }
  if (i->next == nullptr) {
	return;
  }
  auto next = i->next;
  i->next = next->next;
  delete next;
}

ListNode* FindKthToTail(ListNode* head, unsigned k) {
  if (head == nullptr || k == 0) {
    return nullptr;
  }
  ListNode* i = head;
  ListNode* j = head;
  size_t step = 0;
  while  (step < k - 1 && j->next != nullptr) {
    ++step;
    j = j->next;
  }
  if (step != k - 1) {
    return nullptr;
  }
  while (j->next != nullptr) {
    i = i->next;
    j = j->next;
  }
  return i;
}

ListNode* ReverseList(ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }
  ListNode* pre = nullptr;
  ListNode* cur = head;
  ListNode* result = nullptr;
  while (cur != nullptr) {
	ListNode* next = cur->next;
	if (next == nullptr) {
	  result = cur;
	}
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  return result;
}

ListNode* Merger(ListNode* p1, ListNode* p2) {
  if (p1 == nullptr) {
    return p2;
  }
  if (p2 == nullptr) {
    return p1;
  }
  ListNode* result_head = nullptr;
  if (p1->value < p2->value) {
    result_head = p1;
    p1 = p1->next;
  } else {
    result_head = p2;
    p2 = p2->next;
  }
  ListNode* cur = result_head;
  while (p1 != nullptr && p2 != nullptr) {
    if (p1->value < p2->value) {
	  cur->next = p1;
	  p1 = p1->next;
    } else {
	  cur->next = p2;
	  p2 = p2->next;
	}
    cur = cur->next;
  }
  if (p1 != nullptr) {
    cur->next = p1;
  }
  if (p2 != nullptr) {
    cur->next = p2;
  }
  return result_head;
}

bool SubstructInTree::HasSubTree(BinaryTreeNode *p1, BinaryTreeNode *p2) {
  bool result = false;
  if (p1 != nullptr && p2 != nullptr) {
    if (p1->value == p2->value) {
      result = DoesTree1HaveTree2(p1, p2);
    }
    if (!result) {
	  result = HasSubTree(p1->left, p2);
    }
	if (!result) {
	  result = HasSubTree(p1->right, p2);
	}
  }
  return result;
}

bool SubstructInTree::DoesTree1HaveTree2(BinaryTreeNode *p1, BinaryTreeNode *p2) {
  if (p2 == nullptr) {
    return true;
  }
  if (p1 == nullptr) {
    return false;
  }
  if (p1->value != p2->value) {
    return false;
  }
  return DoesTree1HaveTree2(p1->left, p2->left) && DoesTree1HaveTree2(p1->right, p2->right);
}

}
