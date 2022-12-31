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
        std::vector<int> squares;
        for(int i = 0; i < n; i++)
        {
            int k = i + 1;
            if(is_sqr(k))
            {
                dp[i] = 1;
                squares.push_back(k);
            }else
            {
                for(int j = 0; j < squares.size() && squares[j] < k; j++)
                {
                    m = std::min(m, 1 + dp[k - squares[j] - 1]);
                }
            
                dp[i] = m;
                m = INT_MAX;
            }
        }
        return dp[n - 1];
    }
};