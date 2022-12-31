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
    void helper(TreeNode *root, std::vector<int> &path, int &cnt)
    {
        if(root == nullptr) return;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            if(is_palindrome(path)) cnt++;
        }else
        {
            helper(root->left, path, cnt);
            helper(root->right, path, cnt);
        }
        path.pop_back();
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        std::vector<int> path;
        helper(root, path, cnt);
        return cnt;
    }
    bool is_palindrome(std::vector<int> &path)
    {
        std::map<int, int> cnt;
        for(auto &val: path)
        {
            cnt[val]++;
        }
        int how_many = 0;
        for(auto &n: cnt)
        {
            if(n.second & 1) how_many++;
        }
        if(how_many <= 1) return true;
        return false;
    }

    
};
//3311 2 113