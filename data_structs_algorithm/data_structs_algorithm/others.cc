#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/* question31 下一个排列
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr
的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。 整数数组的 下一个排列
是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的
下一个排列
就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1]
不存在一个字典序更大的排列。 给你一个整数数组 nums ，找出 nums
的下一个排列。

必须 原地 修改，只允许使用额外常数空间。
输入：nums = [1,2,3]
输出：[1,3,2]
*/

void nextPermutation(vector<int>& nums) {
  if (nums.size() < 2) {
    return;
  }
  int i = nums.size() - 2;
  for (; i >= 0; --i) {
    if (nums[i] < nums[i + 1]) {
      break;
    }
  }
  int j = nums.size() - 1;
  // 找到了
  if (i >= 0) {
    while (nums[j] <= nums[i]) {
      --j;
    }
    swap(nums[i], nums[j]);
    ++i;
    j = nums.size() - 1;
  } else {
    i = 0;
  }
  while (i < nums.size() && j >= 0 && i < j) {
    swap(nums[i], nums[j]);
    ++i;
    --j;
  }
}

/*
62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为
“Finish” ）。
问总共有多少条不同的路径？
示例 1：
输入：m = 3, n = 7
输出：28
示例 2：
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
从左上角到右下角的过程中，我们需要移动 m+n-2m+n−2 次，其中有 m-1m−1
次向下移动，n-1n−1 次向右移动。因此路径的总数，就等于从 m+n-2m+n−2 次移动中选择
m-1m−1 次向下移动的方案数，即组合数：
*/
int uniquePaths(int m, int n) {
  long long ans = 1;
  for (int x = n, y = 1; y < m; ++x, ++y) {
    ans = ans * x / y;
  }
  return ans;
}
/*
121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子
卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/
int maxProfit(vector<int>& prices) {
  int inf = 1e9;
  int minprice = inf, maxprofit = 0;
  for (int price : prices) {
    maxprofit = max(maxprofit, price - minprice);
    minprice = min(price, minprice);
  }
  return maxprofit;
}

/*
169. 多数元素
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数
大于 ⌊ n/2 ⌋ 的元素。 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/

int majorityElement(vector<int>& nums) {
  int candidate = -1;
  int count = 0;
  for (int num : nums) {
    if (num == candidate)
      ++count;
    else if (--count < 0) {
      candidate = num;
      count = 1;
    }
  }
  return candidate;
}

/*
238. 除自身以外数组的乘积
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i]
之外其余各元素的乘积 。 题目数据 保证 数组
nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请不要使用除法，且在 O(n) 时间复杂度内完成此题。
*/
class Solution238 {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int length = nums.size();
    vector<int> answer(length);

    // answer[i] 表示索引 i 左侧所有元素的乘积
    // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
    answer[0] = 1;
    for (int i = 1; i < length; i++) {
      answer[i] = nums[i - 1] * answer[i - 1];
    }

    // R 为右侧所有元素的乘积
    // 刚开始右边没有元素，所以 R = 1
    int R = 1;
    for (int i = length - 1; i >= 0; i--) {
      // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
      answer[i] = answer[i] * R;
      // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
      R *= nums[i];
    }
    return answer;
  }
};

/*
question240
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target
。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
链接：https://leetcode.cn/problems/search-a-2d-matrix-ii
*/

class Solution240 {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = n - 1;
    while (x < m && y >= 0) {
      if (matrix[x][y] == target) {
        return true;
      }
      if (matrix[x][y] > target) {
        --y;
      } else {
        ++x;
      }
    }
    return false;
  }
};

/*
287. 寻找重复数
https://leetcode.cn/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和
n），可知至少存在一个重复的整数。 假设 nums 只有 一个重复的整数 ，返回
这个重复的数 。 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1)
的额外空间。
*/
class Solution287 {
 public:
  int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 1, r = n - 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        cnt += nums[i] <= mid;
      }
      if (cnt <= mid) {
        l = mid + 1;
      } else {
        r = mid - 1;
        ans = mid;
      }
    }
    return ans;
  }
};

class Solution2872 {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

/*
560. 和为 K 的子数组
https://leetcode.cn/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k
的子数组的个数 。 示例 1： 输入：nums = [1,1,1], k = 2 输出：2

前缀和
*/
int subarraySum(vector<int>& nums, int k) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int count = 0, pre = 0;
  for (auto& x : nums) {
    pre += x;
    if (mp.find(pre - k) != mp.end()) {
      count += mp[pre - k];
    }
    mp[pre]++;
  }
  return count;
}

/*
https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leet-yhlf/
581. 最短无序连续子数组
给你一个整数数组 nums ，你需要找出一个 连续子数组
，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
请你找出符合题意的 最短 子数组，并输出它的长度。
*/
int findUnsortedSubarray(vector<int>& nums) {
  int n = nums.size();
  int maxn = INT_MIN, right = -1;
  int minn = INT_MAX, left = -1;
  for (int i = 0; i < n; i++) {
    if (maxn > nums[i]) {
      right = i;
    } else {
      maxn = nums[i];
    }
    if (nums[n - i - 1] > minn) {
      left = n - i - 1;
    } else {
      minn = nums[n - i - 1];
    }
  }
  return right == -1 ? 0 : right - left + 1;
}

/*
647. 回文子串
https://leetcode.cn/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode-solution/
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
*/
int countSubstrings(string s) {
  int n = s.size(), ans = 0;
  for (int i = 0; i < 2 * n - 1; ++i) {
    int l = i / 2, r = i / 2 + i % 2;
    while (l >= 0 && r < n && s[l] == s[r]) {
      --l;
      ++r;
      ++ans;
    }
  }
  return ans;
}