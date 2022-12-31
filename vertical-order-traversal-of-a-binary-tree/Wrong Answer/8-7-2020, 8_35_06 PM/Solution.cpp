// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
       std::map<int, std::vector<int>> nodes;
       aux(nodes, root, 0, 0);
       std::vector<std::vector<int>> res;
       for(const auto &it: nodes){
           res.push_back(it.second);
       }
       return res;
   }
   void aux(std::map<int, std::vector<int>> &nodes, TreeNode *root, int x, int y){
       if(root != NULL){
           nodes[x].push_back(root->val);
           aux(nodes, root->left, x - 1, y - 1);
           aux(nodes, root->right, x + 1, y - 1);
       }
   }
};