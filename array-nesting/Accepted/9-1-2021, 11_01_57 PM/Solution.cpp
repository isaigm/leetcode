// https://leetcode.com/problems/array-nesting

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        int dp[nums.size()];
        for(int i = 0; i < nums.size(); i++)
        {
            dp[i] = 0;
        }
        for(int x = 0; x < nums.size(); x++)
        {
            if(dp[x] > 0) continue;
            std::vector<bool> seen(nums.size());
            std::vector<int> set;
            int k = x;

            int len = 0;
            while(!seen[k])
            {
                
                set.push_back(k);
                seen[k] = true;
                
                k = nums[k];
                len++;
            }
            for(const auto &n: set)
            {
                dp[n] = len;
            }
        }
        
        for(const auto &x: dp)
        {
            ans = std::max(x, ans);
        }
        return ans;
    }
};