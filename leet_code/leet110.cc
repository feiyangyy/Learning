#include <algorithm>

struct TreeNode {

    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};


class Solution {
public:
    int GetDetph(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l_dep = GetDetph(root->left);
        int r_dep = GetDetph(root->right);
        // child tree is not balanced.
        if(l_dep < 0 || r_dep<0){
            return -1;
        }

        if (std::abs(l_dep - r_dep) > 1) {
            return -1;
        }
        // return current-tree depth.
        return std::max(l_dep, r_dep) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int r = GetDetph(root);
        return r>=0;
    }
};