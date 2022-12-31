// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    void util(TreeNode *root, std::priority_queue<int, std::vector<int>, std::greater<int>> &min_heap)
    {
        if(root != nullptr)
        {
            min_heap.push(root->val);
            if(min_heap.size() > 2)
            {
                min_heap.pop();
            }
            util(root->left, min_heap);
            util(root->right, min_heap);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        util(root, min_heap);
        int first = min_heap.top();
        min_heap.pop();
        int second = min_heap.top();
        return std::abs(second - first);
    }
};