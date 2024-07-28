#include "common_def.h"
// 1. dfs为什么不合适?
// dfs相当于枚举所有可能，所以此处使用深搜，和暴力枚举法没啥区别
// 2.
// 解题思路，此题较为tricky，需要使用头尾指针处理，同时使用排序，当ni + nj + nk
// = 0时，如果有相同元素则一定位于相邻位置，则直接可用
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int i, j, k;
    int size = nums.size();
    i = 0;
    vector<vector<int>> res;
    for (int i = 0; i < size - 2; ++i) {
      if (nums[i] > 0) {
        continue;
      }
      if (i && nums[i] == nums[i - 1]) {
        continue;
      }
      j = i + 1;
      k = size - 1;
      while (j < k) {
        int s = nums[i] + nums[j] + nums[k];
        if (s == 0) {
          std::vector<int> tmp;
          tmp.push_back(nums[i]);
          tmp.push_back(nums[j]);
          tmp.push_back(nums[k]);
          res.push_back(tmp);
          // 注意, j k的重复值可能会使得结果存在重复解
          ++j;
          --k;
          while (j < k && nums[j] == nums[j - 1]) {
            ++j;
          }
          while (j < k && nums[k] == nums[k + 1]) {
            --k;
          }
        } else if (s > 0) {
          --k;
          // 跳过重复解
          while (j < k && nums[k] == nums[k + 1]) {
            --k;
          }
        } else {
          ++j;
          while (j < k && nums[j] == nums[j - 1]) {
            ++j;
          }
        }
      }
    }
    return res;
  }
};

int main() {
  std::vector<int> r = {-1, 0, 1, 2, -1, -4};
  Solution().threeSum(r);
  return 0;
}