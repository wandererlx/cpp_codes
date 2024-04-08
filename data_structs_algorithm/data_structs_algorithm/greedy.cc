#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
贪心算法（又称贪婪算法）是指，在对问题求解时，总是做出在当前看来是最好的选择，就能得到问题的答案。
贪心算法需要充分挖掘题目中条件，没有固定的模式，解决有贪心算法需要一定的直觉和经验。贪心算法不是对
所有问题都能得到整体最优解。能使用贪心算法解决的问题具有「贪心选择性质」。「贪心选择性质」严格意义
上需要数学证明。能使用贪心算法解决的问题必须具备「无后效性」，即某个状态以前的过程不会影响以后的状态，
只与当前状态有关。
*/

/*
55. 跳跃游戏 https://leetcode-cn.com/problems/jump-game/  贪心
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3
步到达最后一个下标。 示例 2： 输入：nums = [3,2,1,0,4] 输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ，
所以永远不可能到达最后一个下标。
*/

bool canJump(vector<int>& nums) {
  int n = nums.size();
  int rightmost = 0;
  for (int i = 0; i < n; ++i) {
    if (i <= rightmost) {
      rightmost = max(rightmost, i + nums[i]);
      if (rightmost >= n - 1) {
        return true;
      }
    }
  }
  return false;
}

/*
300. 最长递增子序列
https://leetcode.cn/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列
是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7]
是数组 [0,3,1,6,2,2,7] 的子序列。
*/
int lengthOfLIS(vector<int>& nums) {
  int len = 1, n = (int)nums.size();
  if (n == 0) {
    return 0;
  }
  vector<int> d(n + 1, 0);
  d[len] = nums[0];
  for (int i = 1; i < n; ++i) {
    if (nums[i] > d[len]) {
      d[++len] = nums[i];
    } else {
      int l = 1, r = len,
          pos = 0;  // 如果找不到说明所有的数都比 nums[i] 大，此时要更新
                    // d[1]，所以这里将 pos 设为 0
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (d[mid] < nums[i]) {
          pos = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      d[pos + 1] = nums[i];
    }
  }
  return len;
}