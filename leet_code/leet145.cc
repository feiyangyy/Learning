#include "common_def.h"
#include <stack>

// 后序
// 左右根
class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    std::stack<TreeNode *> stk;
    if (!root)
    {
      return {};
    }
    stk.push(root);
    vector<int> results;
    while (!stk.empty())
    {
      TreeNode *n = stk.top();
      if (n)
      {
        stk.pop();
        stk.push(n);
        // 增加中止标记
        stk.push(nullptr);
        if (n->right)
        {
          stk.push(n->right);
        }
        if (n->left)
        {
          stk.push(n->left);
        }
      }
      else
      {
        stk.pop();
        n = stk.top();
        stk.pop();
        results.push_back(n->val);
      }
    }
    return results;
  }
};