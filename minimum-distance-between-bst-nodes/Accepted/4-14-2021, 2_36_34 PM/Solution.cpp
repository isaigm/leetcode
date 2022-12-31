// https://leetcode.com/problems/minimum-distance-between-bst-nodes


class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int m = INT_MAX;
        int last = -1;
        dfs(root, m, last);
        return m;
    }
    void dfs(TreeNode *root, int &m, int &last)
    {
        if(root)
        {
            dfs(root->left, m, last);
            if(last != -1)
            {
                m = std::min(m, std::abs(last - root->val));
            }
            last = root->val;
            dfs(root->right, m, last);
        }
    }
};