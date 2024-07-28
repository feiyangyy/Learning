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
    TreeNode* buildTree(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        // 返回条件
        if(is > ie || ps > pe) {
            return nullptr;
        }
        int root = postorder[pe];
        int idx = is;
        // 找到根节点位置
        for(; idx<=ie; ++idx) {
            if(inorder[idx] == root) {
                break;
            }
        }
        int left_node_count = idx - is; // 不包含idx节点
        int right_node_count = ie - idx; // 不包含idx节点
        TreeNode* r = new TreeNode(root);
        r->left = buildTree(inorder, is, is + left_node_count - 1, postorder, ps, ps + left_node_count - 1);
        r->right = buildTree(inorder, idx + 1, ie, postorder, ps + left_node_count, pe - 1);
        return r;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    } 
};