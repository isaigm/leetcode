// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         std::map<ListNode*, bool> visited;
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        if (visited[ptr])
        {
            return true;
        }
        else
        {
            visited[ptr] = true;
        }
        ptr = ptr->next;
    }
    return false;
    }
};