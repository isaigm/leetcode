// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        std::set<int> numss;
        int ans = 1;
        for(const auto &x: nums)
        {
            numss.insert(x);
        }
        for(auto x: nums)
        {
            int curr_len = 1;
            while(numss.find(x + 1) != numss.end())
            {
                x++;
                curr_len++;
            }
            ans = std::max(ans, curr_len);
        }
        return ans;
       
    }
};