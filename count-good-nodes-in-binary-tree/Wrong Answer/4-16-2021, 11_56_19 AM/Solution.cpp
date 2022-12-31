// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int goodNodes(TreeNode* root) {
        int maxx = INT_MIN;
        int ans = 0;
        dfs(root, ans, maxx);
        return ans;
    }
    void dfs(TreeNode *root, int &ans, int &maxx)
    {
        if(root)
        {
            int last_max = maxx;
            
            if(root->val >= maxx)
            {
                maxx = root->val;
                ans++;
            }
            dfs(root->left, ans, maxx);
            maxx = last_max;
            dfs(root->right, ans, maxx);
        }
    }
};