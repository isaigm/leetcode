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
    int how_much_left;
};
class Comparator{
  public:
    bool operator() (info &inf1, info &inf2)
    {
        if(inf1.level == inf2.level)
        {
            return inf1.how_much_left > inf2.how_much_left;
        }
        return inf1.level > inf2.level;
    } 
};
class Solution {
public:
    void util(TreeNode *root, int level, std::priority_queue<info, std::vector<info>, Comparator> &max_heap, int how_much_left)
    {
       if(root != nullptr)
       {
           if(root->left == nullptr && root->right == nullptr)
           {
               max_heap.push({level, root->val, how_much_left});
               if(max_heap.size() > 1)
               {
                   max_heap.pop();
               }
           }
           util(root->left, level + 1,max_heap, how_much_left + 1);
           util(root->right, level + 1, max_heap, how_much_left - 1);
       }
    }
    int findBottomLeftValue(TreeNode* root) {
        std::priority_queue<info, std::vector<info>, Comparator> max_heap;
        util(root, 0, max_heap, 0);
        return max_heap.top().val;
    }
};