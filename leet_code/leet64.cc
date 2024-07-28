#include "common_def.h"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        auto dp = grid;
        for(int idx = 1;idx<w;++idx){
          dp[0][idx] += dp[0][idx - 1];
        }
       for(int idx =1; idx<h;++idx){
        dp[idx][0] += dp[idx-1][0];
       }
      for(int i = 1; i<h; ++i){
        for(int j = 1; j < w; ++j) {
          dp[i][j] += std::min(dp[i-1][j], dp[i][j-1]);
        }
      }
      return dp[h-1][w-1];
    }
};