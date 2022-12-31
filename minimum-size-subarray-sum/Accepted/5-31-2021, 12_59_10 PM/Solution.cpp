// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        std::vector<int> prefix_sum(nums.size());
        int ans = INT_MAX;
        prefix_sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)   
        {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                int sum = prefix_sum[j] - prefix_sum[i] + nums[i];
                if(sum >= target)
                {
                    ans = std::min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};