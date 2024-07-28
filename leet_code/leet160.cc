#include "common_def.h"
#include <unordered_set>

class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> nodes;
        while(headA){
            nodes.insert(headA);
            headA=headA->next;
        }
        // 判断交汇
        while(headB){
            auto it = nodes.find(headB);
            if(it != nodes.end()){
                return *it;
            }
            headB = headB->next;
        }
        return nullptr;
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }
        ListNode* pa, * pb;
        pa = headA;
        pb = headB;
        // 注意，如果pa == pb = nullptr 此时也会退出
        // pa 和 pb 肯定有一个人先到尾部
        // 然后同时迭代，当另外一者到达尾部并重置时，两者就会同步开始迭代
        while(pa != pb){
            #if 1
            // 迭代后再判断
            if(!pa){
                pa = headB;
            } else {
                pa = pa->next;
            }
            if(!pb){
                pb = headA;
            } else {
                pb = pb->next;
            }
            #endif 

        }
        return pa;
    }
};