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
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            int first = -1;
            int last = -1;
            for(int i = 0; i < s; i++)
            {
                auto n = q.front();
                q.pop();
                if(n != nullptr)
                {
                    if(first == -1)
                    {
                        first = i;
                    }
                    last = i;
                    q.push(n->left);
                    q.push(n->right);
                    
                }
            }
            if(first != -1 && last != -1)
            {
                ans = std::max(ans, last - first + 1);
            }
        }
        return ans;
    }
};