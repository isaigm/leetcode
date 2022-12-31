// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        int len = 0;
        ListNode *ptr = head;
        while(ptr != nullptr){
            len++;
            ptr = ptr->next;
        }
        len--;
        ptr = head;
        int i = 0;
        while(ptr != nullptr){
            result += ptr->val * pow(2, len - i);
            i++;
            ptr = ptr->next;
        }
        return result;
    }
};