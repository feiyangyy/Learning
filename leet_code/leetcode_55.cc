bool canJump(vector<int>& nums) {
    int max_pos = 0;
    int end = 0;
    if(nums.size() == 1) {
        return true;
    }
    for(int idx = 0; idx<nums.size(); ++idx){
        if(idx == max_pos && nums[idx] == 0){
            return false;
        }
        max_pos = std::max(max_pos, nums[idx] + idx);
        if(max_pos >= nums.size() -1) {
            return true;
        }
        if(idx == end){
            end = max_pos;
            // ans++;
        }
    }
    return true;

}