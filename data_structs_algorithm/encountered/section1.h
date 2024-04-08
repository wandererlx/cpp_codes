#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

struct DLinkedNode {
  int key, value;
  DLinkedNode* prev;
  DLinkedNode* next;
  DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
  DLinkedNode(int _key, int _value)
      : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity), size(0) {
    // 使用伪头部和伪尾部节点
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!cache.count(key)) {
      return -1;
    }
    // 如果 key 存在，先通过哈希表定位，再移到头部
    DLinkedNode* node = cache[key];
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    if (!cache.count(key)) {
      // 如果 key 不存在，创建一个新的节点
      DLinkedNode* node = new DLinkedNode(key, value);
      // 添加进哈希表
      cache[key] = node;
      // 添加至双向链表的头部
      addToHead(node);
      ++size;
      if (size > capacity_) {
        // 如果超出容量，删除双向链表的尾部节点
        DLinkedNode* removed = removeTail();
        // 删除哈希表中对应的项
        cache.erase(removed->key);
        // 防止内存泄漏
        delete removed;
        --size;
      }
    } else {
      // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
      DLinkedNode* node = cache[key];
      node->value = value;
      moveToHead(node);
    }
  }

 private:
  void addToHead(DLinkedNode* node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void removeNode(DLinkedNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DLinkedNode* node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkedNode* removeTail() {
    DLinkedNode* node = tail->prev;
    removeNode(node);
    return node;
  }

 private:
  unordered_map<int, DLinkedNode*> cache;
  DLinkedNode* head;
  DLinkedNode* tail;
  int size;
  int capacity_;
};
/*
1:didi
全排列下一数字
反转环形链表
*/

/*
2：weibo
1）模型压缩float 压缩int_16t
2）堆topk  剑指offer
3）虚函数表，sizeof
*/
/*
215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
*/

int quickSort(vector<int>& nums, int start, int end, int k) {
  int mid = rand() % (end - start + 1) + start;
  int mid_value = nums[mid];
  swap(nums[mid], nums[end]);
  int index = start - 1;
  for (int i = start; i < end; ++i) {
    if (nums[i] > mid_value) {
      swap(nums[i], nums[++index]);
    }
  }
  swap(nums[++index], nums[end]);
  if ((index - start + 1) == k) {
    return nums[index];
  } else if ((index - start + 1) > k) {
    return quickSort(nums, start, index - 1, k);
  } else {
    return quickSort(nums, index + 1, end, k - (index - start + 1));
  }
}
int findKthLargest(vector<int>& nums, int k) {
  return quickSort(nums, 0, nums.size() - 1, k);
}

/*
109. 有序链表转换二叉搜索树https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/you-xu-lian-biao-zhuan-huan-er-cha-sou-suo-shu-1-3/
给定一个单链表的头节点  head ，其中的元素 按升序排序
，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过
1。
*/
int getLength(ListNode* head) {
  int ret = 0;
  for (; head != nullptr; ++ret, head = head->next)
    ;
  return ret;
}

TreeNode* buildTree(ListNode*& head, int left, int right) {
  if (left > right) {
    return nullptr;
  }
  int mid = (left + right + 1) / 2;
  TreeNode* root = new TreeNode();
  root->left = buildTree(head, left, mid - 1);
  root->val = head->value;
  head = head->next;
  root->right = buildTree(head, mid + 1, right);
  return root;
}

TreeNode* sortedListToBST(ListNode* head) {
  int length = getLength(head);
  return buildTree(head, 0, length - 1);
}

/*
92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right
。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
*/
ListNode* reverseBetween(ListNode* head, int m, int n) {
  ListNode* dummy = new ListNode(-1);
  dummy->next = head;
  ListNode* pre = dummy;
  for (int i = 1; i < m; ++i) pre = pre->next;
  head = pre->next;
  for (int i = m; i < n; ++i) {
    ListNode* nxt = head->next;
    // head节点连接nxt节点之后链表部分，也就是向后移动一位
    head->next = nxt->next;
    // nxt节点移动到需要反转链表部分的首部
    nxt->next = pre->next;
    pre->next = nxt;  // pre继续为需要反转头节点的前驱节点
  }
  return dummy->next;
}