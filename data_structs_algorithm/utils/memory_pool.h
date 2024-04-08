//
// Created by shawnunili on 2019/7/26.
//

#ifndef CPP_TOOLS_MEMORYPOOL_H
#define CPP_TOOLS_MEMORYPOOL_H

#include <list>
//一个简单的内存池，池中保存3块内存分别为1k,2k,4k
//实现池子的malloc（size）和free(void*)操作
//不考虑跨块申请内存情况

class Node {
 public:
  int offset;//相对于起始地址偏移
  bool flag;//是有效地址还是已经分配地址
  int len;

  Node() {
	offset = 0;
	flag = true;
	len = 0;
  }

  Node(int sz) {
	offset = 0;
	flag = true;
	len = sz;
  }
};

class MemoryPool {
 public:
  MemoryPool() {
	m_First_Count = 1024;
	m_Second_Count = 2 * 1024;
	m_Third_Count = 4 * 1024;
	m_First_Address = new char[m_First_Count];
	m_Second_Address = new char[m_Second_Count];
	m_Third_Address = new char[m_Third_Count];

	first.insert(first.begin(), new Node(1024));
	second.insert(second.begin(), new Node(1024 * 2));
	third.insert(third.begin(), new Node(1024 * 4));
  }

  ~MemoryPool() {
	delete[]m_First_Address;
	delete[]m_Second_Address;
	delete[]m_Third_Address;
	m_First_Address = NULL;
	m_Second_Address = NULL;
	m_Third_Address = NULL;

  }

  char *myMalloc(const int memSize);

  void memFree(void *address_arg);

 private:
  char *m_First_Address;//每一块内存起始地址
  char *m_Second_Address;
  char *m_Third_Address;
  int m_First_Count;//剩余有效地址大小，不一定是连续，是第一块内存中所有有效之和
  int m_Second_Count;
  int m_Third_Count;
  std::list<Node *> first;
  std::list<Node *> second;
  std::list<Node *> third;
};

#endif //CPP_TOOLS_MEMORYPOOL_H
