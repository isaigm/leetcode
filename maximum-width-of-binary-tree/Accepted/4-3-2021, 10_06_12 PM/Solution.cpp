// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int s = q.size();
            int start = q.front().second;
            int end = q.back().second;
            ans = std::max(ans, end - start + 1);
            for(int i = 0; i < s; i++)
            {
                auto n = q.front();
                int idx = q.front().second - start;
                q.pop();
                if(n.first->left)
                {
                    q.push({n.first->left, 2*idx + 1});
                }
                if(n.first->right)
                {
                    q.push({n.first->right, 2*idx + 2});
                }
            }

        }
        return ans;
    }
};