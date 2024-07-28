class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        std::stack<int> stk;
        int i = 0;
        // stk.push(putIn[i++]);
        for(int idx = 0; idx<takeOut.size(); ++idx){
            // 如果顶部不是要弹出的数据，则从输入序列中取，如果取到末尾，则G
            while(stk.size() == 0 || stk.top() != takeOut[idx]) {
                // 注意位置
                if(i>=putIn.size()) {
                    return false;
                }
                stk.push(putIn[i++]);

            }
            stk.pop();
            // 开始下一轮
            continue;
        }
         return true;
    }
};