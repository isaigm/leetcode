// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
        std::map<int, int> dp;
        return helper(dp, n) - 1;
    }
    uint64_t helper(std::map<int, int> &dp, uint64_t n)
    {
        if(dp.find(n) != dp.end())
        {
            return dp[n];
        }
        int ans;
        if(n == 1) 
        {
            ans = 1;
        }
        else if(n % 2 == 0)
        {
            ans =  1 + helper(dp, n / 2);
        }else{
      
            ans = 1 + std::min(helper(dp, n + 1), helper(dp, n - 1));
        }
        dp[n] = ans;
        return ans;
    }
};