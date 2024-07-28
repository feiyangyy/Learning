#include "common_def.h"
class Solution {
public:
    int fib(int n) {
        std::vector<int> res(n+1, 0);
        res[1] = 1;
        for(int idx = 2; idx <= n; ++idx) {
          res[idx] = res[idx - 2] + res[idx -1];
        }
        return res[n];
    }
};