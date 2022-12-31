// https://leetcode.com/problems/deepest-leaves-sum

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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;    
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            int ss = 0;
            for(int _ = 0; _ < s; _++)
            {
                auto n = q.front();
                ss += n->val;
                q.pop();
                if(n->left != nullptr)
                {
                    q.push(n->left);
                }
                if(n->right != nullptr)
                {
                    q.push(n->right);
                }
            }
            sum = ss;
        }
        return sum;
    }
};