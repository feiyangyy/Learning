class Solution {
public:
    void dfs(int begin, int n, int k, vector<int>& path, vector<vector<int>>& res) {
        if(k==0){
            // path.push_back(begin); //?
            res.push_back(path);
            return;
        }
        for(int idx = begin; idx <= n;++idx){
            path.push_back(idx);
            dfs(idx + 1, n, k - 1, path, res);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>  res;
        vector<int> path;
        dfs(1, n, k, path, res);
        return res;
    }
};