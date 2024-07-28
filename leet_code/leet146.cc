#include "common_def.h"
#include <unordered_map>
struct LNode {
  explicit LNode(int i, int k) : key(k), val(i), next(nullptr), prev(nullptr) {}
  LNode *next;
  LNode *prev;
  int val;
  int key;
};

class LRUCache {
public:
  LNode *head_, *tail_;
  int capcity_ = 0;
  int count_ = 0;
  std::unordered_map<int, LNode *> hash_;
  LRUCache(int capacity) {
    capcity_ = capacity;
    // head_ = tail_ = nullptr;
    head_ = new LNode(-1, -1);
    tail_ = new LNode(-1, -1);
    head_->next = tail_;
    tail_->prev = head_;
  }

  void move_node_to_tail(LNode *node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;

    // move to tail
    tail_->prev->next = node;
    node->prev = tail_->prev;
    tail_->prev = node;
    node->next = tail_;
  }

  void add_new_node_to_tail(LNode *node) {
    tail_->prev->next = node;
    node->prev = tail_->prev;
    tail_->prev = node;
    node->next = tail_;
  }

  int get(int key) {
    auto it = hash_.find(key);
    if (it == hash_.end()) {
      return -1;
    }
    int res = it->second->val;
    // update
    move_node_to_tail(it->second);
    return res;
  }

  void put(int key, int value) {
    auto it = hash_.find(key);
    LNode *node = nullptr;
    bool create_new = false;
    if (it == hash_.end()) {
      node = new LNode(value, key);
      hash_.insert(std::make_pair(key, node));
      ++count_;
      create_new = true;
    } else {
      node = it->second;
      it->second->val = value;
    }
    if (count_ > capcity_) {
      // 删除head
      LNode *prev = head_->next;
      // 移动head
      head_->next->next->prev = head_;
      head_->next = head_->next->next;

      auto it2 = hash_.find(prev->key);
      hash_.erase(it2);
      delete prev;
      add_new_node_to_tail(node);
      --count_;
    } else if (create_new) {
      add_new_node_to_tail(node);
    } else {
      move_node_to_tail(node);
    }
  }
};
//[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
int main() {
#if 1
  LRUCache lru(2);
  lru.put(1, 1);
  lru.put(2, 2);
  lru.get(1);
  lru.put(3, 3);
  lru.get(2);
  lru.put(4, 4);
  lru.get(1);
  lru.get(3);
  lru.get(4);
#else
  LRUCache lru(1);
  lru.put(2, 1);
  lru.get(2);
  lru.put(3, 2);
  lru.get(2);
  lru.get(3);
#endif
  return 0;
}