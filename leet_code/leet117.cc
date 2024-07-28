#include "common_def.h"
#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> q;
        if (!root) {
            return root;
        }
        q.push(root);
        int level_cnt;
        while(!q.empty()) {
            // 如果只是print，这样就可以了，但是还需要连接
            // 当前层的节点数量
            // 要有自信，不要自我怀疑，否则这个状态去面试一定会失败！
            level_cnt = q.size();
            Node pre;
            Node* ppre = &pre;
            for(int i = 0; i < level_cnt;++i) {
                Node* n = q.front();
                q.pop();
                // 此时都放到尾部
                // 注意push进去的都是下一层的节点
                ppre->next = n;
                ppre = ppre->next;
                if(n->left) {
                    q.push(n->left);
                }
                if(n->right) {
                    q.push(n->right);
                }
            }
        }
        return root;
    }
};