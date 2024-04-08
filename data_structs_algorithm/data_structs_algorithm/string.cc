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
43. 字符串相乘 https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2
的乘积，它们的乘积也表示为字符串形式。 注意：不能使用任何内置的 BigInteger
库或直接将输入转换为整数。
*/
string addStrings(string& num1, string& num2) {
  int i = num1.size() - 1, j = num2.size() - 1, add = 0;
  string ans;
  while (i >= 0 || j >= 0 || add != 0) {
    int x = i >= 0 ? num1.at(i) - '0' : 0;
    int y = j >= 0 ? num2.at(j) - '0' : 0;
    int result = x + y + add;
    ans.push_back(result % 10);
    add = result / 10;
    i--;
    j--;
  }
  reverse(ans.begin(), ans.end());
  for (auto& c : ans) {
    c += '0';
  }
  return ans;
}
// 时间复杂度：O(mn+n^2) 空间复杂度：O(m+n)
string multiply(string num1, string num2) {
  if (num1 == "0" || num2 == "0") {
    return "0";
  }
  string ans = "0";
  int m = num1.size(), n = num2.size();
  for (int i = n - 1; i >= 0; i--) {
    string curr;
    int add = 0;
    for (int j = n - 1; j > i; j--) {
      curr.push_back(0);
    }
    int y = num2.at(i) - '0';
    for (int j = m - 1; j >= 0; j--) {
      int x = num1.at(j) - '0';
      int product = x * y + add;
      curr.push_back(product % 10);
      add = product / 10;
    }
    while (add != 0) {
      curr.push_back(add % 10);
      add /= 10;
    }
    reverse(curr.begin(), curr.end());
    for (auto& c : curr) {
      c += '0';
    }
    ans = addStrings(ans, curr);
  }
  return ans;
}
// 时间复杂度：O(mn) 空间复杂度：O(m+n)
string multiply2(string num1, string num2) {
  if (num1 == "0" || num2 == "0") {
    return "0";
  }
  int m = num1.size(), n = num2.size();
  auto ansArr = vector<int>(m + n);
  for (int i = m - 1; i >= 0; i--) {
    int x = num1.at(i) - '0';
    for (int j = n - 1; j >= 0; j--) {
      int y = num2.at(j) - '0';
      ansArr[i + j + 1] += x * y;
    }
  }
  for (int i = m + n - 1; i > 0; i--) {
    ansArr[i - 1] += ansArr[i] / 10;
    ansArr[i] %= 10;
  }
  int index = ansArr[0] == 0 ? 1 : 0;
  string ans;
  while (index < m + n) {
    ans.push_back(ansArr[index]);
    index++;
  }
  for (auto& c : ans) {
    c += '0';
  }
  return ans;
}

/*
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词
是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> res;
  unordered_map<string, vector<string>> M;
  for (int i = 0; i < strs.size(); i++) {
    string key = strs[i];
    sort(key.begin(), key.end());
    M[key].push_back(strs[i]);
  }
  for (auto ite = M.begin(); ite != M.end(); ite++) res.push_back(ite->second);
  return res;
}