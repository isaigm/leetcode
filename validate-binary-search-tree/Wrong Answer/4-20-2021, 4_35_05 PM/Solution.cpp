// https://leetcode.com/problems/validate-binary-search-tree

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
    bool first_time = false;
    int last_value;
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
    void dfs(TreeNode *root, bool &ans)
    {
        if(!ans) return;
        if(root)
        {
            dfs(root->left, ans);
            if(!first_time)
            {
                first_time = true;
            }else if(root->val < last_value){
                ans = false;
            }
            last_value = root->val;
            dfs(root->right, ans);
        }
    }
};