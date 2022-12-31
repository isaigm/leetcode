// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    int minDiffInBST(TreeNode* root) {
        int min = INT_MAX;
        int last = 0;
        dfs(root, min, last);
        return min;
    }
    void dfs(TreeNode *root, int &min, int &last)
    {
        if(root)
        {
            dfs(root->left, min, last);
            min = std::min(min, std::abs(last - root->val));
            last = root->val;
            dfs(root->right, min, last);
        }
    }
};