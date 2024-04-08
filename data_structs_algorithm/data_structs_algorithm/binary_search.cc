#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
4. 寻找两个正序数组的中位数
https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
*/
int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
  /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和
   * pivot2 = nums2[k/2-1] 进行比较 这里的 "/" 表示整除 nums1 中小于等于 pivot1
   * 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个 nums2 中小于等于 pivot2 的元素有
   * nums2[0 .. k/2-2] 共计 k/2-1 个 取 pivot = min(pivot1,
   * pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <=
   * k-2 个 这样 pivot 本身最大也只能是第 k-1 小的元素 如果 pivot = pivot1，那么
   * nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部
   * "删除"，剩下的作为新的 nums1 数组 如果 pivot = pivot2，那么 nums2[0 ..
   * k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2
   * 数组 由于我们 "删除" 了一些元素（这些元素都比第 k
   * 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
   */

  int m = nums1.size();
  int n = nums2.size();
  int index1 = 0, index2 = 0;

  while (true) {
    // 边界情况
    if (index1 == m) {
      return nums2[index2 + k - 1];
    }
    if (index2 == n) {
      return nums1[index1 + k - 1];
    }
    if (k == 1) {
      return min(nums1[index1], nums2[index2]);
    }

    // 正常情况
    int newIndex1 = min(index1 + k / 2 - 1, m - 1);
    int newIndex2 = min(index2 + k / 2 - 1, n - 1);
    int pivot1 = nums1[newIndex1];
    int pivot2 = nums2[newIndex2];
    if (pivot1 <= pivot2) {
      k -= newIndex1 - index1 + 1;
      index1 = newIndex1 + 1;
    } else {
      k -= newIndex2 - index2 + 1;
      index2 = newIndex2 + 1;
    }
  }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int totalLength = nums1.size() + nums2.size();
  if (totalLength % 2 == 1) {
    return getKthElement(nums1, nums2, (totalLength + 1) / 2);
  } else {
    return (getKthElement(nums1, nums2, totalLength / 2) +
            getKthElement(nums1, nums2, totalLength / 2 + 1)) /
           2.0;
  }
}

/*
33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了
旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3
处经旋转后可能变为 [4,5,6,7,0,1,2] 。 给你 旋转后 的数组 nums 和一个整数
target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
示例 1： 输入：nums = [4,5,6,7,0,1,2], target = 0 输出：4
*/
int search(vector<int>& nums, int target) {
  auto n = nums.size();
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] >= nums[left]) {
      if (target < nums[mid] && target >= nums[left])
        right = mid;
      else
        left = mid + 1;
    } else {
      if (target <= nums[right] && target > nums[mid])
        left = mid + 1;
      else
        right = mid;
    }
  }
  return -1;
}
// 旋转数组的最小值 剑指offer
// https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-by-leetcode-s/

/*
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值
target。找出给定目标值在数组中的开始位置和结束位置。 如果数组中不存在目标值
target，返回 [-1, -1]。 你可以设计并实现时间复杂度为 O(log n)
的算法解决此问题吗？ 示例 1： 输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
*/

vector<int> searchRange(vector<int>& nums, int target) {
  vector<int> result;
  if (nums.empty()) {
    result = vector(2, -1);
    return result;
  }
  int left_index = -1;
  int left = 0, right = nums.size() - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (target <= nums[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  if (nums[left] == target) {
    left_index = left;
  }

  result.push_back(left_index);
  int right_index = -1;
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    int mid = (left + right) / 2 + 1;
    if (target >= nums[mid]) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  if (nums[left] == target) {
    right_index = left;
  }
  result.push_back(right_index);
  return result;
}

/*
236. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
的深度尽可能大（一个节点也可以是它自己的祖先）。”
*/
class Solution236 {
 public:
  unordered_map<int, TreeNode*> fa;
  unordered_map<int, bool> vis;
  void dfs(TreeNode* root) {
    if (root->left != nullptr) {
      fa[root->left->val] = root;
      dfs(root->left);
    }
    if (root->right != nullptr) {
      fa[root->right->val] = root;
      dfs(root->right);
    }
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    fa[root->val] = nullptr;
    dfs(root);
    while (p != nullptr) {
      vis[p->val] = true;
      p = fa[p->val];
    }
    while (q != nullptr) {
      if (vis[q->val]) return q;
      q = fa[q->val];
    }
    return nullptr;
  }
};
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/
class Solution2362 {
 public:
  TreeNode* ans;
  bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return false;
    bool lson = dfs(root->left, p, q);
    bool rson = dfs(root->right, p, q);
    if ((lson && rson) ||
        ((root->val == p->val || root->val == q->val) && (lson || rson))) {
      ans = root;
    }
    return lson || rson || (root->val == p->val || root->val == q->val);
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ans;
  }
};