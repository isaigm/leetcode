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
    void util(TreeNode *root, std::vector<int> &vec)
    {
        if(root != nullptr)
        {
            util(root->left, vec);
            vec.push_back(root->val);
            util(root->right, vec);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        std::vector<int> vec;
        util(root, vec);
        for(int i = 1; i < vec.size(); i++)
        {
            ans = std::min(ans, std::abs(vec[i] - vec[i - 1]));
        }
        return ans;
    }
};