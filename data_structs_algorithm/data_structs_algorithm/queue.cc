#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
239. 滑动窗口最大值
https://leetcode.cn/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetco-ki6m/
给你一个整数数组 nums，有一个大小为 k
的滑动窗口从数组的最左侧移动到数组的最右侧。 你只可以看到在滑动窗口内的 k
个数字。滑动窗口每次只向右移动一位。 返回 滑动窗口中的最大值
*/

class Solution239 {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> q;
    for (int i = 0; i < k; ++i) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }

    vector<int> ans = {nums[q.front()]};
    for (int i = k; i < n; ++i) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
      while (q.front() <= i - k) {
        q.pop_front();
      }
      ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};