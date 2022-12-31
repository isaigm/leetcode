// https://leetcode.com/problems/trim-a-binary-search-tree

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
    void trim(TreeNode **node, int low, int high)
{
    
    if (*node != nullptr)
    {
        if ((*node)->val < low)
        {
            if ((*node)->left != nullptr)
            {
                delete ((*node)->left);
                (*node)->left = nullptr;
            }
            trim(&((*node)->right), low, high);
            auto right = (*node)->right;
            delete (*node);
            *node = nullptr;
            *node = right;
        }
        else if ((*node)->val > high)
        {
            if ((*node)->right != nullptr)
            {
                delete ((*node)->right);
                (*node)->right = nullptr;
            }
            trim(&((*node)->left), low, high);
            auto left = (*node)->left;
            delete (*node);
            *node = nullptr;
            *node = left;
        }else{
            trim(&((*node)->left), low, high);
            trim(&((*node)->right), low, high);
        }
    }
}
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        trim(&root, low, high);
        return root;
    }
};