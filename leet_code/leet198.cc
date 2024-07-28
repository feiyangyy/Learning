#include "common_def.h"
/*(
  !!!! 加星 动态规划入门题，该问题不像斐波那契数列那么直观
)*/
class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size() == 1){
        return nums[0];
      }
      std::vector<int> res(nums.size(), 0);
      res[0] = nums[0];
      res[1] = nums[1] > nums[0]? nums[1]:nums[0];
      for(int idx=2;idx<nums.size();++idx){
        res[idx] = std::max(res[idx-2] + nums[idx], res[idx -1]);
      }
      return res.back();
    }
};