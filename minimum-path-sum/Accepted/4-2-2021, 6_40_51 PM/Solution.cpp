// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dp[rows][cols];
        dp[0][0] = grid[0][0];
        
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
                        dp[i][j] = std::min(left + grid[i][j], up + grid[i][j]);
                    }else if(has_left)
                    {
                        dp[i][j] = left + grid[i][j];
                    }else if(has_up)
                    {
                        dp[i][j] = up + grid[i][j];
                    }
                    
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
   
};