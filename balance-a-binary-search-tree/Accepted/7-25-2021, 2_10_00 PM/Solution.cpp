// https://leetcode.com/problems/balance-a-binary-search-tree

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
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> nodes;
        std::set<int> seen;
        inorder(root, nodes);
        TreeNode *ans = nullptr;
        gen(&ans, nodes, seen, 0, nodes.size() - 1);
        return ans;
    }
    void inorder(TreeNode *root, std::vector<int> &nodes)
    {
        if(root)
        {
            inorder(root->left, nodes);
            nodes.push_back(root->val);
            inorder(root->right, nodes);
        }
    }
    void gen(TreeNode **root, std::vector<int> &nodes, std::set<int> &seen, int left, int right)
    {
        if(left < right)
        {
            int mid = left + (right - left) / 2;
            *root = new TreeNode(nodes[mid]);
            seen.insert(nodes[mid]);
            gen(&((*root)->left), nodes, seen, left, mid);
            gen(&((*root)->right), nodes, seen, mid + 1, right);
        }else if(left == right && seen.find(nodes[left]) == seen.end())
        {
            *root = new TreeNode(nodes[left]);
            seen.insert(nodes[left]);
        }
    }
};