// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree

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
void dfs(TreeNode *root, std::set<int> &table)
{
    if(root)
    {
        
        table.insert(root->val);
        if(root->left != nullptr)
        {
            root->left->val = 2 * root->val + 1;
        }
        if(root->right != nullptr)
        {
            root->right->val = 2 * root->val + 2;
        }
        dfs(root->left, table);
        dfs(root->right, table);
    }
}
class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        ::dfs(root, table);
    }
    
    bool find(int target) {
        return table.find(target) != table.end();
    }
    std::set<int> table;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */