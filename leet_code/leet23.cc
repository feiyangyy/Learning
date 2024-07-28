#include "common_def.h"
#include <queue>
// sln1
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (auto node : lists) {
      while (node) {
        q.push(node->val);
        node = node->next;
      }
    }
    ListNode *dummy = new ListNode(-1);
    ListNode *pre = dummy;
    while (!q.empty()) {
      pre->next = new ListNode(q.top());
      q.pop();
      pre = pre->next;
    }
    return dummy->next;
  }
};
class Solution2 {
public:
  ListNode *merge2lists(ListNode *lhs, ListNode *rhs) {
    if (lhs == nullptr) {
      return rhs;
    }
    if (rhs == nullptr) {
      return lhs;
    }
    ListNode *res;
    if (lhs->val < rhs->val) {
      res = lhs;
      res->next = merge2lists(lhs->next, rhs);
      return lhs;
    } else {
      res = rhs;
      res->next = merge2lists(lhs, rhs->next);
      return rhs;
    }
    return nullptr;
  }
  ListNode *merge_list(vector<ListNode *> &lists, int l, int r) {
    // 返回条件：split 直到节点为1个链表，或者两个链表
    // 归并子链表
    // 合并子链表，返回结果
    if (l == r) { // ----返回条件，不要纳入递归的过程中
      return lists[l];
    }
    int mid = (l + r) / 2;
    ListNode *left = merge_list(lists, l, mid);      // --递归过程
    ListNode *right = merge_list(lists, mid + 1, r); // --递归过程
    return merge2lists(left, right);                 // 处理
  }
  // 分治法 （归并排序中的归并） 可以减少中间结果
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // 无聊的case
    if (lists.size() == 0) {
      return nullptr;
    }
    return merge_list(lists, 0, lists.size() - 1);
  }
};