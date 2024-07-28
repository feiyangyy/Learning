#include "common_def.h"
#include <deque>

class Solution {
public:
  static vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int i = 1, j = 0;
    std::deque<int> q;
    std::vector<int> res;
    // 第一次构造窗口
    // 处于队列头部的数字，意味着：
    // 1. 该数的位置比较靠前
    // 2.
    // 该数的数值比较大（否则，其和其后部的数字所构成的窗口的最大值并不是头部数据）
    while (j < k) {
      if (q.size() == 0) {
        q.push_back(j);
      } else if (nums[j] > nums[q.front()]) {
        // 进来的数字比front大，则清空队列
        // 其实和底下是一回事
        while (!q.empty()) {
          q.pop_front();
        }
        q.push_front(j);
      } else {
        // 否则，在尾部插入，从尾部开始，比a[j]小的数，全部被踢出去
        while (!q.empty() && nums[q.back()] < nums[j]) {
          q.pop_back();
        }
        q.push_back(j);
      }
      ++j;
    }
    // 第一个最大值
    res.push_back(nums[q.front()]);
    // 开始移动
    while (i <= nums.size() - k) {
      if (i > q.front()) {
        // pop front 后第二大的数字自然成为最大致
        q.pop_front();
      }
      if (q.empty()) {
        q.push_back(j);
      } else if (nums[j] > nums[q.front()]) {
        while (!q.empty()) {
          // 清空队列
          q.pop_front();
        }
        q.push_front(j);
      } else {
        while (!q.empty() && nums[q.back()] < nums[j]) {
          q.pop_back();
        }
        q.push_back(j);
      }
      res.push_back(nums[q.front()]);
      ++i;
      ++j;
    }
    return res;
  }
};

int main() {
  std::vector<int> nums = {1, -1}; //{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 1;
  auto res = Solution::maxSlidingWindow(nums, k);
  return 0;
}