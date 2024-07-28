#include "common_def.h"
#include <limits>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      // 此处我们初值构造错了，初值应当是invalid, 一般求最大的问题，应当设置为0，求最小的问题应当设置为int_max
      std::vector<uint32_t> dp(amount + 1, std::numeric_limits<int>::max());
      // 初始化, dp[0] 当做特殊的初值
      dp[0] = 0;      
      int c = coins[0];
      // 构造初值
      for(int i = c; i<=amount;++i){
        if(!(i % c)) {
          dp[i] = i / c;
        }
      }
      int sz = coins.size();
      for(int i = 1; i < sz; ++ i){
        c = coins[i];
        for(int j = c; j <= amount; ++j) {
          // 注意，如果跑到了int_max+1, 就G了，所以上面要生命成uint32_t
          dp[j] = std::min(dp[j], (dp[j-c] + 1));
        }
      }
      return dp.back();
    }
};