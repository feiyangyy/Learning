#include "common_def.h"

class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        int count = 1;
        int res = nums[0];
        for(int idx = 1; idx<nums.size(); ++idx){
            if(res == nums[idx]) {
                ++count;
            } else {
                --count;
                if(!count) {
                    count = 1;
                    res = nums[idx];
                }
            }
        }
        return res;
    }
};

int main(){
    std::vector<int> tc = {8, 8, 7, 7, 7};
    printf("%d\n", Solution::majorityElement(tc));
    return 0;
}