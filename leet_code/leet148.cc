#include "common_def.h"
// 主要是回忆一下各种排序，特别是，快速排序和归并排序，并且在链表形式下的实现
// 需要头脑清醒的时候回忆?

class Solution {
public:

    ListNode* merge_sort(ListNode* head) {
        ListNode* fast, * slow;
        if(!head || !head->next) {
            return head;
        }
        slow = head;
        fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        // 排序前半部分
        ListNode* left = merge_sort(head);
        // 排序后半部分
        ListNode* right = merge_sort(mid);
        // 合并
        ListNode dummy, *pd;
        pd = &dummy;
        while(left && right) {
            if(left->val < right->val){
                pd->next=left;
                left= left->next;
            } else {
                pd->next = right;
                right = right->next;
            }
            pd = pd->next;
        }
        while (left) {
            pd->next = left;
            left=left->next;
            pd = pd->next;
        }
        while (right) {
            pd->next = right;
            right = right->next;
            pd = pd->next;
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};