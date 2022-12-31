// https://leetcode.com/problems/binary-tree-paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ans;
        dfs("", ans, root);
        return ans;
    }
    void dfs(std::string s, std::vector<std::string> &ans, TreeNode *root)
    {
        if(root)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                s += std::to_string(root->val);
                ans.push_back(s);
                return;
            }
            dfs(s + std::to_string(root->val) + "->", ans, root->left);
            dfs(s + std::to_string(root->val) + "->", ans, root->right);
        }
    }
};