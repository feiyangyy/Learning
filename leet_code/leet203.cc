#include "common_def.h"
class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    // 注意会不会漏掉最后一个节点
    while (pre->next)
    {
      if (pre->next->val == val)
      {
        // 修改next节点， 但不跳转
        ListNode *td = pre->next;
        pre->next = pre->next->next;
        delete td;
        continue;
      }
      else
      {
        pre = pre->next;
      }
    }
    return dummy.next;
  }
};