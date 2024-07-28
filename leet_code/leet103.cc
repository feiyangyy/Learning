#include "common_def.h"
#include <vector>
#include <queue>
// 层级遍历应用
class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    std::queue<TreeNode *> que;
    que.push(root);
    bool rv = false;
    vector<vector<int>> res;
    while (!que.empty())
    {
      std::vector<int> vec;
      int cnt = que.size();
      while (cnt--)
      {
        TreeNode *top = que.front();
        vec.push_back(que.front()->val);
        que.pop();
        if (top->left)
        {
          que.push(top->left);
        }
        if (top->right)
        {
          que.push(top->right);
        }
      }
      if (rv)
      {
        std::reverse(vec.begin(), vec.end());
      }
      // rv = ~rv 有问题
      // 增加到note
      rv = !rv;
      res.push_back(vec);
    }
    return res;
  }
};