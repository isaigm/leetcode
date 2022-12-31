// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        int rows = m;
        int cols = n;
        int dp[rows][cols];
        dp[0][0] = 1;
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(i != 0 || j != 0)
                {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    bool has_left = false;
                    bool has_up = false;
                    if(j - 1 >= 0)
                    {
                        left = dp[i][j - 1];
                        has_left = true;
                    }
                    if(i - 1 >= 0)
                    {
                        up = dp[i - 1][j];
                        has_up = true;
                    }
                    if(has_left && has_up)
                    {
                        dp[i][j] = left + up;
                    }else if(has_left)
                    {
                        dp[i][j] = left;
                    }else if(has_up)
                    {
                        dp[i][j] = up;
                    }
                    
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};


    