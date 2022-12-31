// https://leetcode.com/problems/path-sum

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
    void dfs(TreeNode *root, bool &flag, int sum){
    if(root != nullptr){
        if(sum == 0 && root->left == nullptr && root->right == nullptr){
            flag = true;
            return;
        }
        if(root->left != nullptr){
            dfs(root->left, flag, sum - root->left->val);
        }
        if(root->right != nullptr){
            dfs(root->right, flag, sum - root->right->val);
        }
    }
}
bool hasPathSum(TreeNode* root, int sum) 
{
    if(root == nullptr) return false;
    bool flag = false;
    dfs(root, flag, sum - root->val);
    return flag;
}
};