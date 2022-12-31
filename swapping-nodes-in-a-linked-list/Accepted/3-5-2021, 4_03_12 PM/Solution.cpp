// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *left = head;
        ListNode *right = nullptr;
        int size = 0;
        while(left != nullptr)
        {
            size++;
            left = left->next;
        }
        ListNode *cursor = head;
        left = nullptr;
        for(int i = 1; i <= size && !left || !right; i++)
        {
            if(i == k)
            {
                left = cursor;
            }
            if(i == size - k + 1)
            {
                right = cursor;
            }
            cursor = cursor->next;
        }
        std::swap(left->val, right->val);
        return head;
    }
};