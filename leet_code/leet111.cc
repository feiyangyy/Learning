#include <algorithm>
#include <queue>
#include "common_def.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        std::queue<TreeNode*> q;
        if(!root) {
            return 0;
        }
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int idx = 0;
            int sz = q.size();
            ++level;
            while(idx<sz){
                TreeNode* front = q.front();
                q.pop();
                if(!front){
                    return 0;
                }
                if(!front->left && !front->right) {
                    return level;
                }
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
                ++idx;
            }
        }
        return level;
    }

    int minDepth2(TreeNode* root) {

    }
};