// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
    void helper(TreeNode *root, int *cnt, int &ans)
    {
        if(root == nullptr) return;
        cnt[root->val]++;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(is_palindrome(cnt)) ans++;
        }else
        {
            helper(root->left, cnt, ans);
            helper(root->right, cnt, ans);
        }
        cnt[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt[10] = {0};
        int ans = 0;
        helper(root, cnt, ans);
        return ans;
    }
    bool is_palindrome(int *cnt)
    {
        int how_many = 0;
        for(int i = 0; i < 10; i++)
        {
            if(cnt[i] & 1) how_many++;
        }
        if(how_many <= 1) return true;
        return false;
    }

    
};
//3311 2 113