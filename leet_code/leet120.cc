class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        std::vector<std::vector<int>> dp;
        dp.resize(triangle.size());
        int idx = 1;
        std::for_each(dp.begin(), dp.end(), [&idx](std::vector<int>& vec){
            vec.resize(idx++);
            std::fill(vec.begin(),vec.end(), 0);
        });
        // for(int)
        int m = triangle.size();
       // int n =
        // std::transform(<#InputIterator first#>, <#InputIterator last#>, <#OutputIterator result#>, <#UnaryOperation op#>)
        // std::copy(triangle[m-1].begin(), triangle[m-1].end(), dp[m-1].begin());
        for(int i = m-1; i>=0; --i){
            for(int j = 0; j<=i; ++j){
                if(i == m-1){
                    dp[i][j] = triangle[i][j];
                } else {
                    dp[i][j] = triangle[i][j] + std::min(dp[i+1][j], dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};