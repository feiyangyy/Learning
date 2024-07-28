#include "common_def.h"
using std::string;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      std::vector<bool> dp(s.size() + 1, false);
      dp[0] = true;
      for(int i=0;i<s.size(); ++i){
        for(int j = i+1; j<s.size()+1; ++j){
          if(dp[i]){
            int len = j-1;
            std::string sub_str(len, 0);
            std::copy(s.begin()+i+1, s.begin()+j+1, sub_str);
            for(const auto& w:wordDict){
              if(w == sub_str){
                dp[j] = true;
                break;
              }
            }
          }
        }
      }
    }
};