// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        int a_size = 0;
        int b_size = 0;
        ListNode *ans = nullptr;
        ListNode *cursorA = headA;
        ListNode *cursorB = headB;
        while(cursorA != nullptr)
        {
            cursorA = cursorA->next;
            a_size++;
            
        }
        while(cursorB != nullptr)
        {
            cursorB = cursorB->next;
            b_size++;
        }
        cursorA = headA;
        cursorB = headB;
        int diff = 0;
        if(a_size >= b_size)
        {
            for(int i = 0; i < a_size - b_size; i++)
            {
                cursorA = cursorA->next;
            }
        }else{
            
            for(int i = 0; i < b_size - a_size; i++)
            {
                cursorB = cursorB->next;
            }
        }
        while(cursorA != cursorB)
        {
            cursorA = cursorA->next;
            cursorB = cursorB->next;
        }
        ans = cursorA;
        return ans;
            
    }
};