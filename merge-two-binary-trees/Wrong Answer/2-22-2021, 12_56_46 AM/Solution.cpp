// https://leetcode.com/problems/merge-two-binary-trees

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
    void util(TreeNode* root1, TreeNode* root2, TreeNode **new_root){
        if(root1 == nullptr && root2 == nullptr) return;
        if(root1 != nullptr && root2 != nullptr)
        {
            *new_root = new TreeNode;
            (*new_root)->val = root1->val + root2->val;
            util(root1->left, root2->left, &((*new_root)->left));
            util(root1->right, root2->right, &((*new_root)->right));
        }
        if(root1 != nullptr && root2 == nullptr)
        {
            *new_root = new TreeNode(root1->val);
        }
        if(root1 == nullptr && root2 != nullptr)
        {
            *new_root = new TreeNode(root2->val);
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 != nullptr) return root2;
        if(root1 != nullptr && root2 == nullptr) return root1;
        if(root1 == nullptr && root2 == nullptr) return nullptr;
        TreeNode *new_root = nullptr;
        util(root1, root2, &new_root);
        return new_root;
    }
};