// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};