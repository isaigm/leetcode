// https://leetcode.com/problems/linked-list-in-binary-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool ans = false;
        dfs(ans, root, head);
        return ans;
    }
    void dfs(bool &ans, TreeNode *root, ListNode *head)
    {
        if(root != nullptr)
        {
            if(root->val == head->val)
            {
                util(ans, root, head);
                if(ans) return;
            }
            dfs(ans, root->left, head);
            dfs(ans, root->right, head);
        }
    }
    void util(bool &ans, TreeNode *root, ListNode*head)
    {
        if(root != nullptr)
        {
            if(root->val == head->val)
            {
                
                if(head->next == nullptr)
                {
                    ans = true;
                }else
                {
                    util(ans, root->left, head->next);
                    if(!ans) util(ans, root->right, head->next);
                }
            }
        }
    }
};