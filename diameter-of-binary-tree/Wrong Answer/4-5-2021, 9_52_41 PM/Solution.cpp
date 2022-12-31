// https://leetcode.com/problems/diameter-of-binary-tree

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
    int diameterOfBinaryTree(TreeNode* root) {
        return maxDepth(root->right) + maxDepth(root->left);
    }
    int maxDepth(TreeNode *root)
    {
        if(root != nullptr)
        {
            int left = 1 + maxDepth(root->left);
            int right = 1 + maxDepth(root->right);
            
            return std::max(left, right);
        }
        return 0;
    }
};