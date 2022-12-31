// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

/*
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return findTargetCopy(cloned, target);
    }
    TreeNode *findTargetCopy(TreeNode *cursor, TreeNode *target)
    {
        TreeNode *node = NULL;
        if(cursor != NULL)
        {
            if(cursor->val == target->val)
            {
                int l1 = cursor->left == NULL ? 0 : cursor->left->val;
                int r1 = cursor->right == NULL ? 0 : cursor->right->val;
                int l2 = target->left == NULL ? 0 : target->left->val;
                int r2 = target->right == NULL ? 0 : target->right->val;
                if(l1 == l2 && r1 == r2)
                {
                    return cursor;
                }
            }
            node = findTargetCopy(cursor->left, target);
            if(node != NULL) return node;
            node = findTargetCopy(cursor->right, target);
            if(node != NULL) return node;
          
        }
        return node;
    }
};