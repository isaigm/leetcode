// https://leetcode.com/problems/leaf-similar-trees

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leaves1;
        std::vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);
        if(leaves1.size() != leaves2.size()) return false;
        for(size_t i = 0; i < leaves1.size(); i++)
        {
            if(leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
    void dfs(TreeNode *root, std::vector<int> &leaves)
    {
        if(root)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                leaves.push_back(root->val);
            }
            dfs(root->left, leaves);
            dfs(root->right, leaves);
        }
    }
};