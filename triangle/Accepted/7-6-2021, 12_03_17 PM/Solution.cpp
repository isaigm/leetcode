// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        for(int i = 1; i < triangle.size(); i++)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                if(j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j]; 
                }else if(j == triangle[i].size() - 1)
                {
                    
                    triangle[i][j] += triangle[i - 1][j - 1];
                }else
                {
                    triangle[i][j] += std::min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }
        for(int i = 0; i < triangle[triangle.size() - 1].size(); i++)
        {
            ans = std::min(ans, triangle[triangle.size() - 1][i]);
        }
        return ans;
    }
};