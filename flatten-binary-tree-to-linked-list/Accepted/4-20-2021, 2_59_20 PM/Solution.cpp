// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void flatten(TreeNode* root) {
        auto cursor = root;
        std::vector<int> nodes;
        dfs(root, nodes);
        for(size_t i = 0; i < nodes.size(); i++)
        {
            cursor->val = nodes[i];
            cursor->left = nullptr;
            if(cursor->right == nullptr && i < nodes.size() - 1)
            {
                cursor->right = new TreeNode();
            }
            cursor = cursor->right;    
        }
        
    }
    void dfs(TreeNode *root, std::vector<int> &nodes)   
    {
        if(root)
        {
            nodes.push_back(root->val);
            dfs(root->left, nodes);
            dfs(root->right, nodes);
        }
    }
};