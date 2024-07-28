class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int sz = nums.size();
        int start = 0;
        int end = sz - 1;
        while (start <= end){
            int mid = (start + end) / 2;
            if(target == nums[mid]){
                return true;
            }
            // 前半部分有序
            if(nums[start] < nums[mid]) {
                if(target >= nums[start] && target <= nums[mid]){
                    end = mid-1;
                    continue;
                } else {
                    // 在非有序部分继续
                    start = mid + 1;
                }
            } else if(nums[start] > nums[mid]) {
                // 在有序区间查找
                if(target <= nums[end] && target > nums[mid]){
                    start = mid + 1;
                } else {
                    end = mid-1;
                }
            } else {
                // 一直找到有序区间为止
                start++;
                continue;
            }
        }
        return false;
    }
};