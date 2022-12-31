// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
   void util(TreeNode *root, std::map<int, std::vector<int>> &tab, int level)
    {
        if (root != nullptr)
        {
            tab[level].push_back(root->val);
            util(root->left, tab, level + 1);
            util(root->right, tab, level + 1);
        }
    }
    std::vector<int> largestValues(TreeNode *root)
    {
        std::vector<int> ans;
        std::map<int, std::vector<int>> tab;
        util(root, tab, 0);
        for(auto it = tab.begin(); it != tab.end(); it++)
        {
            auto m = std::max_element(it->second.begin(), it->second.end());
            ans.push_back(*m);
           
        }
        return ans;
    }
};