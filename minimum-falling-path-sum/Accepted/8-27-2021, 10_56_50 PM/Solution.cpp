// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int dp[matrix.size()][matrix.size()];
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                if(i == 0){
                    dp[i][j] = matrix[i][j];
                }else if(j == matrix.size() - 1){
                    dp[i][j] = matrix[i][j] + std::min(dp[i - 1][j], dp[i - 1][j - 1]);
                }
                else if(j == 0)
                {
                    dp[i][j] = matrix[i][j] + std::min(dp[i - 1][j], dp[i - 1][j + 1]);
                }else
                {
                    dp[i][j] = matrix[i][j] + std::min({dp[i - 1][j], dp[i - 1][j + 1], dp[i - 1][j - 1]});
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++)
        {
            ans = std::min(ans, dp[matrix.size() - 1][i]);
        }
        return ans;
    }
};

