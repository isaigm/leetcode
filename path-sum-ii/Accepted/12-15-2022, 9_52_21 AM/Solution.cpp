// https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        int sum = 0;
        helper(root, res, sum, targetSum, path);
        return res;
    }
    void helper(TreeNode *root, std::vector<std::vector<int>>& res, int &sum, int &targetSum, std::vector<int> &path)
    {
        if(root)
        {
            path.push_back(root->val);
            sum += root->val;
            if(root->left == nullptr && root->right == nullptr && sum == targetSum){
                std::vector<int> copy(path);
                res.push_back(copy);
            }
            helper(root->left, res, sum, targetSum, path);
            helper(root->right, res, sum, targetSum, path);
            sum -= root->val;
            path.pop_back();
        }
    }
};