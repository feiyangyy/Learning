
#include "common_def.h"

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int sz = nums.size();
    for (int i = sz - 1; i > 0; --i) {
      for (int k = i - 1; k >= 0; --k) {
        if (nums[i] > nums[k]) {
          // std::swap(nums[i], nums[k]);
          int min_pos = k + 1;
          for (int j = k + 1; j < sz - 1; ++j) {
          }
          std::sort(nums.begin() + k + 1, nums.end());
          return;
        }
      }
    }
    std::sort(nums.begin(), nums.end());
  }
};