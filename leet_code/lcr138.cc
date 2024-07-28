#include <stdio.h>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
// 链表这块还是不行
// 需要加强!!!!
class Solution {
public:
  Node *copyRandomList(Node *head) {
    Node *dummy = new Node(-1);
    Node *cloned = dummy;
    Node *src = head;
    // copy node.
    while (head) {
      cloned->next = new Node(head->val);
      Node *n = head->next;
      // connect src node->next = to cloned.
      head->next = cloned->next;
      // connect cloned node->next = n;
      cloned->next->next = n;
      cloned = cloned->next;
      // head go to n
      head = n;
    }
    head = src;
    cloned = head->next;
    while (head) {
      if (head->random) {
        cloned->random = head->random->next;
      }
      if (!cloned) {
        break;
      }
      head = cloned->next;
      if (!head) {
        break;
      }
      cloned = head->next;
    }
    int cnt = 0;
    cloned = dummy;
    head = src;
    while (head) {
      cloned->next = head->next;
      cloned = cloned->next;
      if (!cloned) {
        break;
      }
      // 回复原指针
      head->next = cloned->next;
      head = head->next;
    }
    return dummy->next;
  }
};