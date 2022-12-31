// https://leetcode.com/problems/deepest-leaves-sum

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
    int deepestLeavesSum(TreeNode* root) {
        int depth = max_depth(root);
        int sum = 0;
        dfs(root, 1, depth, sum);
        return sum;
    }
    void dfs(TreeNode *root, int level, int &depth, int &sum)
    {
        if(root)
        {
            if(level == depth)
            {
                sum += root->val;
            }
            dfs(root->left, level + 1, depth, sum);
            dfs(root->right, level + 1, depth, sum);
        }
    }
    int max_depth(TreeNode *root)
    {
        if(root)
        {
            return 1 + std::max(max_depth(root->left), max_depth(root->right));
        }
        return 0;
    }
};