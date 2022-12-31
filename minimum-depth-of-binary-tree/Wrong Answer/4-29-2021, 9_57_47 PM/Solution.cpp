// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int minDepth(TreeNode* root) {
        if(root == nullptr) 0;
        int ans = INT_MAX;
        dfs(root, ans);
        return ans;
    }
    void dfs(TreeNode *root, int &ans, int depth = 1)
    {
        if(root)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                ans = std::min(ans, depth);
            }
            dfs(root->left, ans, depth + 1);
            dfs(root->right, ans, depth + 1);
        }
    }
};