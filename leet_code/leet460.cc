#include "common_def.h"
struct LNode {
  int key;
  int val;
  int freq;
  LNode *next;
  LNode *prev;
  LNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};
// LRU
struct WrappedList {
  LNode *head_;
  LNode *tail_;
  WrappedList() {
    head_ = new LNode(-1, -1);
    tail_ = new LNode(-1, -1);
    head_->next = tail_;
    tail_->prev = head_;
  }
  // 往tail插入
  void AddNewNode(LNode *node) {
    tail_->prev->next = node;
    node->prev = tail_->prev;
    node->next = tail_;
    tail_->prev = node;
  }
  // 一般是移除head
  LNode *RemoveNode(LNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    return node;
  }

  LNode *RemoveHead() {
    if (Empty()) {
      return nullptr;
    }
    return RemoveNode(head_->next);
  }

  // is_emtpy
  bool Empty() { return head_->next == tail_; }
};

class LFUCache {
  // key-to-node
  std::unordered_map<int, LNode *> node_hash_;
  // freq-to-list
  std::unordered_map<int, WrappedList *> hash_;
  // key, freq --> 合并到 node_hash 理
  // std::unordered_map<int, int> key_freq_hash_;
  int min_freq = 0;
  int capacity_ = 0;
  int count_ = 0;

public:
  LFUCache(int capacity) {
    capacity_ = capacity;
    count_ = 0;
    hash_.insert(std::make_pair(1, new WrappedList()));
  }

  int get(int key) {
    auto it = node_hash_.find(key);
    if (it == node_hash_.end()) {
      return -1;
    }
    int res = it->second->val;
    AddNodeFreq(it->second);
    return res;
  }

  void AddNodeFreq(LNode *node) {
    int old_freq = node->freq++;
    hash_[old_freq]->RemoveNode(node);
    if (min_freq == old_freq && hash_[old_freq]->Empty()) {
      ++min_freq;
    }
    auto it = hash_.find(node->freq);
    if (it == hash_.end()) {
      hash_.insert(std::make_pair(node->freq, new WrappedList));
    }
    hash_[node->freq]->AddNewNode(node);
  }

  void RemoveOne() {
    auto it_list = hash_.find(min_freq);
    auto node = it_list->second->RemoveHead();
    auto it_node = node_hash_.find(node->key);
    node_hash_.erase(it_node);
    delete node;
    // 更新min_freq
    for (;;) {
      auto it = hash_.find(min_freq);
      if (it != hash_.end()) {
        min_freq = -1;
        break;
      }
      if (it->second->Empty()) {
        ++min_freq;
        continue;
      }
      break;
    }
  }

  void put(int key, int value) {
    auto it = node_hash_.find(key);
    bool create_new = false;
    LNode *node = nullptr;
    int freq = -1;
    if (it == node_hash_.end()) {
      node = new LNode(key, value);
      node_hash_.insert(std::make_pair(key, node));
      ++count_;
      if (count_ > capacity_) {
        RemoveOne();
        --count_;
      }
      hash_[1]->AddNewNode(node);
      min_freq = node->freq = 1;
      // 准备插入，如果超过size，则寻找一个合适位置
    } else {
      node = it->second;
      node->val = value;
      AddNodeFreq(node);
    };
  }
};