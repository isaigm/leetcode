// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int ans = 0;
        int zeroes = 0;
        int left_part = 0;
        int right_part = 0;
        int j;
        for(j = 0; j < nums.size() && nums[j] == 0; j++){
            
        }
        for(int i = j; i < nums.size(); i++)
        {
            int x = nums[i];
            if(x == 1)
            {
                if(zeroes == 0)
                {
                    left_part++;
                }else 
                {
                    right_part++;
                }
            }
            else if(x == 0)
            {
                if(zeroes == 1)
                {
                    ans = std::max(ans, left_part + right_part);
                   
                
                    int j;
                    int z = 0;
                    for(j = i; j < nums.size() && nums[j] == 0; j++){
                        z++;
                    }
                    if(z > 1)
                    {
                        left_part = 0;
                        i = j - 1;
                        zeroes = 0;
                    }else
                    {
                        left_part = right_part;
                      
                    }
                    right_part = 0;
                   
                }else zeroes++;
            }
        }
        ans = std::max(ans, left_part + right_part);
        if(ans == nums.size()) return ans - 1;
        return ans;
    }
};