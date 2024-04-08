#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "common_define/data_type.h"

using namespace std;

/*
图是我们现实生活中连接关系的抽象，例如朋友圈、微博的关注关系。
图论中的很多问题都可以使用「深度优先搜索」或者「广度优先搜索」完成。
图论中有很多专门的问题，都使用计算机科学家的名字命名，例如 Dijkstra 算法、
Bellman-Ford 算法、Floyd 算法、Prim 算法、Kruskal 算法，
*/

/*
210. 课程表
IIhttps://leetcode.cn/problems/course-schedule-ii/solution/ke-cheng-biao-ii-by-leetcode-solution/
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组
prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须
先选修 bi 。 例如，想要学习课程 0 ，你需要先完成课程 1
，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回
任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组
*/
class Solution {
 private:
  // 存储有向图
  vector<vector<int>> edges;
  // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
  vector<int> visited;
  // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
  vector<int> result;
  // 判断有向图中是否有环
  bool valid = true;

 public:
  void dfs(int u) {
    // 将节点标记为「搜索中」
    visited[u] = 1;
    // 搜索其相邻节点
    // 只要发现有环，立刻停止搜索
    for (int v : edges[u]) {
      // 如果「未搜索」那么搜索相邻节点
      if (visited[v] == 0) {
        dfs(v);
        if (!valid) {
          return;
        }
      }
      // 如果「搜索中」说明找到了环
      else if (visited[v] == 1) {
        valid = false;
        return;
      }
    }
    // 将节点标记为「已完成」
    visited[u] = 2;
    // 将节点入栈
    result.push_back(u);
  }

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (const auto& info : prerequisites) {
      edges[info[1]].push_back(info[0]);
    }
    // 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
    for (int i = 0; i < numCourses && valid; ++i) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    if (!valid) {
      return {};
    }
    // 如果没有环，那么就有拓扑排序
    // 注意下标 0 为栈底，因此需要将数组反序输出
    reverse(result.begin(), result.end());
    return result;
  }
};

class Solution2 {
 private:
  // 存储有向图
  vector<vector<int>> edges;
  // 存储每个节点的入度
  vector<int> indeg;
  // 存储答案
  vector<int> result;

 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    indeg.resize(numCourses);
    for (const auto& info : prerequisites) {
      edges[info[1]].push_back(info[0]);
      ++indeg[info[0]];
    }

    queue<int> q;
    // 将所有入度为 0 的节点放入队列中
    for (int i = 0; i < numCourses; ++i) {
      if (indeg[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      // 从队首取出一个节点
      int u = q.front();
      q.pop();
      // 放入答案中
      result.push_back(u);
      for (int v : edges[u]) {
        --indeg[v];
        // 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了
        if (indeg[v] == 0) {
          q.push(v);
        }
      }
    }

    if (result.size() != numCourses) {
      return {};
    }
    return result;
  }
};