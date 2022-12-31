// https://leetcode.com/problems/increasing-order-search-tree

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
    TreeNode *new_root = nullptr;
    TreeNode *cursor = nullptr;
    TreeNode* increasingBST(TreeNode* root) {
        util(root);
        
        return new_root;
    }
    void util(TreeNode *root)
    {
        if(root)
        {
            util(root->left);
            if(new_root == nullptr)
            {
                new_root = new TreeNode(root->val);
                cursor = new_root;
            }else
            {
                cursor->right = new TreeNode(root->val);
                cursor = cursor->right;
            }
            util(root->right);
        }
    }
};