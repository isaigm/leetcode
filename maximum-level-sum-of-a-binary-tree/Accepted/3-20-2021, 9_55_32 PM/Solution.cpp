// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> q;
        int ans = INT_MIN;
        int curr_level = 1;
        int level = 1;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            int sum = 0;
            for(int i = 0; i < s; i++)
            {
                auto curr_node = q.front();
                sum += curr_node->val;
                q.pop();
                if(curr_node->left != nullptr)
                {
                    q.push(curr_node->left);
                }
                if(curr_node->right != nullptr)
                {
                    q.push(curr_node->right);
                }
            }
            if(ans < sum)
            {
                ans = sum;
                level = curr_level;
            }
            curr_level++;
        }
     
        return level;
    }
};