#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
question 5 https://leetcode-cn.com/problems/longest-palindromic-substring/
给你一个字符串 s，找到 s 中最长的回文子串。
示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
*/

std::string LongestPalindrome(std::string s) {
  int n = s.size();
  std::vector<std::vector<int>> dp(n, std::vector<int>(n));
  std::string ans;
  for (int length = 0; length < n; ++length) {
    for (int i = 0; i + length < n; ++i) {
      int j = i + length;
      if (length == 0) {
        dp[i][j] = 1;
      } else if (length == 1) {
        dp[i][j] = (s[i] == s[j]);
      } else {
        dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
      }
      if (dp[i][j] && length + 1 > ans.size()) {
        ans = s.substr(i, length + 1);
      }
    }
  }
  return ans;
}

/*
64. 最小路径和
https://leetcode-cn.com/problems/minimum-path-sum/solution/zui-xiao-lu-jing-he-by-leetcode-solution/
给定一个包含非负整数的 m x n 网格 grid
，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12

动态规划
创建二维数组dp，与原始网格的大小相同，dp[i][j] 表示从左上角出发到(i,j) 位置的最小路径和。显然，dp[0][0]=grid[0][0]。
对于dp 中的其余元素，通过以下状态转移方程计算元素值。
*/
int minPathSum(vector<vector<int>>& grid) {
  if (grid.size() == 0 || grid[0].size() == 0) {
    return 0;
  }
  int rows = grid.size(), columns = grid[0].size();
  auto dp = vector<vector<int>>(rows, vector<int>(columns));
  dp[0][0] = grid[0][0];
  for (int i = 1; i < rows; i++) {
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  }
  for (int j = 1; j < columns; j++) {
    dp[0][j] = dp[0][j - 1] + grid[0][j];
  }
  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < columns; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
  }
  return dp[rows - 1][columns - 1];
}

/*
139.
单词拆分https://leetcode.cn/problems/word-break/solution/dan-ci-chai-fen-by-leetcode-solution/
给你一个字符串 s 和一个字符串列表 wordDict
作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
dp[i] 表示字符串 ss 前 ii 个字符组成的字符串 s[0..i-1]s[0..i−1]
是否能被空格拆分成若干个字典中出现的单词 dp[i]=dp[j] && check(s[j..i−1])
*/
bool wordBreak(string s, vector<string>& wordDict) {
  auto wordDictSet = unordered_set<string>();
  for (auto word : wordDict) {
    wordDictSet.insert(word);
  }

  auto dp = vector<bool>(s.size() + 1);
  dp[0] = true;
  for (int i = 1; i <= s.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
        dp[i] = true;
        break;
      }
    }
  }

  return dp[s.size()];
}

/*
152. 乘积最大子数组
https://leetcode-cn.com/problems/maximum-product-subarray/solution/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/
给你一个整数数组 nums
，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
测试用例的答案是一个 32-位 整数。
子数组 是数组的连续子序列。
示例 1:
输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
动态规划
*/

int maxProduct(vector<int>& nums) {
  //初始化了maxF[0]为nums[0]
  vector<int> maxF(nums), minF(nums);
  for (int i = 1; i < nums.size(); ++i) {
    maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
    minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
  }
  return *max_element(maxF.begin(), maxF.end());
}

/*
198. 打家劫舍
https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-leetcode-solution/
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下
，一夜之内能够偷窃到的最高金额。 示例 1： 输入：[1,2,3,1] 输出：4 解释：偷窃 1
号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。 偷窃到的最高金额 = 1 + 3 = 4
。 动态规划用dp[i] 表示前 i间房屋能偷窃到的最高总金额，那么就有如下的状态转移方程：
*/
int rob(vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }
  int size = nums.size();
  if (size == 1) {
    return nums[0];
  }
  // vector<int> dp = vector<int>(size, 0);
  // dp[0] = nums[0];
  // dp[1] = max(nums[0], nums[1]);
  // for (int i = 2; i < size; i++) {
  //   dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
  // }
  // return dp[size - 1];

  int first = nums[0], second = max(nums[0], nums[1]);
  for (int i = 2; i < size; i++) {
    int temp = second;
    second = max(first + nums[i], second);
    first = temp;
  }
  return second;
}

/*
221. 最大正方形
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1'
的最大正方形，并返回其面积。
我们用dp(i,j) 表示以 (i, j)(i,j) 为右下角，且只包含 1 的正方形的边长最大值。
如果我们能计算出所有 dp(i,j) 的值，那么其中的最大值即为矩阵中只包含 1 的正方形
的边长最大值，其平方即为最大正方形的面积。
*/
class Solution221 {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return 0;
    }
    int maxSide = 0;
    int rows = matrix.size(), columns = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (matrix[i][j] == '1') {
          if (i == 0 || j == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] =
                min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
          }
          maxSide = max(maxSide, dp[i][j]);
        }
      }
    }
    int maxSquare = maxSide * maxSide;
    return maxSquare;
  }
};

/*
279. 完全平方数
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数
是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。*/
class Solution279 {
 public:
  int numSquares(int n) {
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
      int minn = INT_MAX;
      for (int j = 1; j * j <= i; j++) {
        minn = min(minn, f[i - j * j]);
      }
      f[i] = minn + 1;
    }
    return f[n];
  }
};

/*
309. 最佳买卖股票时机含冷冻期
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格
。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */
int maxProfit(vector<int>& prices) {
  if (prices.empty()) {
    return 0;
  }

  int n = prices.size();
  int f0 = -prices[0];
  int f1 = 0;
  int f2 = 0;
  for (int i = 1; i < n; ++i) {
    int newf0 = max(f0, f2 - prices[i]);
    int newf1 = f0 + prices[i];
    int newf2 = max(f1, f2);
    f0 = newf0;
    f1 = newf1;
    f2 = newf2;
  }

  return max(f1, f2);
}

/*
322. 零钱兑换
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数
。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。
 */

int coinChange(vector<int>& coins, int amount) {
  int Max = amount + 1;
  vector<int> dp(amount + 1, Max);
  dp[0] = 0;
  for (int i = 1; i <= amount; ++i) {
    for (int j = 0; j < (int)coins.size(); ++j) {
      if (coins[j] <= i) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }
  return dp[amount] > amount ? -1 : dp[amount];
}

/*
337. 打家劫舍 III
链接：https://leetcode.cn/problems/house-robber-iii/solution/da-jia-jie-she-iii-by-leetcode-solution/
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的
小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。 给定二叉树的 root 。返回
在不触动警报的情况下 ，小偷能够盗取的最高金额 。
*/

struct SubtreeStatus {
  int selected;
  int notSelected;
};

class Solution {
 public:
  SubtreeStatus dfs(TreeNode* node) {
    if (!node) {
      return {0, 0};
    }
    auto l = dfs(node->left);
    auto r = dfs(node->right);
    int selected = node->val + l.notSelected + r.notSelected;
    int notSelected =
        max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
    return {selected, notSelected};
  }

  int rob(TreeNode* root) {
    auto rootStatus = dfs(root);
    return max(rootStatus.selected, rootStatus.notSelected);
  }
};

/*
338. 比特位计数
链接：https://leetcode.cn/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode-solution-0t1i/
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数
，返回一个长度为 n + 1 的数组 ans 作为答案。
*/

vector<int> countBits(int n) {
  vector<int> bits(n + 1);
  for (int i = 1; i <= n; i++) {
    bits[i] = bits[i >> 1] + (i & 1);
  }
  return bits;
}

/*
416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums
。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
*/
bool canPartition(vector<int>& nums) {
  int n = nums.size();
  if (n < 2) {
    return false;
  }
  int sum = 0, maxNum = 0;
  for (auto& num : nums) {
    sum += num;
    maxNum = max(maxNum, num);
  }
  if (sum & 1) {
    return false;
  }
  int target = sum / 2;
  if (maxNum > target) {
    return false;
  }
  vector<int> dp(target + 1, 0);
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    int num = nums[i];
    for (int j = target; j >= num; --j) {
      dp[j] |= dp[j - num];
    }
  }
  return dp[target];
}