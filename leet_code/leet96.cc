#include "common_def.h"
/*
  这是一个数学问题，设f(i) 为以i为根节点的BST的数量，则当总数字为n时，i 左子树节点数量为i-1(比i小的数), 右子数节点数量为;
  k = n-(i-1) - 1 = n-i;
  设G(n) 为n个节点时，BST的总数，则
  G(n)=\sum_{i=1}^{n}f(i) = \sum_{i=1}^{n}G(i-1)\mulG(n-i)
  其中G(0) = 1 G(1)=1
*/
class Solution {
public:
    int numTrees(int n) {
      std::vector<int> G(n+1,0);
      G[0] = 1;
      G[1] = 1;
      for(int idx = 2; idx<=n; ++idx){
        // 此处会有一些重复计算
        // 以j为根节点
        for(int j = 1; j<=idx; ++j) {
          G[idx] += (G[j-1]*G[idx-j]);
        }
      }
      return G[n];
    }
};