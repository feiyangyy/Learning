class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> res = intervals;
        res.push_back(newInterval);
        // 字典序
        std::sort(res.begin(), res.end());
        intervals.clear();
        intervals.push_back(res[0]);
        for(int idx = 1; idx< res.size(); ++idx){
            auto last = intervals.end() - 1;
            std::vector<int>& last_one = *last;
            if(last_one[1] >= res[idx][1]) {
                continue;
            } else if(last_one[1] < res[idx][0]) {
                intervals.push_back(res[idx]);
                continue;
            } else if(last_one[1] >= res[idx][0] && last_one[1] <= res[idx][1]){
                last_one[1] = res[idx][1];
            }
        }
        return intervals;
    }
};