#include "common_def.h"
#include <stack>
// 得用中序遍历
// 先用递归解法，DFS本身也是递归
class Solution
{
public:
  bool PathSum(TreeNode *root, int val, int target)
  {
    val += root->val;
    if (val == target && !root->left && !root->right)
    {
      return true;
    }
    return PathSum(root->left, val, target) | PathSum(root->right, val, target);
  }

  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (!root)
    {
      return false;
    }
    return PathSum(root, 0, targetSum);
#if 0
    std::stack<TreeNode *> stk;
    stk.push(root);
    int val = 0;
    // 想想看前序遍历怎么写的来着？
    while (!stk.empty())
    {
      TreeNode *node = stk.top();
      stk.pop();
      val += node->val;
      if (val == 0 && !node->left && !node->right)
      {
        return true;
      }
      else if (val > 0)
      {
        // 把非叶子节点的左右子树push进去
        if (node->right)
        {
          stk.push(node->right);
        }
        if (node->left)
        {
          stk.push(node->left);
        }
      }
      else // 非叶子节点 或者 值 小于 0
      {
        // 加回被减去的值
        // 其左右子树不处理
        val += node->val;
      }
    }
    return false;
#endif
  }
  // BFS solve ...
};