// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        std::sort(nums.begin(), nums.end());
        int ans = 1;
        int last_element = nums[0];
        int curr_len = 1;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == last_element) continue;
            if(nums[i] == last_element + 1)
            {
                curr_len++;
            }else
            {
                curr_len = 1;
            }
            ans = std::max(ans, curr_len);
            last_element = nums[i];
        }
        
        return ans;
    }
};