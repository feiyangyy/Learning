#ifndef COMMON_DEF_
#define COMMON_DEF_ 1
#include <algorithm>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector;
struct TreeNode {

  int val;

  TreeNode *left;

  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

struct ListNode {
  explicit ListNode(int i = 0) : val(i), next(nullptr) {}
  ListNode *next;
  ListNode *prev;
  int val;
};

#endif