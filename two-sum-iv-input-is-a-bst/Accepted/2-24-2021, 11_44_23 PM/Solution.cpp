// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    bool findTarget(TreeNode* root, int k) {
        std::set<int> s;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto n = q.front();
            q.pop();
            if (s.find(k - n->val) != s.end())
                return true;
            s.insert(n->val);
            if (n->left != nullptr)
            {
                q.push(n->left);
            }
            if (n->right != nullptr)
            {
                q.push(n->right);
            }
        }
        return false;
    }
};