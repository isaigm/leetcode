// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    int util(TreeNode *root)
    {
        if(root != nullptr)
        {
            int left_min = INT_MAX;
            int right_min = INT_MAX;
            if(root->left != nullptr)
            {
                left_min = std::abs(root->val - root->left->val);
            }
            if(root->right != nullptr)
            {
                right_min = std::abs(root->val - root->right->val);
            }
            return std::min({left_min, right_min, util(root->left), util(root->right)});
        }
        return INT_MAX;
    }
    int getMinimumDifference(TreeNode* root) {
      return util(root);
    }
};