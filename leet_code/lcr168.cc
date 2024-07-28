#include "common_def.h"
class Solution {
public:
    static int nthUglyNumber(int n) {
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        int idx = 0;
        int a,b,c;
        a = b = c = idx;
        while(idx <n-1){
            int tmp_2 = dp[a] * 2;
            int tmp_3 =dp[b] * 3;
            int tmp_5 = dp[c] * 5;
            int min = std::min(tmp_2, tmp_3);
            min = std::min(min, tmp_5);
            dp[idx+1] = min;
            if(min == tmp_2) {
                ++a;
            } 
            if(min == tmp_3) {
                ++b;
            } 
            // 对于重复元素，都需要移动
            if(min == tmp_5) {
                ++c;
            }
            ++idx;
        }
        return dp[n-1];
    }
};

int main(){
    Solution::nthUglyNumber(10);
    return 0;
}