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
    ListNode* partition(ListNode* head, int x) {
        ListNode* sml = new ListNode(0);
        ListNode* gt = new ListNode(1);
        ListNode* p0 = sml;
        ListNode* p1 = gt;
        while(head){
            if(head->val < x){
                p0->next = head;
                // head = head->next;
                p0 = p0->next;
            } else {
                p1->next = head;
                p1 = p1->next;
            }
            head = head->next;
        }
        p0->next = gt->next;
        // 注意边界值赋值处理
        p1->next = nullptr;
        return sml->next;
    }
};