#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;



struct TreeNode {

    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};


class Solution {
public:
    TreeNode* ConstructBst(vector<int>& nums, int l, int r) {
        // if there is only 2 elements, the mid will be equal to the left(start)
        #if 1
        if(l>r) {
            // ???
            return nullptr;
        }
        #endif
        if(l == r) {
             TreeNode* node = new TreeNode(nums[l]);
             node->left = nullptr;
             node->right = nullptr;
             return node;
        }
        int mid = (l + r) / 2;
        // mid is already token.
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = ConstructBst(nums, l, mid - 1);
        node->right = ConstructBst(nums, mid + 1, r);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) {
            return nullptr;
        }
        return ConstructBst(nums, 0, nums.size() - 1);
    }
};