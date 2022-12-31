// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    void util(TreeNode *root, uint32_t &sum, uint32_t &path)
{
    if (root != nullptr)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            path <<= 1;
            path |= root->val;
            sum += path;
            path >>= 1;
        }
        else
        {
            path <<= 1;
            path |= root->val;
            util(root->left, sum, path);
            util(root->right, sum, path);
            path >>= 1;
        }
    }
}
int sumRootToLeaf(TreeNode *root)
{
    uint32_t sum = 0;
    uint32_t path = 0;
    util(root, sum, path);
    return sum;
}
};