#include "common_def.h"
#include <limits>
#include <numeric>
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    int i, j, k;
    i = 0;
    int min_sum = 1000000;
    for (i = 0; i < size - 2; ++i) {
      j = i + 1;
      k = size - 1;
      if (i && nums[i] == nums[i - 1]) {
        continue;
      }
      while (j < k) {
        int s = nums[i] + nums[j] + nums[k];
        if (s == target) {
          return target;
        }
        int diff = s - target;
        if (std::abs(diff) < std::abs(target - min_sum)) {
          min_sum = s;
        }
        // s
        if (diff > 0) {
          k--;
          while (j < k && nums[k] == nums[k + 1]) {
            --k;
          }
        }
        if (diff < 0) {
          ++j;
          while (j < k && nums[j] == nums[j - 1]) {
            ++j;
          }
        }
      }
    }
    return min_sum;
  }
};