#include "common_def.h"
class Solution {
public:
  ListNode *reverse(ListNode *node, int cnt) {
    if (cnt == 1) {
      return node;
    }
    // 这个返回的是反转的head,这个last只是返回值
    ListNode *last = reverse(node->next, cnt - 1);
    // 反转的过程不需要其他信息，只是需要tail作为返回值
    ListNode *successor = node->next->next;
    node->next->next = node;
    node->next = successor;
    return last;
  }
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *prev = new ListNode(-1);
    prev->next = head;
    ListNode *hold = prev;
    int cnt = right - left + 1;
    while (left > 1) {
      prev = prev->next;
      --left;
    }
    prev->next = reverse(prev->next, cnt);
    return hold->next;
  }
};