class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        while(head && head->next){
            if(head->val == head->next->val){
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return pre->next;
    }
};