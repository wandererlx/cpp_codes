//
// Created by shawnunili on 2020-03-31.
//
#include <stdlib.h>
#include <iostream>

#include "max_heap.h"

MaxHeap::MaxHeap(size_t heapSize) : m_heapSize(heapSize), m_queue_(maxHeapCmp) {
  if (m_heapSize == 0) {
	std::cout << "MaxHeap constructor param must great than zero!" << std::endl;
	abort();
  }
}

bool MaxHeap::insert(const MergeSortData &data) {
  if (m_queue_.size() < m_heapSize) {
	m_queue_.push(data);
	return true;
  } else {
	return false;
  }
}

bool MaxHeap::pop(MergeSortData &maxData) {
  if (m_queue_.empty()) {
	return false;
  } else {
	maxData = m_queue_.top();
	m_queue_.pop();
	return true;
  }
}

bool MaxHeap::empty() {
  return m_queue_.empty();
}