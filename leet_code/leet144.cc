#include "common_def.h"
#include <queue>
#include <stack>
// 前绪
// 根左右， 其中的左，是包含整个左子树的，同理，右，也是包含了整个右子树的
// 注意，这个不是层级便利
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
    TreeNode *tr = root;
    stk.push(root);
    std::vector<int> result;
    while (!stk.empty())
    {
      tr = stk.top();
      stk.pop();
      result.push_back(tr->val);
      // 后入stk的，一定会在后面的travel中得到先处理
      if (tr->right)
      {
        stk.push(tr->right);
      }
      if (tr->left)
      {
        stk.push(tr->left);
      }
    }
    return result;
  }
};