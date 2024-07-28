    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        
        bool found  = false;
        for(int i = m-1; i >=0; --i){
            if(obstacleGrid[i][n-1] || found) {
                found = true;
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }
        found = false;
        for(int i = n-1; i >=0; --i){
            if(obstacleGrid[m-1][i] || found){
                found = true;
                dp[0][i] = 0;
            } else {
                dp[0][i] = 1;
            }
        }
        for(int i = 0; i<m;++i){
            for(int j = 0; j <n; ++j){
                if(obstacleGrid[i][j]){
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }