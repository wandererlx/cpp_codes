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
56. 合并区间 https://leetcode-cn.com/problems/merge-intervals/
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti,
endi] 。请你合并所有重叠的区间，并返回
一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。 示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  if (intervals.size() == 0) {
    return {};
  }
  sort(intervals.begin(), intervals.end(),
       [](const vector<int>& left, const vector<int>& right) {
         return left[0] < right[0];
       });
  vector<vector<int>> merged;
  for (int i = 0; i < intervals.size(); ++i) {
    int L = intervals[i][0], R = intervals[i][1];
    if (merged.empty() || merged.back()[1] < L) {
      merged.push_back({L, R});
    } else {
      merged.back()[1] = max(merged.back()[1], R);
    }
  }
  return merged;
}

/*
75. 颜色分类
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums
，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库的sort函数的情况下解决这个问题。
示例 1：
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
*/

void sortColors(vector<int>& nums) {
  int n = nums.size();
  int p0 = 0, p2 = n - 1;
  for (int i = 0; i <= p2; ++i) {
    while (nums[i] == 2 && i <= p2) {
      swap(nums[i], nums[p2]);
      --p2;
    }
    if (nums[i] == 0) {
      swap(nums[i], nums[p0]);
      ++p0;
    }
  }
}

/*
215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/
class Solution215 {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return quickSort(nums, 0, nums.size() - 1, k);
  }

 private:
  int quickSort(vector<int>& nums, int start, int end, int k) {
    int mid = rand() % (end - start + 1) + start;
    int mid_value = nums[mid];
    swap(nums[mid], nums[end]);
    int index = start - 1;
    // 4,2,3
    for (int i = start; i < end; ++i) {
      if (nums[i] > mid_value) {
        swap(nums[i], nums[++index]);
      }
    }
    swap(nums[++index], nums[end]);
    if ((index - start + 1) == k) {
      return nums[index];
    } else if ((index - start + 1) > k) {
      return quickSort(nums, start, index - 1, k);
    } else {
      return quickSort(nums, index + 1, end, k - (index - start + 1));
    }
  }
};

class Solution2152 {
 public:
  void maxHeapify(vector<int>& a, int i, int heapSize) {
    int l = i * 2 + 1, r = i * 2 + 2, largest = i;
    if (l < heapSize && a[l] > a[largest]) {
      largest = l;
    }
    if (r < heapSize && a[r] > a[largest]) {
      largest = r;
    }
    if (largest != i) {
      swap(a[i], a[largest]);
      maxHeapify(a, largest, heapSize);
    }
  }

  void buildMaxHeap(vector<int>& a, int heapSize) {
    for (int i = heapSize / 2; i >= 0; --i) {
      maxHeapify(a, i, heapSize);
    }
  }

  int findKthLargest(vector<int>& nums, int k) {
    int heapSize = nums.size();
    buildMaxHeap(nums, heapSize);
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
      swap(nums[0], nums[i]);
      --heapSize;
      maxHeapify(nums, 0, heapSize);
    }
    return nums[0];
  }
};

/*
406. 根据身高重建队列
https://leetcode.cn/problems/queue-reconstruction-by-height/solution/gen-ju-shen-gao-zhong-jian-dui-lie-by-leetcode-sol/
假设有打乱顺序的一群人站成一个队列，数组 people
表示队列中一些人的属性（不一定按顺序）。 每个 people[i] = [hi, ki] 表示第 i
个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue
， 其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0]
是排在队列前面的人）。
*/
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
  sort(people.begin(), people.end(),
       [](const vector<int>& u, const vector<int>& v) {
         return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
       });
  vector<vector<int>> ans;
  for (const vector<int>& person : people) {
    ans.insert(ans.begin() + person[1], person);
  }
  return ans;
}