
#include "common_def.h"
// 反转链表
class Solution
{
public:
  ListNode *rvList(ListNode *head)
  {
    // 此处要特殊处理
    if (!head->next)
    {
      return nullptr;
    }
    // 下一个节点是结尾
    if (!head->next->next)
    {
      head->next->next = head;
      return head;
    }
    ListNode *rv = rvList(head->next);
    // 翻转
    // 记住结尾
    head->next = rv->next;
    rv->next = head;
    return head;
  }
  ListNode *reverseList(ListNode *head)
  {
    if (!head || !head->next)
    {
      return head;
    }
    head = rvList(head);
    ListNode *rh = head->next;
    head->next = nullptr;
    return rh;
  }
};