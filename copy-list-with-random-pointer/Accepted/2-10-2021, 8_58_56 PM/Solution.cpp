// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        std::map<Node *, int> nodes;
        std::map<int, Node*> inv_nodes;
        Node *new_list = new Node(head->val);
        Node *last = new_list;
        Node *ptr = head;
        for(int i = 0; ptr != nullptr; i++)
        {
            inv_nodes[i] = last;
            if(ptr->next != nullptr)
            {
                Node *next = new Node(ptr->next->val);
                last->next = next;
                last = next;
            }else{
                last->next = nullptr;
            }
            nodes[ptr] = i;
            ptr = ptr->next;
        }
        ptr = head;
        last = new_list;
        while(ptr != nullptr)
        {
            if(ptr->random != nullptr)
            {
                int idx = nodes[ptr->random];
                last->random = inv_nodes[idx];
            }
            ptr = ptr->next;
            last = last->next;
        }
        return new_list;
    }
};