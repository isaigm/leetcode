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
    void dfs(TreeNode *root, int &curr_sum, int &sum, int &total){
    if(root != nullptr){
        curr_sum += root->val;
        if(curr_sum == sum){
            curr_sum = 0;
            total++;
        }
        if(sum > 0){
            if(curr_sum > sum || curr_sum < 0){
                curr_sum = 0;
            }
        }else{
            if(curr_sum < sum || curr_sum > 0){
                curr_sum = 0;
            }
        }
        dfs(root->left, curr_sum, sum, total);
        dfs(root->right, curr_sum, sum, total);
        
    }
}

int pathSum(TreeNode* root, int sum) {
        int curr_sum = 0, total = 0;
        dfs(root, curr_sum, sum, total);
        return total;
}
};