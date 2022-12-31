// https://leetcode.com/problems/add-one-row-to-tree

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
    void util(TreeNode *root, int &v, int &d, int curr_depth)
    {
        if(root != nullptr)
        {
            auto left = root->left;
            auto right = root->right;
            if(curr_depth < d)
            {
                auto l = left == nullptr ? nullptr : new TreeNode(v);
                auto r = right == nullptr ? nullptr: new TreeNode(v);
                if(l != nullptr && r != nullptr)
                {
                    l->left = left; 
                    r->right = right;
                    root->left = l;
                    root->right = r;
                }
           
            }
            util(left, v, d, curr_depth + 1);
            util(right, v, d, curr_depth + 1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
     
        if(d == 1)
        {
            auto new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }
        else util(root, v, d, 1);
        return root;
    }
};