#include "common_def.h"
#include <list>
// dfs 有顺序有关和顺序无关的问题, 需要复习
class Solution {
public:
    // 返回所有可能子树
    // 注意递归退回条件，以及临界情况，比如只有2个节点
    std::list<TreeNode*> GenTree(int s, int e){
      // 为什么不是=e呢?
      if(s > e){
        return {nullptr};
      }
      std::list<TreeNode*> tr;
      for(int i =s;i<=e;++i){
        // 注意, i 已被root 使用
        std::list<TreeNode*> left = GenTree(s, i-1);
        std::list<TreeNode*> right = GenTree(i+1, e);
        for(auto pleft: left){
          for(auto pright: right){
            // tree node ...
            TreeNode* root = new TreeNode(i);
            // left 相同，每个不同的right 子树都是不同的树
            root->left = pleft;
            root->right = pright;
            tr.push_back(root);
          }
        }
      }
      return tr;
    }

    vector<TreeNode*> generateTrees(int n) {
      if(!n){
        return {};
      }
      auto res = GenTree(1,n);
      std::vector<TreeNode*> res_vec(res.size());
      // std::copy 不会帮目标容器申请空间，所以要提前预备
      std::copy(res.begin(), res.end(), res_vec.begin());
      return res_vec;
    }
};