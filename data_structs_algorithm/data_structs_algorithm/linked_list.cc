#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
question 19 https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
删除链表的倒数第 N 个结点
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* dummy = new ListNode(0, head);
  ListNode* first = head;
  ListNode* second = dummy;
  for (int i = 0; i < n; ++i) {
    first = first->next;
  }
  while (first) {
    first = first->next;
    second = second->next;
  }
  second->next = second->next->next;
  ListNode* ans = dummy->next;
  delete dummy;
  return ans;
}

/*
25. K 个一组翻转链表
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k
的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
https://leetcode.cn/problems/reverse-nodes-in-k-group/solution/k-ge-yi-zu-fan-zhuan-lian-biao-by-leetcode-solutio/
*/
class Solution25 {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* hair = new ListNode(0);
    hair->next = head;
    ListNode* pre = hair;
    while (head) {
      ListNode* tail = pre;
      // 查看剩余部分长度是否大于等于 k
      for (int i = 0; i < k; ++i) {
        tail = tail->next;
        if (!tail) {
          ListNode* result = hair->next;
          delete hair;
          return result;
          return hair->next;
        }
      }
      ListNode* nex = tail->next;
      // 这里是 C++17 的写法，也可以写成
      // pair<ListNode*, ListNode*> result = myReverse(head, tail);
      // head = result.first;
      // tail = result.second;
      tie(head, tail) = myReverse(head, tail);
      // 把子链表重新接回原链表
      pre->next = head;
      tail->next = nex;
      pre = tail;
      head = tail->next;
    }
    ListNode* result = hair->next;
    delete hair;
    return result;
  }

 private:
  // 翻转一个子链表，并且返回新的头与尾
  pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
    ListNode* tail_next = tail->next;
    ListNode* cur = head;
    while (tail_next != tail) {
      ListNode* nex = cur->next;
      cur->next = tail_next;
      tail_next = cur;
      cur = nex;
    }
    return {tail, head};
  }
};

/*
142. 环形链表 II
https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回
null。 如果链表中有某个节点，可以通过连续跟踪 next
指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos
来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是
-1，则在该链表中没有环。注意：pos
不作为参数进行传递，仅仅是为了标识链表的实际情况。 不允许修改 链表。
*/

ListNode* detectCycle(ListNode* head) {
  ListNode *slow = head, *fast = head;
  while (fast != nullptr) {
    slow = slow->next;
    if (fast->next == nullptr) {
      return nullptr;
    }
    fast = fast->next->next;
    if (fast == slow) {
      ListNode* ptr = head;
      while (ptr != slow) {
        ptr = ptr->next;
        slow = slow->next;
      }
      return ptr;
    }
  }
  return nullptr;
}

/*
148. 排序链表
https://leetcode-cn.com/problems/sort-list/solution/pai-xu-lian-biao-by-leetcode-solution/
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
自底向上归并排序
时间复杂度：O(nlogn)，其中 n 是链表的长度。
空间复杂度：O(1)。
*/
ListNode* Merge2List(ListNode* head1, ListNode* head2) {
  ListNode* dummyHead = new ListNode(0);
  ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
  while (temp1 != nullptr && temp2 != nullptr) {
    if (temp1->value <= temp2->value) {
      temp->next = temp1;
      temp1 = temp1->next;
    } else {
      temp->next = temp2;
      temp2 = temp2->next;
    }
    temp = temp->next;
  }
  if (temp1 != nullptr) {
    temp->next = temp1;
  } else if (temp2 != nullptr) {
    temp->next = temp2;
  }
  return dummyHead->next;
}
ListNode* sortList(ListNode* head) {
  if (head == nullptr) {
    return head;
  }
  int length = 0;
  ListNode* node = head;
  while (node != nullptr) {
    length++;
    node = node->next;
  }
  ListNode* dummyHead = new ListNode(0, head);
  for (int subLength = 1; subLength < length; subLength <<= 1) {
    ListNode *prev = dummyHead, *curr = dummyHead->next;
    while (curr != nullptr) {
      ListNode* head1 = curr;
      for (int i = 1; i < subLength && curr->next != nullptr; i++) {
        curr = curr->next;
      }
      ListNode* head2 = curr->next;
      curr->next = nullptr;
      curr = head2;
      for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr;
           i++) {
        curr = curr->next;
      }
      ListNode* next = nullptr;
      if (curr != nullptr) {
        next = curr->next;
        curr->next = nullptr;
      }
      ListNode* merged = Merge2List(head1, head2);
      prev->next = merged;
      while (prev->next != nullptr) {
        prev = prev->next;
      }
      curr = next;
    }
  }
  return dummyHead->next;
}
/*
23. 合并K个升序链表 给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
*/
ListNode* merge(vector<ListNode*>& lists, int l, int r) {
  if (l == r) return lists[l];
  if (l > r) return nullptr;
  int mid = (l + r) >> 1;
  return Merge2List(merge(lists, l, mid), merge(lists, mid + 1, r));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  return merge(lists, 0, lists.size() - 1);
}

class Solution23 {
 public:
  struct Status {
    int val;
    ListNode* ptr;
    bool operator<(const Status& rhs) const { return val > rhs.val; }
  };

  priority_queue<Status> q;

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    for (auto node : lists) {
      if (node) q.push({node->value, node});
    }
    ListNode head, *tail = &head;
    while (!q.empty()) {
      auto f = q.top();
      q.pop();
      tail->next = f.ptr;
      tail = tail->next;
      if (f.ptr->next) q.push({f.ptr->next->value, f.ptr->next});
    }
    return head.next;
  }
};

/*
https://leetcode.cn/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/
160. 相交链表
给你两个单链表的头节点 headA 和 headB
，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null
。
*/

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  if (headA == nullptr || headB == nullptr) {
    return nullptr;
  }
  ListNode *pA = headA, *pB = headB;
  while (pA != pB) {
    pA = pA == nullptr ? headB : pA->next;
    pB = pB == nullptr ? headA : pB->next;
  }
  return pA;
}

/*
109. 有序链表转换二叉搜索树
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
234. 回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true
；否则，返回 false 。
输入：head = [1,2,2,1]
输出：true
*/
class Solution234 {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) {
      return true;
    }

    // 找到前半部分链表的尾节点并反转后半部分链表
    ListNode* firstHalfEnd = endOfFirstHalf(head);
    ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    // 判断是否回文
    ListNode* p1 = head;
    ListNode* p2 = secondHalfStart;
    bool result = true;
    while (result && p2 != nullptr) {
      if (p1->value != p2->value) {
        result = false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }

    // 还原链表并返回结果
    firstHalfEnd->next = reverseList(secondHalfStart);
    return result;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    return prev;
  }

  ListNode* endOfFirstHalf(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};

/*
1206. 设计跳表
https://leetcode.cn/problems/design-skiplist/
不使用任何库函数，设计一个 跳表 。
跳表 是在 O(log(n))
时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，
并且跳表的代码长度相较下更短，其设计思想与链表相似。
跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过
O(n)。 跳表的每一个操作的平均时间复杂度是 O(log(n))，空间复杂度是 O(n)。
在本题中，你的设计应该要包含这些函数：

bool search(int target) : 返回target是否存在于跳表中。
void add(int num): 插入一个元素到跳表。
bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false.
如果存在多个 num ，删除其中任意一个即可。
注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。
*/
// https://leetcode.cn/circle/article/gRlksy/
// https://leetcode.cn/problems/design-skiplist/solution/can-kao-redisshi-xian-by-bakezq/
static const int SKIPLIST_P_VAL = RAND_MAX / 2, MAX_LEVEL = 16;
class Skiplist {
 public:
  struct Node {
    int val;
    vector<Node*> level;
    Node(int val, int size = MAX_LEVEL) : val(val), level(size) {}
  };

  Node head;
  int maxlevel = 1;
  Skiplist() : head(INT_MIN, MAX_LEVEL) {}
  // ~Skiplist() { delte all nodes. }

  // essentially the same as _search
  bool search(int target) {
    Node* prev = _search(target)[0];
    return prev->level[0] && prev->level[0]->val == target;
  }

  vector<Node*> _search(int key) {
    Node* cur = &head;
    vector<Node*> prevs(MAX_LEVEL);
    // through every level, from top to bottom
    for (int i = maxlevel - 1; i >= 0; i--) {
      // through elements in the current level with smaller value
      while (cur->level[i] && cur->level[i]->val < key) cur = cur->level[i];
      prevs[i] = cur;
    }

    return prevs;
  }

  void add(int num) {
    auto prevs = _search(num);
    int level = random_level();
    // update maxlevel and prevs
    if (level > maxlevel) {
      for (int i = maxlevel; i < level; i++) prevs[i] = &head;
      maxlevel = level;
    }
    Node* cur = new Node(num, level);
    // from prev->next   to   prev->cur->next
    for (int i = level - 1; i >= 0; i--) {
      cur->level[i] = prevs[i]->level[i];
      prevs[i]->level[i] = cur;
    }
    // if there is backward pointer, need to set both cur and cur.next 's back
    // pointer Note that the back poinet of the first valid node is nullptr
    // instead of head
  }

  bool erase(int num) {
    auto prevs = _search(num);
    if (!prevs[0]->level[0] || prevs[0]->level[0]->val != num) return false;
    Node* del = prevs[0]->level[0];
    // from prev->cur->next to prev->next
    for (int i = 0; i < maxlevel; i++)
      if (prevs[i]->level[i] == del) prevs[i]->level[i] = del->level[i];
    delete del;
    // update maxlevel.
    while (maxlevel > 1 && !head.level[maxlevel - 1]) maxlevel--;
    // if there is backward poinet, need to set cur.next.back to cur.back
    return true;
  }

  static int random_level() {
    int level = 1;
    while (rand() < SKIPLIST_P_VAL && level < MAX_LEVEL) level++;
    return level;
  }
};