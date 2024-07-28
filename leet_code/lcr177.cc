#include "common_def.h"

class Solution {
public:
    // 所以这个跟用hash有什么区别?
    // 除非限制不让用额外的空间
    vector<int> sockCollocation(vector<int>& sockets) {
        int num = sockets[0];
        int res_a = 0, res_b = 0;
        for(int idx = 1;idx< sockets.size(); ++idx){
            num ^= sockets[idx];
        }
        int pos = 0;
        while(!(num & (0x1 << pos))) {
            pos++;
        }
        int n = 0x1 << pos;
        for(int idx = 0; idx<sockets.size(); ++idx) {
            if(sockets[idx] & n){
                res_a ^= sockets[idx];
            } else {
                res_b ^= sockets[idx];
            }
        }
        std::vector<int> res;
        res.push_back(res_a);
        res.push_back(res_b);
        return res;
    }
};