#include "common_def.h"
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
class Solution {
public:
    void dfs(TreeNode* node, int target, std::vector<int>& path, std::vector<std::vector<int>>& res) {
        // only root == nullptr
        if(!node) {
            return;
        }
        target -= node->val;
        path.push_back(node->val);
        if( !node->left && !node->right) {
           if(target == 0) {
            res.push_back(path);
           }
           return;
        }
        // get left
        if(node->left) {
            dfs(node->left, target, path, res);
            path.pop_back();
        }
        if(node->right) {
            dfs(node->right, target, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }
};
};