#include "common_def.h"
// note:基本的二维动态规划， 但是可以做一些优化
class Solution {

public:
    int jewelleryValue(vector<vector<int>>& frame) {
        std::vector<std::vector<int>> dp;
        int m = frame.size();
        int n = frame.front().size();
        dp.resize(m, std::vector<int>(n, 0));
        dp[0][0] = frame[0][0];
        for(int i =0 ;i <m; ++i){
            for(int j = 0;j < n; ++j){
                int pad = 0;
                if(i==0 && j == 0){
                    continue;
                }
                if(i ==0){
                    pad = dp[i][j-1];
                } else if (j == 0) {
                    pad = dp[i-1][j];
                } else {
                    pad = std::max(dp[i-1][j], dp[i][j-1]);
                }
                dp[i][j] = frame[i][j] + pad;
            }
        }
        return dp[m-1][n-1];
    }
};