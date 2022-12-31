// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        for(int i = 0; i < 10000; i++)
        {
            computed[i] = false;
        }
        std::sort(coins.begin(), coins.end());
        int ans = solve(coins, amount);
        if(ans > 100000) return -1;
        return ans;
    }
    int solve(vector<int>& coins, int amount)
    {
        if(amount < 0) return INT_MAX - 10000;
        if(amount == 0) return 0;
        if(computed[amount]) return dp[amount];
        int best = INT_MAX - 10000;
        for(int &x: coins)
        {
            best = std::min(best, solve(coins, amount - x) + 1);
        }
       
        computed[amount] = true;
        dp[amount] = best;
        return best;
    }
    bool computed[10001];
    int dp[10001];
    
};