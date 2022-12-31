// https://leetcode.com/problems/even-odd-tree

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
    bool isEvenOddTree(TreeNode* root) {
        std::queue<TreeNode *> q;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            int last_value = -1;
            for(int i = 0; i < s; i++)
            {
                auto node = q.front();
                q.pop();
                if(last_value == node->val) return false;
                if(level % 2)
                {
                    if(node->val % 2) return false;
                    if(last_value != -1 && node->val > last_value) return false;
                }else
                {
                    if(node->val % 2 == 0) return false;
                    if(last_value != -1 && node->val < last_value) return false;
                }
                last_value = node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            level++;
        }
        return true;
    }
};