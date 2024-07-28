#include "common_def.h"
#include <stdio.h>
class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> k_length;
        int max_len = 0;
        for(auto num: nums){
            int left_len = 0, right_len = 0;
            auto it = k_length.find(num);
            if(it != k_length.end()){
                continue;
            }
            it = k_length.find(num-1);
            if(it != k_length.end()){
                left_len=it->second;
            }
            it = k_length.find(num + 1);
            if(it != k_length.end()){
                right_len =it->second;
            }
            int cur_len = 1 + left_len + right_len;
            max_len = std::max(cur_len, max_len);
            if(max_len == 7) {
                printf("hello!");
            }
            k_length[num-left_len] = cur_len;
            k_length[num+right_len] = cur_len;
        }
        return max_len;
    }
};

int main(){
    vector<int> r = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    Solution::longestConsecutive(r);
    return 0;
}