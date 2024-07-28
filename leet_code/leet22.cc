class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        dp[1] = {"()"};
        // dp.push_back({""}, {"()"});
        for(int i = 2; i <=n; ++i){
            for(int j = 0; j < i;++j){
                vector<string> dp_j = dp[j];
                vector<string> dp_i = dp[i-j-1];
                // 注意每个循环I都不变
                for(const auto& p:dp_i){
                    for(const auto& q:dp_j){
                        dp[i].push_back("(" + p + ")" + q);
                    }
                }
            }
        }
        return dp[n];
    }
};