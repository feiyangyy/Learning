/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "common_def.h"
#include <unordered_set>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::unordered_set<ListNode*> n;
        ListNode* p = head;
        while(p){
            // 在记录的表中发现了旧的节点
            auto it = n.find(p);
            if(it != n.end() ) {
                return (*it);
            }
            n.insert(p);
            p = p->next;
        }
        return nullptr;
    }
    // 
    // 不光是要找到是否存在环，还要确认这个节点的位置
    // 不想那么随意，想要十分认真的工作，想要全身心的投入，想要获得回报，想要体现价值
    // 想想你在camb的遭遇，你最终获得了你想要的成长吗?不过是自我欺骗罢了，人家都跑完了，只有你还在觉得自己在坚持，最后落得这个下场
    // 
    ListNode *detectCycle2(ListNode* head) {
        ListNode *ps, *pf;
        ps= pf = head;
        // 只要tail = nullptr就是false
        while(ps && pf && pf->next) {
            ps = ps->next;
            pf = pf->next->next;
            // 追上的位置，不一定是环的位置
            if(ps == pf){
                // 追上的位置, ps = n*b，此时距离入口还差a步，因为a + nb = a 
                pf = head;
                while(pf != ps) {
                    pf= pf->next;
                    ps = ps->next;
                }
                return pf;
            }
        }
        return nullptr;
    }
};