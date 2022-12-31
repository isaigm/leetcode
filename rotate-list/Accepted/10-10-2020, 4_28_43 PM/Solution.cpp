// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        std::vector<ListNode *> nodes;
        auto curr = head;
        while(curr != nullptr)
        {
            nodes.push_back(curr);
            curr = curr->next;
        }
        std::vector<ListNode *> tmp(nodes.size());
        for(int i = 0; i < tmp.size(); i++){
            tmp[(i + k) % tmp.size()] = nodes[i];
        }
        for(int i = 0; i < tmp.size() - 1; i++){
           tmp[i]->next = tmp[i + 1];
        }
        tmp[tmp.size() - 1]->next = nullptr;
        return tmp[0];  
    }
};