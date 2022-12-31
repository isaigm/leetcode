// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    int minDiffInBST(TreeNode* root) {
        std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
        dfs(root, max_heap);
        int n1 = max_heap.top();
        max_heap.pop();
        int n2 = max_heap.top();
        return std::abs(n1 - n2);
    }
    void dfs(TreeNode *root, std::priority_queue<int, std::vector<int>, std::less<int>> &max_heap)
    {
        if(root)
        {
            max_heap.push(root->val);
            if(max_heap.size() > 2)
            {
                max_heap.pop();
            }
            dfs(root->left, max_heap);
            dfs(root->right, max_heap);
        }
    }
};