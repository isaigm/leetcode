// https://leetcode.com/problems/delete-leaves-with-a-given-value

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, target);
        if(is_leaf(root) && root->val == target)
        {
            return nullptr;
        }
        return root;
    }
    bool is_leaf(TreeNode *root)
    {
        return root && root->left == nullptr && root->right == nullptr;
    }
    void dfs(TreeNode *root, int target)
    {
        if(root)
        {
            if(is_leaf(root->left) && root->left->val == target)
            {
                root->left = nullptr;
            }
            if(is_leaf(root->right) && root->right->val == target)
            {
                root->right = nullptr;
            }
            dfs(root->left, target);
            dfs(root->right, target);
            if(is_leaf(root->left) && root->left->val == target)
            {
                root->left = nullptr;
            }
            if(is_leaf(root->right) && root->right->val == target )
            {
                root->right = nullptr;
            }
        }
    }
};