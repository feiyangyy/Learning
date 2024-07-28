#include <common_def.h>
class Solution {
public:
  int bsearch(vector<int> &nums, int l, int r, int tgt) {
    if (l > r) {
      return -1;
    }
    int mid = (l + r) / 2;
    if (nums[mid] == tgt) {
      return mid;
    }
    // 0到nums有序
    if (nums[mid] >= nums[l]) {
      if (tgt >= nums[l] && tgt < nums[mid]) {
        r = mid - 1; // mid已经判定过了
      } else {
        // 数据在非有序区间内
        l = mid + 1;
      }
    } else {
      // 后半段区间

      if (tgt > nums[mid] && tgt <= nums[r]) {
        // 调整查找区间
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return bsearch(nums, l, r, tgt);
  }

  int search(vector<int> &nums, int target) {
    return bsearch(nums, 0, nums.size() - 1, target);
  }
};