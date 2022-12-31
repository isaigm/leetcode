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
#include <algorithm>
class Solution {
public:
     std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
       std::map<int, std::vector<std::pair<int, int>>> nodes;
       aux(nodes, root, 0, 0);
       std::vector<std::vector<int>> res;
       for(auto &it: nodes){
           std::sort(it.second.begin(), it.second.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
                  return (p1.first < p2.second) || (p1.first == p2.first) && (p1.second < p2.second);
           });
           std::vector<int> col;
           for(const auto &e: it.second){
               col.push_back(e.second);
           }
           res.push_back(col);
       }
       return res;
   }
   void aux(std::map<int, std::vector<std::pair<int, int>>> &nodes, TreeNode *root, int x, int y){
       if(root != NULL){
           nodes[x].push_back({y, root->val});
           aux(nodes, root->left, x - 1, y + 1);
           aux(nodes, root->right, x + 1, y + 1);
       }
   }
};