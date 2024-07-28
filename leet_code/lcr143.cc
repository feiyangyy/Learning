/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSame(TreeNode* a, TreeNode* b){
        // b到达叶子节点，则已经匹配完毕了
        if(!b) {
            return true;
        }
        if(!a){
            return false;
        }
        if(a->val != b->val){
            return false;
        }
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) {
            return false;
        }
        // 前序遍历
        // 这个判断是多余的，为什么?
        // if(A->val != B->val) {
            return isSame(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
        // }
        // return isSame(A, B);
        // return isSubStructure(A->left, B->left) && isSubStructure(A->right, B->right);
    }
};