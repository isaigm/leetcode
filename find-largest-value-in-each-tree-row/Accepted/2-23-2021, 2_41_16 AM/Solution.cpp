// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    std::vector<int> largestValues(TreeNode *root)
    {
    std::vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        std::queue<std::pair<int, TreeNode *>> q;
        q.push({0, root});
        int last_level = 0;
        int last_max = INT_MIN;
        while (!q.empty())
        {
            auto node = q.front();
            if(last_level == node.first){
                last_max = std::max(node.second->val, last_max);
            }else{
                ans.push_back(last_max);
                last_max = node.second->val;
                last_level = node.first;
            }

            q.pop();
            if (node.second->left != nullptr)
            {
                q.push({node.first + 1, node.second->left});
               
            }
            if (node.second->right != nullptr)
            {
                q.push({node.first + 1, node.second->right});
            }
            if(q.size() == 0)
            {
                ans.push_back(std::max(node.second->val, last_max));
            }
        }

        return ans;
    }
};