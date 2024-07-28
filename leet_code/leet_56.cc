class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        int j = 0;
        for(int idx = 1; idx < intervals.size(); ++idx){
            if(res[j][1] >= intervals[idx][0]) {
                res[j][1] = std::max(intervals[idx][1], res[j][1]);
            } else {
                res.push_back(intervals[idx]);
                ++j;
            }
        }
        return res;
    }
};