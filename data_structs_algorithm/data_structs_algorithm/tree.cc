#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (!root) {
      return ret; 
    }
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
       TreeNode* node = s.top();
       s.pop();
       ret.push_back(node->val);
       if (node->right) {
         s.push(node->right); // 先右后左，保证左子树先遍历 
       }
       if (node->left) {
           s.push(node->left);
       } 
    }
    return ret; 
}

// 后续遍历
void postorderTraversal(TreeNode* root) {
   if (root == nullptr) {
       return;
   }

   stack<TreeNode*> s;
   TreeNode* prev = nullptr;

   while (root != nullptr || !s.empty()) {
       if (root != nullptr) {
           s.push(root);
           root = root->left;
       } else {
        TreeNode* top = s.top();
       // 分清返回根节点时 是从左子树返回还是右子树返回，
       // 以下判断主要防止从右节点返回后重复，入栈
         if (top->right != nullptr && top->right != prev) {
           root = top->right;
         } else {
           cout << top->val << " ";
           s.pop();
           prev = top;
          }
       } 
   }
}

/*
94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
申请一个栈，头结点为开始节点(当前节点)
如果当前节点不为空，那么将左节点压栈，即做tree=tree->lson操作，如果当前节点为空的时候打印栈顶元素，并且出栈，将
当前节点变为栈顶元素的右节点也就是做tree =
cur->rson(中序遍历中，栈主要保存的是父节点元素)
不断重复步骤2直到栈空，结束程序！
原文链接：https://blog.csdn.net/woshinannan741/article/details/52825163
*/
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  if (root == nullptr) {
    return res;
  }
  stack<TreeNode*> stack;
  while (!stack.empty() || root) {
    if (root) {
      stack.push(root);
      root = root->left;
    } else {
      TreeNode* node = stack.top();
      stack.pop();
      res.push_back(node->val);
      root = node->right;
    }
  }
  return res;
}
/*
先说两个栈来实现的方法，第一个栈保存的是根节点元素，第二栈是保存输出的元素！过程如下：
申请一个栈，将根节点入栈
如果栈不为空，弹出第一个栈的栈顶元素记做cur，将第一个栈顶元素出栈，然后将cur压入第二个栈。如果cur有左孩子将左孩子加入第一个栈，如果有右孩子将右孩子加入第一个栈
不断的重复步骤2，直到第一个栈为空，打印第二个栈，结束程序！
原文链接：https://blog.csdn.net/woshinannan741/article/details/52825163
*/
vector<int> PosTraversal(TreeNode* root) {
  vector<int> res;
  if (root == nullptr) {
    return res;
  }
  stack<TreeNode*> stack1;
  stack<TreeNode*> stack2;
  stack1.push(root);
  while (!stack1.empty()) {
    root = stack1.top();
    stack1.pop();
    stack2.push(root);
    if (root->left) {
      stack1.push(root->left);
    }
    if (root->right) {
      stack1.push(root->right);
    }
  }
  while (!stack2.empty()) {
    root = stack2.top();
    stack2.pop();
    res.emplace_back(root->val);
  }

  return res;
}
/*我们用cur表示栈顶元素,h表示的是最近栈的元素，初始化时h为头结点。算法流程如下：
申请一个栈 ，将头结点压栈，初始化h变量，
如果栈不为空，cur赋为栈顶元素！
---- 1.如果cur的左孩子不为NULL并且h不等于cur的左孩子也不等于cur的右孩子那么就将左孩子入栈。（如果最近h等于当前节点的左孩子，就说明左子树已经打印完了，否则就代表还没有打印过，就应该将左孩子或者右孩子入栈）
---- 2.在1条件不成立的条件下，并且cur的右孩子不等于h并且不为空，就说明右子树还没有处理过，这个时候就应该将cur的右孩子入栈！
---- 3.如果前俩个条件都不成立，就说明cur的左子树和右子树已经打印完毕了，或者当前节点为叶子节点，此时就应该将栈顶元素出栈了，并且令h=cur
一直重复步骤2直到栈为空，结束程序
原文链接：https://blog.csdn.net/woshinannan741/article/details/52825163/
*/
vector<int> PosTraversal1Stack(TreeNode* root) {
  vector<int> result;
  if (root == nullptr) {
    return result;
  }
  stack<TreeNode*> stack_data;
  stack_data.push(root);
  TreeNode* last_pop;
  while (!stack_data.empty()) {
    TreeNode* node = stack_data.top();
    if (node->left != nullptr && node->left != last_pop &&
        node->right != last_pop) {
      stack_data.push(node->left);
    } else if (node->right != nullptr && node->right != last_pop) {
      stack_data.push(node->right);
    } else {
      last_pop = stack_data.top();
      stack_data.pop();
      result.push_back(last_pop->val);
    }
  }
  return result;
}

/*
98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
输入：root = [2,1,3]
输出：true
*/
bool isValidBSTImpl(TreeNode* root, TreeNode** last) {
  if (root == nullptr) {
    return true;
  }
  bool left = isValidBSTImpl(root->left, last);
  if (!left) {
    return false;
  }
  if (last != nullptr && (*last) != nullptr && (*last)->val >= root->val) {
    return false;
  }
  *last = root;
  bool right = isValidBSTImpl(root->right, last);
  return right;
}

bool isValidBST(TreeNode* root) {
  TreeNode* last = nullptr;
  return isValidBSTImpl(root, &last);
}

/*
102. 二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
（即逐层地，从左到右访问所有节点）。 示例 1： 输入：root =
[3,9,20,null,null,15,7] 输出：[[3],[9,20],[15,7]]
*/

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> res;
  if (root == nullptr) {
    return res;
  }
  deque<TreeNode*> que;
  que.push_back(root);
  while (!que.empty()) {
    size_t cur_size = que.size();
    res.push_back(vector<int>());
    for (size_t i = 0; i < cur_size; ++i) {
      TreeNode* node = que.front();
      res.back().push_back(node->val);
      que.pop_front();
      if (node->left != nullptr) {
        que.push_back(node->left);
      }
      if (node->right != nullptr) {
        que.push_back(node->right);
      }
    }
  }
  return res;
}
/*
104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
*/
int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

/*
105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/

class BuildTreeSolution {
 private:
  unordered_map<int, int> index;

 public:
  TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder,
                        int preorder_left, int preorder_right, int inorder_left,
                        int inorder_right) {
    if (preorder_left > preorder_right) {
      return nullptr;
    }

    // 前序遍历中的第一个节点就是根节点
    int preorder_root = preorder_left;
    // 在中序遍历中定位根节点
    int inorder_root = index[preorder[preorder_root]];

    // 先把根节点建立出来
    TreeNode* root = new TreeNode(preorder[preorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的
    // size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到
    // 根节点定位-1」的元素
    root->left = myBuildTree(preorder, inorder, preorder_left + 1,
                             preorder_left + size_left_subtree, inorder_left,
                             inorder_root - 1);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到
    // 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right =
        myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1,
                    preorder_right, inorder_root + 1, inorder_right);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    // 构造哈希映射，帮助我们快速定位根节点
    for (int i = 0; i < n; ++i) {
      index[inorder[i]] = i;
    }
    return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};

/*
110. 平衡二叉树
：https://leetcode.cn/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode-solution/
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/
class Solution110 {
 public:
  int height(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight == -1 || rightHeight == -1 ||
        abs(leftHeight - rightHeight) > 1) {
      return -1;
    } else {
      return max(leftHeight, rightHeight) + 1;
    }
  }

  bool isBalanced(TreeNode* root) { return height(root) >= 0; }
};

/*
114. 二叉树展开为链表
给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right
子指针指向链表中下一个结点，而左子指针始终为 null 。 展开后的单链表应该与二叉树
先序遍历 顺序相同。
*/

void flatten(TreeNode* root) {
  auto* cur = root;
  while (cur != nullptr) {
    if (cur->left != nullptr) {
      auto* next = cur->left;
      auto* pre = cur->left;
      while (pre->right != nullptr) {
        pre = pre->right;
      }
      pre->right = cur->right;
      cur->left = nullptr;
      cur->right = next;
    }
    cur = cur->right;
  }
}

/*
124. 二叉树中的最大路径和
路径
被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中
至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。
*/
int maxSum = INT_MIN;
int maxGain(TreeNode* node) {
  if (node == nullptr) {
    return 0;
  }
  // 递归计算左右子节点的最大贡献值
  // 只有在最大贡献值大于 0 时，才会选取对应子节点
  int leftGain = max(maxGain(node->left), 0);
  int rightGain = max(maxGain(node->right), 0);

  // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
  int priceNewpath = node->val + leftGain + rightGain;

  // 更新答案
  maxSum = max(maxSum, priceNewpath);

  // 返回节点的最大贡献值
  return node->val + max(leftGain, rightGain);
}

int maxPathSum(TreeNode* root) {
  maxGain(root);
  return maxSum;
}

/*
208. 实现 Trie (前缀树)
Trie（发音类似 "try"）或者说 前缀树
是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
请你实现 Trie 类：
Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word
在前缀树中，返回true（即，在检索之前已经插入）；否则，返回 false 。 boolean
startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix
，返回 true；否则，返回 false 。
*/
class Trie {
 public:
  Trie() : children(26), isEnd(false) {}

  void insert(string word) {
    Trie* node = this;
    for (char ch : word) {
      ch -= 'a';
      if (node->children[ch] == nullptr) {
        node->children[ch] = new Trie();
      }
      node = node->children[ch];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie* node = this->searchPrefix(word);
    return node != nullptr && node->isEnd;
  }

  bool startsWith(string prefix) {
    return this->searchPrefix(prefix) != nullptr;
  }

 private:
  Trie* searchPrefix(string prefix) {
    Trie* node = this;
    for (char ch : prefix) {
      ch -= 'a';
      if (node->children[ch] == nullptr) {
        return nullptr;
      }
      node = node->children[ch];
    }
    return node;
  }

 private:
  vector<Trie*> children;
  bool isEnd;
};

/*
297. 二叉树的序列化与反序列化
https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/solution/er-cha-shu-de-xu-lie-hua-yu-fan-xu-lie-hua-by-le-2/
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
反序列化算法执行逻辑，你只需要保证一
个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
*/

class Codec {
 public:
  string serialize(TreeNode* root) {
    if (!root) {
      return "X";
    }
    auto left = "(" + serialize(root->left) + ")";
    auto right = "(" + serialize(root->right) + ")";
    return left + to_string(root->val) + right;
  }

  TreeNode* deserialize(string data) {
    int ptr = 0;
    return parse(data, ptr);
  }

 private:
  TreeNode* parse(const string& data, int& ptr) {
    if (data[ptr] == 'X') {
      ++ptr;
      return nullptr;
    }
    auto cur = new TreeNode(0);
    cur->left = parseSubtree(data, ptr);
    cur->val = parseInt(data, ptr);
    cur->right = parseSubtree(data, ptr);
    return cur;
  }

  inline TreeNode* parseSubtree(const string& data, int& ptr) {
    ++ptr;  // 跳过左括号
    auto subtree = parse(data, ptr);
    ++ptr;  // 跳过右括号
    return subtree;
  }

  inline int parseInt(const string& data, int& ptr) {
    int x = 0, sgn = 1;
    if (!isdigit(data[ptr])) {
      sgn = -1;
      ++ptr;
    }
    while (isdigit(data[ptr])) {
      x = x * 10 + data[ptr++] - '0';
    }
    return x * sgn;
  }
};

/*
437. 路径总和 III
https://leetcode.cn/problems/path-sum-iii/solution/lu-jing-zong-he-iii-by-leetcode-solution-z9td/
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于
targetSum 的 路径 的数目。 路径
不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

假设当前从根节点root到节点node的前缀和为curr，则此时我们在已保存的前缀和查找是否存在前缀和刚好等于curr−targetSum。
假设从根节点 root 到节点 node 的路径中存在节点pi到根节点root
的前缀和为curr−targetSum，则节点pi+1到node 的路径 上所有节点的和一定为targetSum
*/

class Solution437 {
 public:
  int pathSum(TreeNode* root, int targetSum) {
    prefix[0] = 1;
    return dfs(root, 0, targetSum);
  }

 private:
  int dfs(TreeNode* root, long long curr, int targetSum) {
    if (!root) {
      return 0;
    }
    int ret = 0;
    curr += root->val;
    if (prefix.count(curr - targetSum)) {
      ret = prefix[curr - targetSum];
    }
    prefix[curr]++;
    ret += dfs(root->left, curr, targetSum);
    ret += dfs(root->right, curr, targetSum);
    prefix[curr]--;
    return ret;
  }

 private:
  unordered_map<long long, int> prefix;
};

/*
538. 把二叉搜索树转换为累加树
https://leetcode.cn/problems/convert-bst-to-greater-tree/solution/ba-er-cha-sou-suo-shu-zhuan-huan-wei-lei-jia-sh-14/
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater
Sum Tree）， 使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
提醒一下，二叉搜索树满足下列约束条件：
节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
*/

class Solution538 {
 public:
  int sum = 0;

  TreeNode* convertBST(TreeNode* root) {
    if (root != nullptr) {
      convertBST(root->right);
      sum += root->val;
      root->val = sum;
      convertBST(root->left);
    }
    return root;
  }
};