#include "common_def.h"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int i, j, k, l;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> res;
    int64_t tgt = target;
    for (i = 0; i < size - 3; ++i) {
      if (i && (nums[i] == nums[i - 1])) {
        continue;
      }
      j = i + 1;
      for (j = i + 1; j < size - 2; ++j) {
        if ((j > i + 1) && (nums[j] == nums[j - 1])) {
          continue;
        }
        k = j + 1;
        l = size - 1;
        while (k < l) {
          // int64_t sum = nums[i] + nums[j] + nums[k] + nums[l];
          // 注意越界问题
          int64_t diff = int64_t(nums[i] - target) + int64_t(nums[j]) +
                         int64_t(nums[k]) + int64_t(nums[l]);
          if (diff == 0) {
            vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
            res.push_back(tmp);
            ++k;
            --l;
            while (k < l && nums[k] == nums[k - 1]) {
              ++k;
            }
            while (k < l && nums[l] == nums[l + 1]) {
              --l;
            }
          }
          if (diff > 0) {
            --l;
            while (k < l && nums[l] == nums[l + 1]) {
              --l;
            }
          }
          if (diff < 0) {
            ++k;
            while (k < l && nums[k] == nums[k - 1]) {
              ++k;
            }
          }
        }
      }
    }
    return res;
  }
};