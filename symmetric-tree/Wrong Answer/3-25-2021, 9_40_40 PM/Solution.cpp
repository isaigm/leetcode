// https://leetcode.com/problems/symmetric-tree

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
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            std::vector<int> level;
            for(int i = 0; i < s; i++)
            {
                auto n = q.front();
                q.pop();
                level.push_back(n->val);
                if(n->left)
                {
                    q.push(n->left);
                }
                if(n->right)
                {
                    q.push(n->right);
                }
            }
            for(int i = 0, j = s - 1; i <= j; i++, j--){
                if(level[i] != level[j]) return false;
            } 
            
        }
        return true;
    }
};