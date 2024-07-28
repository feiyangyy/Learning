#include <vector>
#include "unordered_map"
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include "stdio.h"
using namespace std;
class Solution {
public:
    // 深度有限搜索
#if 1
    void dfs1(int begin, int k, vector<int>& path, vector<vector<int>>& res,vector<int>& nums) {
        res.push_back(path);
        if(k==0){
            return;
        }
        for(int idx = begin; idx < nums.size();++idx){
            path.push_back(nums[idx]);
            dfs1(idx+1, k - 1, path, res, nums);
            path.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>  res;
        // res.push_back(vector<int>());
        vector<int> path;
        dfs1(0, nums.size(), path, res, nums);
        return res;
    }

#endif
    // 集合方法
    // 体会bitmap 处理含量数据时的优势
    static  vector<vector<int> > subsets(vector<int>& nums) {
        std::unordered_map<int, int > hash;
        // 定义全集
        int64_t bit_map = (1 << nums.size()) - 1;
        int64_t sub = bit_map;
        vector<vector<int> > res;
        // res.push_back(std::vector<int>());
        while (1) {
            sub = sub & bit_map;
            // 是子集
            if(((sub & bit_map) == sub) && ((sub | bit_map) == bit_map)) {
                std::vector<int> temp;
                
                int idx = 0;
                // 从第0位开始
                while((sub >> idx) > 0){
                    if((sub >> idx) & 0x1) {
                        temp.push_back(nums[idx]);
                    }
                    ++idx;
                }
                res.push_back(temp);
            }
            sub = sub - 1;
            // 成为负数
            if((sub & bit_map) == bit_map) {
                break;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums={1,2,3};
    auto r = Solution::subsets(nums);
    return 0;
}