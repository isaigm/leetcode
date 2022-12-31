// https://leetcode.com/problems/next-greater-node-in-linked-list

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
    vector<int> nextLargerNodes(ListNode* head) {
        std::stack<int> st;
        auto curr = head;
        while(curr != nullptr){
            st.push(curr->val);
            curr = curr->next;
        }
        std::vector<int> ans(st.size(), 0);
        ans[ans.size() - 1] = st.top();
        int last = st.top();
        st.pop();
        for(int i = ans.size() - 2; i >= 0; i--)
        {
            auto next = st.top();
            st.pop();
            if(next < last)
            {
                ans[i] = last;
            }else if(next < ans[i + 1])
            {
                ans[i] = ans[i + 1];
            }else {
                ans[i] = 0;
                for(int j = i; j < ans.size(); j++)
                {
                    if(next < ans[j])
                    {
                        ans[i] = ans[j];
                        break;
                    }
                }
            }
            last = next;
        
        }
        ans[ans.size() - 1] = 0;
        return ans;
    }
};