#include "common_def.h"
#include <limits>
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size()));
        for(int i = 0;i<w;++i){
          dp[0][i] = matrix[0][i];
        }
        for(int i =1;i<h;++i){
          for(int j = 0;j<w;++j){
            int value = matrix[i][j];
            int sum = value + dp[i-1][j];
            if(j-1 >=0){
              sum = std::min(value + dp[i-1][j-1], sum);
            }
            if(j+1 < w){
              sum = std::min(value + dp[i-1][j+1], sum);
            }
            dp[i][j] = sum;
          }
        }
      int res = dp[h-1][0];
      for(int i = 1; i < w; ++i){
        res = std::min(dp[h-1][i], res);
      }
      return res;
    }
};