#include "common_def.h"

class Solution {
public:
    int tribonacci(int n) {
      if(!n){
        return 0;
      }
      std::vector<int> res(n+10);
      res[0] = 0;
      res[1] = 1;
      res[2] = 1;
      for(int idx = 3; idx<=n; ++idx){
        res[idx] = res[idx-1] + res[idx-2] + res[idx-3];
      }
      return res[n];
    }
};