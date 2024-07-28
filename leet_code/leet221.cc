#include  "common_def.h"
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       int w,h;
      w = matrix[0].size();
      h = matrix.size();
      std::vector<std::vector<int>> dp(h, std::vector<int>(w, 0));
      int  max = 0;
      for(auto&vec:matrix){
        for(auto& v:vec){
          v -= 0x30;
        }
      }
      for(int i =0;i<w;++i){
        dp[0][i] = matrix[0][i];
        if(dp[0][i]) {
          max =1;
        }
      }
      for(int i = 0; i<h;++i){
        dp[i][0] = matrix[i][0];
        if(dp[i][0]) {
          max = 1;
        }
      }
      for(int i = 1; i<h;++i){
        for(int j = 1; j <w;++j){
          if(!matrix[i][j]){
            dp[i][j] = 0;
            continue;
          }
          dp[i][j] = 1;
          if (!max) {
            max = 1;
          }
          int len = dp[i-1][j-1];
          if(!len) {
            continue;
          }
          for(int k = 1; k <= len && (i-k + 1) &&(j-k + 1); ++k){
            if(matrix[i-k][j] && matrix[i][j-k]){
              dp[i][j] += 1;
            } else {
              break;
            }
            max = std::max(max, dp[i][j]);
            if(max == 3){
              printf("i %d, j %d", i, j);
            }
          }
        }
      }
      return max*max;
    }
};

int main(){
  // std::vector<vector<char>> ma = { {1 , 0 , 1 , 0 , 0 },{ 1 , 0 , 1 , 1 , 1 },{ 1 , 1 , 1 , 1 , 1 },{ 1 , 0 , 0 , 1 , 0 }};
  std::vector<vector<char>> ma = {{0,1}, {1, 0}};
  int ret = Solution().maximalSquare(ma);
  printf("ret:%d\n",ret);
  return 0;
}