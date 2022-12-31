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
struct info{
    int level;
    int val;
    bool side;
};
class Comparator{
  public:
    bool operator() (info &inf1, info &inf2)
    {
        if(inf1.level == inf2.level)
        {
            if(!inf1.side && !inf2.side) return false;
            if(inf1.side && inf2.side)   return false;
            if(inf1.side && !inf2.side)  return true;
            if(!inf1.side && inf2.side)  return false;
        }
        return inf1.level > inf2.level;
    } 
};
class Solution {
public:
    void util(TreeNode *root, int level, std::priority_queue<info, std::vector<info>, Comparator> &max_heap, bool side)
    {
       if(root != nullptr)
       {
           if(root->left == nullptr && root->right == nullptr)
           {
               max_heap.push({level, root->val, side});
               if(max_heap.size() > 1)
               {
                   max_heap.pop();
               }
           }
           util(root->left, level + 1, max_heap, true);
           util(root->right, level + 1, max_heap, false);
       }
    }
    int findBottomLeftValue(TreeNode* root) {
        std::priority_queue<info, std::vector<info>, Comparator> max_heap;
        util(root, 0, max_heap, true);
        return max_heap.top().val;
    }
};