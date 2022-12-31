// https://leetcode.com/problems/balanced-binary-tree

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
    int util(TreeNode *root, bool &ans)
    {
        if(root != nullptr && ans)
        {
            int l = 1 + util(root->left, ans);
            int r = 1 + util(root->right, ans);
            if(std::abs(l - r) > 1)
            {
                ans = false;
            }
            return std::max(l, r);
        }
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        util(root, ans);
        return ans;
    }
};