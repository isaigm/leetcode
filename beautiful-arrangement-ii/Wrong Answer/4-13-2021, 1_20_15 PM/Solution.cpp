// https://leetcode.com/problems/beautiful-arrangement-ii

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        std::vector<int> ans;
        ans.push_back(1);
        for(int i = 2; i < k + 2; i++)
        {
            ans.push_back(ans.back() + i);
        }
        int last_value = ans.back();
        for(int i = k + 1;  i < n; i++)
        {
            ans.push_back(++last_value);
        }
        return ans;
    }
};