// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        std::vector<int> zeroes;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zeroes.push_back(i);
            }
        }
    
        if(zeroes.size() == 0) return nums.size() - 1;
        for(const auto &z: zeroes)
        {
            int len = 0;
            if(z - 1 < 0)
            {
    
                for(int i = z + 1; i < nums.size() && nums[i] == 1; i++)
                {
                    len++;
                }
            }
            else if(z - 1 >= nums.size()){
                for(int i = z; i >= 0 && nums[i] == 1; i--)
                {
                    len++;
                }
            }else if(nums[z + 1] == 1 || nums[z - 1] == 1)
            {
                 for(int i = z + 1; i < nums.size() && nums[i] == 1; i++)
                {
                    len++;
                }
                 for(int i = z - 1; i >= 0 && nums[i] == 1; i--)
                {
                    len++;
                }
            }
            ans = std::max(ans, len);
        }
        return ans;
    }
};