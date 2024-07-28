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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> t;
        
        t.push(root);
        vector<vector<int>> r;
        if(!root) {
            return r;
        }
        while(!t.empty()){
            std::vector<int> tmp;
            // tmp.push_back(t.pop());
            // 此处要加遍历
            int sz = t.size();
            // 将本层节点打印出
            for(int idx =0;idx<sz;++idx){
                TreeNode* n_1=  t.front();
                tmp.push_back(t.front()->val);
                t.pop();
                if(n_1->left){
                    t.push(n_1->left);
                }
                if( n_1->right){
                    t.push(n_1->right);
                }
            }
            r.push_back(tmp);
        }
        return r;
    }
};