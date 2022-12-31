// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

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
  TreeNode* sortedListToBST(ListNode* head) {
    std::vector<int> nodes;
    auto cursor = head;
    while (cursor)
    {
        nodes.push_back(cursor->val);
        cursor = cursor->next;
    }
    TreeNode *res = nullptr;
    createTree(&res, nodes, 0, nodes.size());
    return res;
}
void createTree(TreeNode** node, std::vector<int> &nodes, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        *node = new TreeNode(nodes[mid]);

        createTree(&((*node)->left), nodes, left, mid);
        createTree(&((*node)->right), nodes, mid + 1, right);
    }
}
};