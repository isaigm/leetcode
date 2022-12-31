// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
        return nullptr;
    ListNode *last_node = head;
    ListNode *it = head;
    ListNode *ans = head;
    int last_value = INT32_MIN;
    while (it != nullptr)
    {
        if(it->val == last_value)
        {
            last_node->next = it->next;
            delete it;       
            it = last_node->next;
        }else{
            last_value = it->val;
            last_node = it;
            it = it->next;
        }
       
     // 1 2 2 3
    }
    return ans;

        
    }
};