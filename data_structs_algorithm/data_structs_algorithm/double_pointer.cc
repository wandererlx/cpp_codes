#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
question 11  https://leetcode-cn.com/problems/container-with-most-water/
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i,
0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
说明：你不能倾斜容器。

输入：[1,8,6,2,5,4,8,3,7]
输出：49
解释：图中垂直线代表输入数组
[1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
*/
int MaxArea(std::vector<int>& height) {
  int l = 0, r = height.size() - 1;
  int ans = 0;
  while (l < r) {
    int area = std::min(height[l], height[r]) * (r - l);
    ans = std::max(ans, area);
    if (height[l] <= height[r]) {
      ++l;
    } else {
      --r;
    }
  }
  return ans;
}

/*
question 15  排序双指针
https://leetcode-cn.com/problems/3sum/solution/san-shu-zhi-he-by-leetcode-solution/
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a
+ b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
*/
std::vector<std::vector<int>> ThreeSum(std::vector<int>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> ans;
  // 枚举 a
  for (int first = 0; first < n; ++first) {
    // 需要和上一次枚举的数不相同
    if (first > 0 && nums[first] == nums[first - 1]) {
      continue;
    }
    // c 对应的指针初始指向数组的最右端
    int third = n - 1;
    int target = -nums[first];
    // 枚举 b
    for (int second = first + 1; second < n; ++second) {
      // 需要和上一次枚举的数不相同
      if (second > first + 1 && nums[second] == nums[second - 1]) {
        continue;
      }
      // 需要保证 b 的指针在 c 的指针的左侧
      while (second < third && nums[second] + nums[third] > target) {
        --third;
      }
      // 如果指针重合，随着 b 后续的增加
      // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
      // b不能等于c 要求是三个元素
      if (second == third) {
        break;
      }
      if (nums[second] + nums[third] == target) {
        ans.push_back({nums[first], nums[second], nums[third]});
      }
    }
  }
  return ans;
}

// question3 无重复字符的最长子串
int lengthOfLongestSubstring(string s) {
  // 哈希集合，记录每个字符是否出现过
  unordered_set<char> occ;
  int n = s.size();
  // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
  int rk = -1, ans = 0;
  // 枚举左指针的位置，初始值隐性地表示为 -1
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      // 左指针向右移动一格，移除一个字符
      occ.erase(s[i - 1]);
    }
    while (rk + 1 < n && !occ.count(s[rk + 1])) {
      // 不断地移动右指针
      occ.insert(s[rk + 1]);
      ++rk;
    }
    // 第 i 到 rk 个字符是一个极长的无重复字符子串
    ans = max(ans, rk - i + 1);
  }
  return ans;
}

/*
42. 接雨水
https://leetcode.cn/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/
给定 n 个非负整数表示每个宽度为 1
的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
// 时间o(n) 空间o(n)
int trap1(vector<int>& height) {
  int n = height.size();
  if (n == 0) {
    return 0;
  }
  vector<int> leftMax(n);
  leftMax[0] = height[0];
  for (int i = 1; i < n; ++i) {
    leftMax[i] = max(leftMax[i - 1], height[i]);
  }

  vector<int> rightMax(n);
  rightMax[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    rightMax[i] = max(rightMax[i + 1], height[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += min(leftMax[i], rightMax[i]) - height[i];
  }
  return ans;
}
// // 时间o(n) 空间o(1)
int trap(vector<int>& height) {
  int ans = 0;
  int left = 0, right = height.size() - 1;
  int leftMax = 0, rightMax = 0;
  while (left < right) {
    leftMax = max(leftMax, height[left]);
    rightMax = max(rightMax, height[right]);
    /*
    双指针可以这么理解： 一开始两个指针在两端，假设h[left] < h[right] ，则有left
    ++ 直到 h[left] > h[right]。
    那么此时，h[left]是遍历过程中第一个大于h[right]的，显然是遍历过程中的最大值。
    然后right -- 直到 h[right] > h[left]
    ，同样的，此时h[right]为遍历过程中的最大值。 即：left移动时，h[right] =
    rightMax。 right移动时，h[left] = leftMax h[left] < h[right]
    的情况只会出现在：right 刚刚找到自己的最大值，left在寻找更大值的过程中。
     所以此时必然有leftMax < rightMax
    */
    if (height[left] < height[right]) {
      ans += leftMax - height[left];
      ++left;
    } else {
      ans += rightMax - height[right];
      --right;
    }
  }
  return ans;
}