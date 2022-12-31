// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::vector<int> ans(2);
        std::unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for(int i = 1; i <= nums.size(); i++)
        {
            if(m[i] == 2)
            {
                ans[0] = i;
            }
            if(m[i] == 0)
            {
                ans[1] = i;
            }
        }
        return ans;
    }
};