// https://leetcode.com/problems/find-bottom-left-tree-value

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
class Comparator{
  public:
    bool operator() (std::pair<int, int> &p1, std::pair<int, int> &p2)
    {
        return p1.first > p2.first;
    } 
};
class Solution {
public:
    void util(TreeNode *root, int level, bool is_left, std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>>, Comparator> &max_heap)
    {
       if(root != nullptr)
       {
           if(root->left == nullptr && root->right == nullptr && is_left)
           {
               max_heap.push({level, root->val});
               if(max_heap.size() > 1)
               {
                   max_heap.pop();
               }
           }
           util(root->left, level + 1, true, max_heap);
           util(root->right, level + 1, false, max_heap);
       }
    }
    int findBottomLeftValue(TreeNode* root) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>>, Comparator> max_heap;
        util(root, 0, true, max_heap);
        auto [_, ans] = max_heap.top();
        
        return ans;
    }
};