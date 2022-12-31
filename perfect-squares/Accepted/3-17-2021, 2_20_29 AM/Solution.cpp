// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    bool is_sqr(long n) {
        long root = sqrt(n);
        return root * root == n;
    }
    int numSquares(int n) {
        int m = INT_MAX;
        int dp[n];
        for(int i = 0; i < n; i++)
        {
            dp[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            if(is_sqr(i + 1))
            {
                dp[i] = 1;
            }else
            {
                for(int j = 0; j < i; j++)
                {
                    if(dp[j] == 1)
                    {
                        m = std::min(m, 1 + dp[i - j - 1]);
                    }
                }
                dp[i] = m;
                m = INT_MAX;
            }
        }
        return dp[n - 1];
    }
};