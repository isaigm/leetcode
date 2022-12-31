// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent

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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        TreeNode *grand_parent = nullptr;
        TreeNode *parent = nullptr;
        dfs(root, grand_parent, parent, sum);
        return sum;
    }
    void dfs(TreeNode *root, TreeNode *grand_parent, TreeNode *parent, int &sum)
    {
        if(root != nullptr)
        {
            if(grand_parent && grand_parent->val % 2 == 0)
            {
                sum += root->val;
            }
            grand_parent = parent;
            parent = root;
            dfs(root->left, grand_parent, parent, sum);
            dfs(root->right, grand_parent, parent, sum);
        }
    }
};