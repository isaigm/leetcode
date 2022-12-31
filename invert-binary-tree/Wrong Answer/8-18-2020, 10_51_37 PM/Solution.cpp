// https://leetcode.com/problems/invert-binary-tree

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
    void helper(TreeNode* root) {
    if(root != nullptr){
        if(root->left != nullptr && root->right != nullptr){
            std::swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
    }
}
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};