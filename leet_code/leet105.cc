/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        // 第一个节点是根节点
        if(ps > pe || is > ie) {
            return nullptr;
        }
        // 生成根节点
        TreeNode* root = new TreeNode(preorder[ps]);
        // 找节点
       // for(int idx = )
       int idx = is;
       // 找到左子树
       for(;idx <= ie; ++idx) {
           if(inorder[idx] == preorder[ps]){
               break;
           }
       }
       // root->left = buildTree(preorder, )
       int cnt = idx - is; // 左子树数量
       // 对于计数问题还是不是很熟练
       root->left = buildTree(preorder, ps + 1, ps + cnt, inorder, is, idx -1);
       root->right = buildTree(preorder, ps + cnt + 1, pe, inorder, idx + 1, ie);
       return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};