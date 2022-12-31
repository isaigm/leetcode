// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int dp[rows][cols];
        dp[0][0] = 1;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(i != 0 || j != 0)
                {
                    if(obstacleGrid[i][j] != 1)
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
                    }else dp[i][j] = 0;
                    
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};