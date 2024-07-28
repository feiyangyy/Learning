#include "common_def.h"
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *res = new ListNode(-1);
    ListNode *pre = res;
    while (l1 && l2) {
      int tmp = l1->val + l2->val + carry;
      carry = tmp / 10;
      pre->next = new ListNode(tmp % 10);
      pre = pre->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1) {
      int tmp = l1->val + carry;
      carry = tmp / 10;
      pre->next = new ListNode(tmp % 10);
      pre = pre->next;
      l1 = l1->next;
    }
    while (l2) {
      int tmp = l2->val + carry;
      carry = tmp / 10;
      pre->next = new ListNode(tmp % 10);
      pre = pre->next;
      l2 = l2->next;
    }
    if (carry) {
      pre->next = new ListNode(carry);
      pre = pre->next;
    }
    return res->next;
  }
};