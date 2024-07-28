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
#include "common_def.h"

class Solution {
public:
    ListNode* SwapList(ListNode* head) {
        // 只有1个或者2个节点，不翻转
        if(head->next == nullptr){
            return head;
        }
        if(head->next->next == nullptr){
            return head;
        }
        ListNode* tail = head->next;
        ListNode* prev = head;
        while(tail->next != nullptr){
            tail = tail->next;
            prev = prev->next;
        }
        // 断开
        // 后继节点
        ListNode* succecor = head->next;
        // 设置尾节点
        prev->next = nullptr;
        // 连接tail
        head->next = tail;
        // 连接后继
        tail->next = SwapList(succecor);
        return head;
    }
    void reorderList(ListNode* head) {
        head=SwapList(head);
    }
};