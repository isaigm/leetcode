// https://leetcode.com/problems/longest-univalue-path

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
    void util(TreeNode *root, int parent, int &path, int &ans)
    {
        if(root != nullptr)
        {
            if(root->val == parent)
            {
                path++;
            }else {
                path = 0;
            }
            
            ans = std::max(ans, path);
            util(root->left, root->val, path, ans);
            path = 0;
            util(root->right, root->val, path, ans);
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = INT_MIN;
        int path = 1;
        util(root, INT_MIN, path, ans);
        return ans;
    }
};