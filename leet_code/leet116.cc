// !!!!need debug!!!!
#include "common_def.h"
#include <algorithm>
#include <memory>

class Solution {
public:
    
    static void AddChild(Node* node, int l, int r) {
        node->left = new Node(l);
        node->right = new Node(r);
    }

    static std::unique_ptr<Node> MakeTree() {
        std::unique_ptr<Node> root = std::make_unique<Node>(0);
        AddChild(root.get(), 1, 2);
        #if 0
        AddChild(root->left, 3,4);
        AddChild(root->right, 5, 6);
        #endif
        return std::move(root);
    }    

    static Node* connect(Node* root) {
        Node* dummy = new Node(0);
        Node* cur = nullptr;
        dummy->next = root;
        Node* pre = dummy;

        while( pre->next) {
            // 取head
            cur = pre->next;
            // 清空头指针
            pre->next = nullptr;
            dummy = pre;
            // 遍历cur层，构造下一层
            while(cur){
                if(cur->left){
                    dummy->next = cur->left;
                    dummy = dummy->next;
                }
                if(cur->right) {
                    dummy->next = cur->right;
                    dummy = dummy->next;
                }
                cur = cur->next;
            }
        }
        return root;
    }
};

int main(){
    std::unique_ptr<Node> node = Solution::MakeTree();
    Solution::connect(node.get());
}