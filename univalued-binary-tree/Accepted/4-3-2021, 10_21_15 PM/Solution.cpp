// https://leetcode.com/problems/univalued-binary-tree

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
    bool isUnivalTree(TreeNode* root) {
        bool ans = true;
        int unique = root->val;
        dfs(ans, unique, root);
        return ans;
    }
    void dfs(bool &ans, int &unique, TreeNode *root)
    {
        if(root)
        {
            if(root->val == unique)
            {
                dfs(ans, unique, root->left);
                dfs(ans, unique, root->right);
            } else ans = false;
        }
    }
};