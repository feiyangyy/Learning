#include "common_def.h"
#include <queue>
#include <stack>
// 中序
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    std::stack<TreeNode *> stk;
    TreeNode *tr;
    if (!root)
    {
      return {};
    }
    tr = root;
    std::vector<int> vals;
    // 如果tr == null, 说明是叶子节点，
    // 则取叶子节点的父节点
    while (tr || !stk.empty())
    {
      // 直到最左侧叶子节点
      while (tr)
      {
        stk.push(tr);
        tr = tr->left;
      }
      // 退出当前节点
      tr = stk.top();
      stk.pop();
      vals.push_back(tr->val);
      // 处理右子树
      tr = tr->right;
    }
    return vals;
  }
};