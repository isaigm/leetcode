// https://leetcode.com/problems/binary-tree-right-side-view

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
void rightViewUtil(TreeNode *root,std::vector<int> &res,  
                   int level, int *max_level) 
{ 
    // Base Case 
    if (root == NULL) return; 
  
    // If this is the last Node of its level 
    if (*max_level < level) 
    { 
        res.push_back(root->val);
        *max_level = level; 
    } 
  
    // Recur for right subtree first,  
    // then left subtree 
    rightViewUtil(root->right, res, level + 1, max_level); 
    rightViewUtil(root->left, res, level + 1, max_level); 
} 
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> vec;
          int max_level = 0; 
    rightViewUtil(root, vec, 1, &max_level); 
        return vec;
    }
};