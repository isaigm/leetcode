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
        int keys = 1;
        std::map<int, int> frq;
        dfs(frq, root);
        for(const auto &p: frq)
        {
            if(keys >= 2) return false;
            keys++;
        }
        return true;
    }
    void dfs(std::map<int, int> &frq, TreeNode *root)
    {
        if(root)
        {
            frq[root->val]++;
            dfs(frq, root->left);
            dfs(frq, root->right);
        }
    }
};