// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        std::vector<ListNode*> odd_nodes;
        std::vector<ListNode*> even_nodes;
        ListNode *cursor = head;
        for(int i = 1; cursor != nullptr; i++)
        {
            if(i % 2)
            {
                odd_nodes.push_back(cursor);
            }else{
                even_nodes.push_back(cursor);
            }
            cursor = cursor->next;
        }
        cursor = head;
        for(int i = 0; i < odd_nodes.size() - 1; i++)
        {
            cursor->next = odd_nodes[i + 1];
            cursor = cursor->next;
        }
        for(int i = 0; i < even_nodes.size(); i++)
        {
            cursor->next = even_nodes[i];
            cursor = cursor->next;
        }
        cursor->next = nullptr;
        return head;
    }
};