// https://leetcode.com/problems/path-sum-iii

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
void aux(TreeNode *root, int &curr_sum, int &sum, int &total){
    if(root != nullptr){
        if(curr_sum == sum) total++;
        curr_sum += root->val;
        aux(root->left, curr_sum, sum, total);
        aux(root->right, curr_sum, sum, total);
        curr_sum -= root->val;
    }
    
}
void dfs(TreeNode *root, int &sum, int &total){
    if(root != nullptr){
        int curr_sum = 0;
        aux(root, curr_sum, sum, total);
        dfs(root->left, sum, total);
        dfs(root->right, sum, total);
    }
}

int pathSum(TreeNode* root, int sum) {
        int total = 0;
        dfs(root, sum, total);
        return total;
}
};