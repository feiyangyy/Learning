class Solution {
public:
    ListNode* head;
    TreeNode* sortedListToBST(ListNode* h) {
        int sz = 0;
        head = h;
        while(h) {
            sz++;
            h = h->next;
        }
        return build(0, sz - 1);
    }
    TreeNode* build(int l, int r) {
        if(l > r) {
            return nullptr;
        }
        int mid = (l + r) / 2;
        TreeNode* left = build(l, mid - 1);
        TreeNode* node = new TreeNode(head->val);
        node->left = left;
        head = head->next;
        node->right = build(mid + 1, r);
        return node;
    }
};