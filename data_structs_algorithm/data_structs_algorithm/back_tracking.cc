#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
回溯法（back tracking）（探索与回溯法）是一种选优搜索法，又称为试探法，
按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，
就退回到上一步，重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为“回溯点”。
*/

/*
question 17
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/
void backtrack(vector<string>& combinations,
               const unordered_map<char, string>& phoneMap,
               const string& digits, int index, string& combination) {
  if (index == digits.length()) {
    combinations.push_back(combination);
  } else {
    char digit = digits[index];
    const string& letters = phoneMap.at(digit);
    for (const char& letter : letters) {
      combination.push_back(letter);
      backtrack(combinations, phoneMap, digits, index + 1, combination);
      combination.pop_back();
    }
  }
}

vector<string> LetterCombinations(string digits) {
  vector<string> combinations;
  if (digits.empty()) {
    return combinations;
  }
  unordered_map<char, string> phoneMap{
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
  string combination;
  backtrack(combinations, phoneMap, digits, 0, combination);
  return combinations;
}

/**
 question22 括号生成
https://leetcode-cn.com/problems/generate-parentheses/
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
有效的 括号组合。 示例 1： 输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
 */

void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
  if (cur.size() == n * 2) {
    ans.push_back(cur);
    return;
  }
  if (open < n) {
    cur.push_back('(');
    backtrack(ans, cur, open + 1, close, n);
    cur.pop_back();
  }
  if (close < open) {
    cur.push_back(')');
    backtrack(ans, cur, open, close + 1, n);
    cur.pop_back();
  }
}
vector<string> generateParenthesis(int n) {
  vector<string> result;
  string current;
  backtrack(result, current, 0, 0, n);
  return result;
}

/*
46. 全排列 https://leetcode-cn.com/problems/permutations/   回溯
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序
返回答案。 示例 1： 输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

void back(vector<int>& nums, vector<vector<int>>& res, int first, int end) {
  if (first == end) {
    res.push_back(nums);
    return;
  }
  for (int i = first; i < end; ++i) {
    swap(nums[first], nums[i]);
    back(nums, res, first + 1, end);
    swap(nums[first], nums[i]);
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> res;
  back(nums, res, 0, nums.size());
  return res;
}

/*
八皇后问题：剑指offer28题
在8 X
8的国际象棋上摆放八个皇后，使其不能相互攻击，即任意两个皇后不得处于同一行，同一列或者同意对角线上，求出所有符合条件的摆法。
全排列解决八皇后问题的思路如下：
由于8个皇后不能处在同一行，那么肯定每个皇后占据一行，这样可以定义一个数组A[8]，数组中第i个数字，即A[i]表示位于第i行的皇后的列号。
先把数组A[8]分别用0-7初始化，接下来对该数组做全排列，由于我们用0-7这7个不同的数字初始化数组，因此任意两个皇后肯定也不同列，
那么我们只需要判断每个排列对应的8个皇后中是否有任意两个在同一对角线上即可，即对于数组的两个下标i和j，如果i-j==A[i]-A[j]或i-j==A[j]-A[i]，
则认为有两个元素位于了同一个对角线上，则该排列不符合条件
*/
void EightQueens() {
  vector<int> data{0, 1, 2, 3, 4, 5, 6, 7};
  vector<vector<int>> pre_result = permute(data);
  vector<vector<int>> result;
  for (const auto& one_possinle : pre_result) {
    int i, j;
    bool can = true;  //是否又符合条件的摆法
    for (i = 0; i < 8; i++) {
      for (j = i + 1; j < 8; j++) {
        if (!can) {
          break;
        }
        if (i - j == one_possinle[i] - one_possinle[j] ||
            i - j == one_possinle[j] - one_possinle[i]) {
          //如果任意两个在一条对角线上，则不符合
          can = false;
          break;
        }
      }
    }
    //有符合的摆法，就打印出来
    if (can) {
      result.emplace_back(one_possinle);
    }
  }
}

/*
79. 单词搜索 https://leetcode-cn.com/problems/word-search/  回溯
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word
存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
"ABCCED" 输出：true
*/
bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i,
           int j, string& s, int k) {
  if (board[i][j] != s[k]) {
    return false;
  } else if (k == s.length() - 1) {
    return true;
  }
  visited[i][j] = true;
  vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool result = false;
  for (const auto& dir : directions) {
    int newi = i + dir.first, newj = j + dir.second;
    if (newi >= 0 && newi < board.size() && newj >= 0 &&
        newj < board[0].size()) {
      if (!visited[newi][newj]) {
        bool flag = check(board, visited, newi, newj, s, k + 1);
        if (flag) {
          result = true;
          break;
        }
      }
    }
  }
  visited[i][j] = false;
  return result;
}

bool exist(vector<vector<char>>& board, string word) {
  int h = board.size(), w = board[0].size();
  vector<vector<int>> visited(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      bool flag = check(board, visited, i, j, word, 0);
      if (flag) {
        return true;
      }
    }
  }
  return false;
}

/*
494. 目标和
https://leetcode.cn/problems/target-sum/solution/mu-biao-he-by-leetcode-solution-o0cp/
给你一个整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-'
，然后串联起来得到表达式 "+2-1" 。 返回可以通过上述方法构造的、运算结果等于
target 的不同 表达式 的数目。
*/
class Solution {
 public:
  int count = 0;

  int findTargetSumWays(vector<int>& nums, int target) {
    backtrack(nums, target, 0, 0);
    return count;
  }

  void backtrack(vector<int>& nums, int target, int index, int sum) {
    if (index == nums.size()) {
      if (sum == target) {
        count++;
      }
    } else {
      backtrack(nums, target, index + 1, sum + nums[index]);
      backtrack(nums, target, index + 1, sum - nums[index]);
    }
  }
};