#include "common_def.h"
class Solution {
public:
// 反转节点
#if 0
  ListNode *reverse_node(ListNode *node, int k) {
    if (k == 1) {
      return node;
    }
    // 此处返回的是sub_list的head
    ListNode *sub_list = reverse_node(node->next, --k);
    ListNode *tmp = node->next->next;
    // 反向
    node->next->next = node;
    node->next = tmp;
    return sub_list;
  }
#endif
  // 非递归方式，实现反转
  // !!!!!  加精 !!!!!!
  ListNode *reverse_node(ListNode *node, int k) {
    ListNode *pre, *next;
    ListNode *tmp = node->next;
    pre = node;
    // 此处含义是反转几次
    while (--k) {
      next = tmp;
      // 下个节点
      tmp = next->next;
      next->next = pre;
      pre = next;
    }
    // 反转的头节点
    return next;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1 || k == 0) {
      return head;
    }
    ListNode *dummy, *pre, *end;
    dummy = new ListNode(-1);
    dummy->next = head;
    pre = end = dummy;
    ListNode *succesor;
    while (end != nullptr) {
      int tmp = k;
      while (end && tmp--) {
        end = end->next;
      }
      // 到达末尾
      if (!end) {
        break;
      }
      // 后继
      succesor = end->next;
      // 前驱就是pre
      ListNode *h = reverse_node(pre->next, k);
      // 反转的末尾
      ListNode *tail = pre->next;
      // 链接后继
      pre->next->next = succesor;
      // 链接反转
      pre->next = h;
      // 设置到结尾，下一次反转的前驱
      pre = tail;
      end = pre; // 就是succesor.
    }
    return dummy->next;
  }
};

int main() {
  // new 关键字不能直接调用对象的具体构造函数(AKA， 使用默认构造！)
  ListNode *l = new ListNode[5];
  l[0].val = 0;
  l[1].val = 1;
  l[2].val = 2;
  l[3].val = 3;
  l[4].val = 4;
  l[0].next = &l[1];
  l[1].next = &l[2];
  l[2].next = &l[3];
  l[3].next = &l[4];
  l[4].next = nullptr;
  Solution().reverseKGroup(l, 2);
  return 0;
}