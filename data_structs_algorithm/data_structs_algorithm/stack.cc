#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
155. 最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
*/

class MinStack {
  stack<int> x_stack;
  stack<int> min_stack;

 public:
  MinStack() { min_stack.push(INT_MAX); }

  void push(int x) {
    x_stack.push(x);
    min_stack.push(min(min_stack.top(), x));
  }

  void pop() {
    x_stack.pop();
    min_stack.pop();
  }

  int top() { return x_stack.top(); }

  int getMin() { return min_stack.top(); }
};

/*
394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k
次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k
，例如不会出现像 3a 或 2[4] 的输入。 输入：s = "3[a2[c]]" 输出："accaccacc"
*/
class Solution {
 public:
  string getDigits(string &s, size_t &ptr) {
    string ret = "";
    while (isdigit(s[ptr])) {
      ret.push_back(s[ptr++]);
    }
    return ret;
  }

  string getString(vector<string> &v) {
    string ret;
    for (const auto &s : v) {
      ret += s;
    }
    return ret;
  }

  string decodeString(string s) {
    vector<string> stk;
    size_t ptr = 0;

    while (ptr < s.size()) {
      char cur = s[ptr];
      if (isdigit(cur)) {
        // 获取一个数字并进栈
        string digits = getDigits(s, ptr);
        stk.push_back(digits);
      } else if (isalpha(cur) || cur == '[') {
        // 获取一个字母并进栈
        stk.push_back(string(1, s[ptr++]));
      } else {
        ++ptr;
        vector<string> sub;
        while (stk.back() != "[") {
          sub.push_back(stk.back());
          stk.pop_back();
        }
        reverse(sub.begin(), sub.end());
        // 左括号出栈
        stk.pop_back();
        // 此时栈顶为当前 sub 对应的字符串应该出现的次数
        int repTime = stoi(stk.back());
        stk.pop_back();
        string t, o = getString(sub);
        // 构造字符串
        while (repTime--) t += o;
        // 将构造好的字符串入栈
        stk.push_back(t);
      }
    }

    return getString(stk);
  }
};

/*
739. 每日温度
https://leetcode.cn/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode-solution/
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
其中 answer[i] 是指在第 i
天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。

单调栈
可以维护一个存储下标的单调栈，从栈底到栈顶的下标对应的温度列表中的温度依次递减。如果一个下标在单调栈里，则表示尚未找到下一次温度更高的下标
正向遍历温度列表。对于温度列表中的每个元素 temperatures[i]，如果栈为空，则直接将 i 进栈，如果栈不为空，则比较栈顶元素 prevIndex 
对应的温度 temperatures[prevIndex] 和当前温度 temperatures[i]，如果 temperatures[i] > temperatures[prevIndex]，则将 
prevIndex 移除，并将 prevIndex 对应的等待天数赋为 i - prevIndex，重复上述操作直到栈为空或者栈顶元素对应的温度小于等于当前温度，
然后将 i 进栈。
为什么可以在弹栈的时候更新 ans[prevIndex] 呢？因为在这种情况下，即将进栈的 i 对应的 temperatures[i] 一定是 temperatures[prevIndex] 
右边第一个比它大的元素，试想如果 prevIndex 和 i 有比它大的元素，假设下标为 j，那么 prevIndex 一定会在下标 j 的那一轮被弹掉。
由于单调栈满足从栈底到栈顶元素对应的温度递减，因此每次有元素进栈时，会将温度更低的元素全部移除，并更新出栈元素对应的等待天数，这样可以确保
等待天数一定是最小的。
*/
vector<int> dailyTemperatures(vector<int> &temperatures) {
  int n = temperatures.size();
  vector<int> ans(n);
  stack<int> s;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
      int previousIndex = s.top();
      ans[previousIndex] = i - previousIndex;
      s.pop();
    }
    s.push(i);
  }
  return ans;
}