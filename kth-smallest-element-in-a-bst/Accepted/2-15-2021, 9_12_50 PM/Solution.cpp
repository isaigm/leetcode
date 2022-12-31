// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    void util(TreeNode *root, int k,  std::priority_queue<int, std::vector<int>, std::greater<int>> &max_heap){
        if(root != nullptr)
        {
            max_heap.push(root->val);
            util(root->left, k, max_heap);
            util(root->right, k, max_heap);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> max_heap;
        util(root, k, max_heap);
        while(--k){
            max_heap.pop();
        }
        return max_heap.top();
    }
};