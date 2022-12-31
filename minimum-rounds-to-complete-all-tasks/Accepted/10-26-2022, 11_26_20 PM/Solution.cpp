// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

#define inf (1 << 31)
class Solution {
public:
    uint64_t dp[100000 + 1];
    Solution()
    {
       for (int i = 0; i <= 100000; i++)
        {
            dp[i] = inf;
        }
        dp[2] = 1;
        dp[3] = 1;
    }
int get_min(int n)
{
    if (dp[n] != inf) return dp[n];
    for (int i = 4; i <= n; i++)
    {
        dp[i] = 1 + std::min(dp[i - 2], dp[i - 3]);
    }
    return dp[n];
}
int minimumRounds(std::vector<int>& tasks) {
    std::map<int, int> counter;
   
    for (auto &t : tasks)
    {
        counter[t]++;
    }
   
    int rounds = 0;
    for (auto& p : counter)
    {
        if (p.second == 1) return -1;
        rounds += get_min(p.second);
    }
    return rounds;
}
};