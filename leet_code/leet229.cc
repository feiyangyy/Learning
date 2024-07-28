#include "common_def.h"
/**
 *  加精: 一维动态规划中的二次遍历问题
 * i from low to high
 * j from i to zero. 递归得出前i个结果，再从i往后推
 * 复习 ！！！
 * **/
class Solution {
public:
    int numSquares(int n) {
     std::vector<int> vec(n + 1,0);
     for(int idx =0;idx<n+1;++idx){
      vec[idx] = idx;
     }
     for(int i =1;i<n+1;++i){
      for(int j = 1; i - j*j >=  0; ++j){
        vec[i] = std::min(vec[i], vec[i - j*j]+ 1);
      }
     }
     return vec[n];
    }
};