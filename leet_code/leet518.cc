#include "common_def.h"
#include <set>
/**
 * 可以用dfs解决, 枚举所有可能结果，dp 关键在于如何规划 转移
 * 背包问题分析
 * https://leetcode.cn/problems/coin-change-ii/solutions/1412584/by-flix-e1vv/?envType=study-plan-v2&envId=dynamic-programming
 * 没有完成！
 * 这个可以类比完全背包问题，但是与背包问题不同的是，这个不是求最大价值，求得是方案数，每一种方案，不代表其背包能达到最大值
 * 把amount看做背包，把coins当做item，定义递推问题为: 前k个能够组成amount的组合数
 * 对于第k个coin，其递推公式是:dp[k] = dp[k-1][J] + dp[k][J-coins[k]] 注意，第二项dp[k][J-coins[k]]已经是充分考虑是否选择第k个coin
 * 但是怎么和背包问题联系起来呢？又是一个割裂的问题
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
      std::vector<int> dp(amount+1, 0);
      // 非常重要的初始化值!
      // dp[0] 表示的值，实际上是 dp[j] = dp[j] + dp[j-c]，c = j 时的值，即用c=j 构造j 一共1种方法
      dp[0] = 1;
      #if 0
      if(!amount % coins[0]) {
        dp[0] = 1;
      }
      #else 
      for(int idx = coins[0]; idx<= amount; ++idx){
        if(!(idx % coins[0])) {
          dp[idx] = 1;
        }
      }
      #endif
      int  sz = coins.size();
      for(int idx = 1; idx < sz;++idx){
        int c = coins[idx];
        // 对于放不下c的数值统计没有意义
        for(int j = c; j<= amount; ++j){
          dp[j] = dp[j] + dp[j-c]; // 此处j-c < j， 而循环是从小王大推的，因此， dp[j-c] = dp[idx][j-c]
        }
      }
      return dp.back();
    }
};