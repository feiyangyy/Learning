#include "common_def.h"

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || (root == p) || (root == q)) {
      return root;
    }
    // 再左子树中搜索一个节点，搜到就返回
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    // 在右子树中搜索一个节点，搜到就返回
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    // 右为空，一定在左
    if (!right) {
      return left;
    }
    // 左为空，一定在右
    if (!left) {
      return right;
    }
    return root;
  }
};