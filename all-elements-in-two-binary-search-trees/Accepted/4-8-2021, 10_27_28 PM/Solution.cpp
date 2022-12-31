// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> ans;
        if(root1 == nullptr && root2 == nullptr) return ans;
        dfs(root1, ans);
        int l1 = 0;
        int r1 = ans.size() - 1;
        dfs(root2, ans);
        int l2 = r1 + 1;
        int r2 = ans.size() - 1;
        if(r1 > -1 && l2 > 0)
        {
            merge(l1, r1, l2, r2, ans);
        }
        return ans;
    }
    void dfs(TreeNode *root, std::vector<int> &ans)
    {
        if(root)
        {
            dfs(root->left, ans);
            ans.push_back(root->val);
            dfs(root->right, ans);
        }
    }
    void merge(int l1, int r1, int l2, int r2, std::vector<int> &v)
{
    std::vector<int> sorted;
    int temp = l1;
    while (l1 < r1 + 1 && l2 < r2 + 1)
    {
        if (v[l1] < v[l2])
        {
            sorted.push_back(v[l1]);
            l1++;
        }
        else
        {
            sorted.push_back(v[l2]);
            l2++;
        }
    }
    if (l1 == r1 + 1)
    {
        for (int i = l2; i <= r2; i++)
        {
            sorted.push_back(v[i]);
        }
    }
    else if (l2 == r2 + 1)
    {
        for (int i = l1; i <= r1; i++)
        {
            sorted.push_back(v[i]);
        }
    }
    for (int i = temp, j = 0; i <= r2; i++, j++)
    {
        v[i] = sorted[j];
    }
}
};