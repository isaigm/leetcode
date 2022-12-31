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
static int m = INT_MAX;
static int last = 0;
static bool first_time = false;
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return m;
    }
    void dfs(TreeNode *root)
    {
        if(root)
        {
            dfs(root->left);
            if(!first_time && root->val == 0)
            {
                first_time = true;
                return;
            }
            m = std::min(m, std::abs(last - root->val));
            last = root->val;
            dfs(root->right);
        }
    }
};