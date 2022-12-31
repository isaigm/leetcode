// https://leetcode.com/problems/binary-tree-pruning

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
     void util(TreeNode **root) {
        if(*root)
        {
            util(&((*root)->left));
            util(&((*root)->right)); 
            if(ones(*root) == 0){
                *root = nullptr;
            }
        }
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        util(&root);
        return root;
    }
    int ones(TreeNode *root)
    {
        if(root)   
        {
          
            return root->val + ones(root->left) + ones(root->right);
        }
        return 0;
    }
};