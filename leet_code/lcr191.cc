#include "common_def.h"
class Solution {
public:
    // 首先不能devide，因为 aa中可能有0
    vector<int> statisticalResult(vector<int>& arrayA) {
      std::vector<int> res;
      int n = arrayA.size();
      if(!n){
        return {};
      }
      std::vector<int> C(n, 1), D(n, 1);
      std::vector<int>& A = arrayA;
      for(int idx = 1; idx < A.size(); ++idx){
        C[idx] = C[idx-1] * A[idx-1];
      }
      for(int idx = A.size() -2; idx>=0; --idx) {
        D[idx] = D[idx+1] *A[idx +1]; 
      }
      std::vector<int> B(n,1);
      for(int idx = 0;idx< A.size(); ++idx){
        B[idx] = C[idx] * D[idx];
      }
      return B;
    }
};