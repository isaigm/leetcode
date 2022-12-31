// https://leetcode.com/problems/beautiful-arrangement-ii

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        std::vector<int> ans;
        int temp = k + 1;
        int temp2 = 1;
        for(int i = 1; i < k + 2; i++)
        {
            if(i % 2)
            {
                ans.push_back(temp2++);
            }else
            {
                ans.push_back(temp--);
            }
        }
        int last_value = ans.back();
        for(int i = k + 2;  i <= n; i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};