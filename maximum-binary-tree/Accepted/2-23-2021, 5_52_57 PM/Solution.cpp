// https://leetcode.com/problems/maximum-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void util(std::vector<int> &nums, TreeNode **root, int left, int right){
       if (left <= right && left >= 0 && right < nums.size())
        {
            auto max_val = std::max_element(nums.begin() + left, nums.begin() + right + 1);
            *root = new TreeNode(*max_val);
            int idx = std::distance(nums.begin(), max_val);
            util(nums, &((*root)->left), left, idx - 1);
            util(nums, &((*root)->right), idx + 1, right);
        }
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root = nullptr;
        util(nums, &root, 0, nums.size() - 1);
        return root;
    }
};