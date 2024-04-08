/*
深度优先搜索算法（英语：Depth-First-Search，DFS）是一种用于遍历或搜索树或图的算法。
其过程简要来说是对每一个可能的分支路径深入到不能再深入为止，而且每个结点只能访问一次.
*/
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出
candidates 中可以使数字和为目标数 target 的 所有 不同组合
，并以列表形式返回。你可以按 任意顺序 返回这些组合。 candidates 中的 同一个
数字可以 无限制重复被选取
。如果至少一个数字的被选数量不同，则两种组合是不同的。
对于给定的输入，保证和为 target 的不同组合数少于 150 个。
示例 1：
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
*/

void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans,
         vector<int>& combine, int idx) {
  if (idx == candidates.size()) {
    return;
  }
  if (target == 0) {
    ans.emplace_back(combine);
    return;
  }
  // 直接跳过
  dfs(candidates, target, ans, combine, idx + 1);
  // 选择当前数
  if (target - candidates[idx] >= 0) {
    combine.emplace_back(candidates[idx]);
    dfs(candidates, target - candidates[idx], ans, combine, idx);
    combine.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> ans;
  vector<int> combine;
  dfs(candidates, target, ans, combine, 0);
  return ans;
}

/*
78. 子集
https://leetcode-cn.com/problems/subsets/solution/zi-ji-by-leetcode-solution/
给你一个整数数组 nums ，数组中的元素 互不相同
。返回该数组所有可能的子集（幂集）。 解集 不能 包含重复的子集。你可以按 任意顺序
返回解集。 示例 1： 输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/
vector<int> t;
vector<vector<int>> ans;

void dfs(int cur, vector<int>& nums) {
  if (cur == nums.size()) {
    ans.push_back(t);
    return;
  }
  t.push_back(nums[cur]);
  dfs(cur + 1, nums);
  t.pop_back();
  dfs(cur + 1, nums);
}

vector<vector<int>> subsets(vector<int>& nums) {
  dfs(0, nums);
  return ans;
}

/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/
void dfs(vector<vector<char>>& grid, int r, int c) {
  int nr = grid.size();
  int nc = grid[0].size();

  grid[r][c] = '0';
  if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
  if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
  if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
  if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
}

int numIslands(vector<vector<char>>& grid) {
  int nr = grid.size();
  if (!nr) return 0;
  int nc = grid[0].size();

  int num_islands = 0;
  for (int r = 0; r < nr; ++r) {
    for (int c = 0; c < nc; ++c) {
      if (grid[r][c] == '1') {
        ++num_islands;
        dfs(grid, r, c);
      }
    }
  }
  return num_islands;
}