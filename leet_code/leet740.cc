#include "common_def.h"
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
/*
* 逐步复杂的动态规划
* 需要做一次映射，才能转化为动归问题
* 这题一定要做，主要是各种容器的使用和分析!!!!
*/
class Solution {
  std::unordered_map<int, int> earn_;
  std::unordered_map<int, int> counts_;
  std::vector<int> value_set;
  int Earn(int index){
    auto it = earn_.find(index);
    // return 最接近的
    if(it == earn_.end()){
      // 找到比index 小的 第一个数
      // 报错, 关联容器的取值是一个pair，不能被greaer 比较
      // 感觉这个复杂的逻辑还不如数组解法
      auto itv = std::lower_bound(value_set.begin(), value_set.end(),index, std::greater<int>());
      // 实在是找不到
      if(itv == value_set.end()) {
        return 0;
      }
      it = earn_.find(*(itv));
    }
    return it->second;
  }
public:
    int deleteAndEarn(vector<int>& nums) {
      
      // std::unordered_set<int> value_set;
      for(int idx=0;idx<nums.size(); ++idx){
        auto it = counts_.find(nums[idx]);
        if(it != counts_.end()){
          ++it->second;
        } else {
          counts_[nums[idx]] = 1;
        }
      }
      value_set.reserve(counts_.size());
      for(auto iter = counts_.begin(); iter != counts_.end();++iter){
        value_set.push_back(iter->first);
      }
      std::sort(value_set.begin(), value_set.end(), std::greater<int>());
      // 初始化前两个值
     // int max_v = *std::max_element(nums.begin(), nums.end());
      int max_v = 0;
      for(auto it = value_set.rbegin(); it != value_set.rend(); ++it){
        int vidx = (*it);
        int earn = std::max((Earn(vidx-2) + vidx * counts_[vidx]), Earn(vidx - 1));
        earn_[vidx] = earn;
        max_v = vidx;
      }
      return earn_[max_v];
    }
};

int main(){
 std::vector<int> v = {1,1,1,2,4,5,5,5,6};
  Solution().deleteAndEarn(v);
  std::vector<int> v1 = {1,2,4,5,6};
  std::sort(v1.begin(), v1.end(), std::greater<int>());
  auto it = std::lower_bound(v1.begin(), v1.end(), 3, std::greater<int>());
  if(it == v1.end()){
    printf("Failed!\n");
  } else {
    printf("Ok!\n");
  }
  return 0;
}