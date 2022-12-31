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
        int d = 0;
        maxDepth(d, root);
        return d;
    }
    int maxDepth(int & d, TreeNode *root)
    {
        if(root != nullptr)
        {
            int left = maxDepth(d, root->left);
            int right = maxDepth(d, root->right);
            d = std::max(d, left + right);
            return std::max(left, right) + 1;
        }
        return 0;
    }
};