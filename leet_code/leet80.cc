class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        int k = 2;
        for(int idx = 0; idx<nums.size(); ++idx){
            if(len < k || nums[len - k] != nums[idx]){
                nums[len] = nums[idx];
                ++len;
            }
        }
        return len;
    }
};