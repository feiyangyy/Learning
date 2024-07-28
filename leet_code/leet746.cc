#include "common_def.h"
/*
** 定义cost(x) = min[cost(x-2) + c[x-2], cost(x-1) + c(x-1)] 
*/
class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
      std::vector<int> pay(cost.size() + 1, 0);
      for(int idx = 2;idx<pay.size();++idx) {
        pay[idx] = std::min(pay[idx-1] + cost[idx-1], pay[idx-2] + cost[idx-2]);
      }
      return pay.back();
    }
};

int main(){
  // Solution().minCostClimbingStairs({10,15, 20});
  std::vector<int> v = {1,2,3};
  // greator => lhs > rhs, how ever, the parameter val is passed to compare a lhs!
  auto it = std::upper_bound(v.begin(), v.end(), 0, std::greater<int>());
  if(it == v.end()) {
    printf("Not found!\n");
  } else {
    printf("Found!\n");
  }
  return 0;
}