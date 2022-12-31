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
        int size = max_heap.size();
        int min = INT_MAX;
        int last = 0;
        for(int i = 0; i < size; i++)
        {
            min = std::min(min, std::abs(last - max_heap.top()));
            last = max_heap.top();
            max_heap.pop();
        }
        return min;
    }
    void dfs(TreeNode *root, std::priority_queue<int, std::vector<int>, std::less<int>> &max_heap)
    {
        if(root)
        {
            max_heap.push(root->val);
            dfs(root->left, max_heap);
            dfs(root->right, max_heap);
        }
    }
};