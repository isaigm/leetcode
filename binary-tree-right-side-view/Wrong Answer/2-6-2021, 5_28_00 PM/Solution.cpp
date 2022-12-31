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
    void helper(std::vector<int> &res, TreeNode *root, bool is_right_node)
{
    
   static bool first_time = true;
    if (root != NULL)
    {
        if (is_right_node)
        {
            res.push_back(root->val);
        }
        if (first_time)
        {
            helper(res, root->right, true);
            first_time = false;
        }
        else
        {
            helper(res, root->right, true);
            helper(res, root->left, false);
            
        }
    }
}
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> vec;
        helper(vec, root, true);
        return vec;
    }
};