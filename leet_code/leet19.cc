/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* sec = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        first = dummy;
        // sec = dummy;
        if(!head){
            return head;
        }
        // n>0的话就多跑了一步
        while(n > 1) {
            sec = sec->next;
            --n;
        }
        while(sec && sec->next) {
            sec = sec->next;
            first = first->next;
        }
        // 删去first 下一节点
        first->next = first->next->next;
        return dummy->next;
    }
};