#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // std::stack<std::vector<int>> stk;
        std::queue<TreeNode*> nodes;
        nodes.push(root);

        // if nodes is empty, the tree is travelled.
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        while(!nodes.empty()) {
            std::vector<int> tmp;
            int sz = nodes.size();
            // idx = 0;
            // circle control variable!!!!
            while(sz--){
                TreeNode* top = nodes.front();
                if(!top) {
                    continue;
                }
                tmp.push_back(top->val);
                nodes.pop();
                if(top->left) {
                    nodes.push(top->left);
                }
                if(top->right){
                    nodes.push(top->right);
                }
                // ++idx;
            }
            // stk.push(tmp);
            res.push_back(tmp);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};