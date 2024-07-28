#include "common_def.h"
#include <unordered_set>

class Solution {
public:
// sln1
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> n;
        ListNode* p = head;
        while(p){
            // 在记录的表中发现了旧的节点
            auto it = n.find(p);
            if(it != n.end() ) {
                return true;
            }
            n.insert(p);
            p = p->next;
        }
        return false;
    }
    // sln 2
    // 使用快慢指针，在有环的情况下，快指针一定会和慢指针相遇
    // 考虑相对速度
    // 考虑快慢指针应用
    // 指针步长和类型有关，不要忘记了
    bool hasCycle(ListNode* head) {
        ListNode *ps, *pf;
        ps= pf = head;
        // 只要tail = nullptr就是false
        while(ps && pf && pf->next) {
            ps = ps->next;
            pf = pf->next->next;
            if(ps == pf){
                return true;
            }
        }
        return false;
    }
};