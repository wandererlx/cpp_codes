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
438. 找到字符串中所有字母异位词
https://leetcode.cn/problems/find-all-anagrams-in-a-string/solution/zhao-dao-zi-fu-chuan-zhong-suo-you-zi-mu-xzin/
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};