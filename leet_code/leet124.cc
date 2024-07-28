#include "common_def.h"
#include <algorithm>
#include <numeric>
#include <limits>
class Solution {
public:
    int max_val = std::numeric_limits<int>::min();

    int GetChildTreeSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left_sum = std::max(0, GetChildTreeSum(root->left));
        int right_sum = std::max(0, GetChildTreeSum(root->right));
        // current tree sum, if it's not the max value, we drop it.
        int cur_sum = root->val + left_sum + right_sum;
        max_val = std::max(cur_sum, max_val);
        int ret_val = std::max(left_sum, right_sum);
        // returns the child-tree sum value, the previous call will calculate the max-sum value.
        return ret_val + root->val;
    }

    int maxPathSum(TreeNode* root) {
        GetChildTreeSum(root);
        return max_val;
    }
};

