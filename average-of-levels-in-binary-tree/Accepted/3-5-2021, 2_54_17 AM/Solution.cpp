// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ans;
        if(root == nullptr) return ans;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            double sum = 0;
            for(int i = 0; i < s; i++)
            {
                auto n = q.front();
                q.pop();
                sum += n->val;
                if(n->left != nullptr)
                {
                    q.push(n->left);
                }
                if(n->right != nullptr)
                {
                    q.push(n->right);
                }
            }
            ans.push_back(sum / s);
        }
        return ans;
    }
};