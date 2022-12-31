// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void helper(TreeNode *root, int &sum, string &n){
        if(root != nullptr){
            n.push_back(root->val + '0');
            if(root->left == nullptr && root->right == nullptr){
                stringstream aux(n);
                int k;
                aux >> k;
                sum += k;
            }else{
                helper(root->left, sum, n);
                helper(root->right, sum, n);
            }
            n.pop_back();
            
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string n;
        helper(root, sum, n);
        return sum;
    }
};