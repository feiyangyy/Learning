#include "common_def.h"
#include <string>
// 自己想出来的第一个动态规划题目！！！，泪目
class Solution {
public:
    int crackNumber(int ciphertext) {
        std::string txt = std::to_string(ciphertext);
        std::vector<int> dp(txt.size() + 1, 0);
        dp[txt.size() -1] = 1;
        dp[txt.size()] = 1;
        int base = 0;
        for(int idx = txt.size() -2; idx>=0; --idx) {
            int n = txt.at(idx) - '0';
            int np1=  txt.at(idx+ 1) - '0';
            int num = n*10 + np1;
            base = 0;
            if(num >= 10 && num < 26){
                base = 1;
            }
            dp[idx] = dp[idx+1] + base * dp[idx + 2];
        }
        return dp[0];
    }
};