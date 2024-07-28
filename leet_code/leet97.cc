#include "common_def.h"
#include <string>
#include <vector>
class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
      int i =0,j=0;
      int all_empty = 0x0;
      if(s1.empty()){
        all_empty |= 0x1;
      }
      if(s2.empty()){
        all_empty |= 0x2;
      }
      if(s3.empty()){
        all_empty |=0x4;
      }
      if(all_empty == 0x7){
        return true;
      }
      int l1, l2, l3;
      l1 = s1.size();
      l2 = s2.size();
      l3 = s3.size();
      if(l3 != l1 + l2){
        return false;
      }
      if(!l1) {
        return s2 == s3;
      } else if(!l2) {
        return s1 == s3;
      }
      // 初始化第一行和第一列
      std::vector<std::vector<bool>> dp(l1+1, std::vector<bool>(l2+1, false));
      dp[0][0] = true;
      // first row
      for(int idx = 0;idx<s2.size(); ++idx){
        dp[0][idx+1] = dp[0][idx] && (s2[idx] == s3[idx]);
      }
      // first col 
      for(int idx = 0; idx < s1.size(); ++idx){
        dp[idx+1][0] = dp[idx][0] && (s1[idx] == s3[idx]);
      }
      // first row and first col is initialized...
      for(i = 1; i<l1+1;++i){
        for(j = 1;j<l2+1; ++j){
          char cmp = s3[i+j - 1];
          dp[i][j] = (dp[i-1][j] && s1[i-1] == cmp) || (dp[i][j-1] && s2[j-1] == cmp);
        }
      }
      return dp[l1][l2];
    }
};

int main(){

  Solution().isInterleave("db","b","cbb");
  return 0;
}