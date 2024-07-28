#include "common_def.h"
class Solution {
public:
    vector<vector<int>> fileCombination(int target) {
        int end = (target+1) /2;
        int s = 1, e = 2;
        int sum = 3;
        std::vector<std::vector<int>> res;
        // 注意结尾判定条件
        while(e <= end){

            if(sum == target){
                std::vector<int> tmp(e - s +1);
                int idx = s;
                std::generate(tmp.begin(), tmp.end(), [&idx](){
                    return idx++;
                });
                res.push_back(tmp);
                sum -= s;
                ++s;
                continue;
            } else if(sum > target) {
                sum -= s;
                ++s;
            } else if (sum < target) {
                ++e;
                sum += e;
            }
        }
        return res;
    }
};