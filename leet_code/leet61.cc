
struct ListNode {
  explicit ListNode(int i = 0) : val(i), next(nullptr) {}
  ListNode *next;
  int val;
};
class Solution {
public:
  int GetListSize(ListNode *head) {
    int res = 0;
    while (head) {
      head = head->next;
      ++res;
    }
    return res;
  }

  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) {
      return head;
    }
    int size = GetListSize(head);
    ListNode *h0 = head;

    k = size - k % size;
    if (k == size) {
      return head;
    }
    ListNode *tail = nullptr;
    ListNode *h1 = head;
    while (k > 1) {
      // working on k !=0
      h1 = h1->next;
      --k;
    }
    // 指针
    head = h1->next;
    // 断开
    h1->next = nullptr;
    // 找到new head的结尾,和h0 相连
    tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = h0;
    return head;
  }
};