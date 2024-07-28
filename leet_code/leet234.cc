#include "common_def.h"
#include <stack>
#include <queue>
class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    std::queue<int> val_q;
    std::stack<int> val_stk;
    while (head)
    {
      val_q.push(head->val);
      val_stk.push(head->val);
      head = head->next;
    }
    while (!val_stk.empty())
    {
      if (val_q.front() != val_stk.top())
      {
        return false;
      }
      val_q.pop();
      val_stk.pop();
    }
    return true;
  }
};