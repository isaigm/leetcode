// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        std::map<int, int> c_cols;
        std::map<int, int> c_rows;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j])
                {
                    c_rows[i]++;
                    c_cols[j]++;
                }
            }
        }
        for(const auto [x, n]: c_rows){
            if(n > 1) ans += n;
        }
        for(const auto [x, n]: c_cols){
            if(n > 1) ans += n;
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] && (c_rows[i] > 1 && c_cols[j] > 1))
                {
                    ans--;
                }
            }
        }
        return ans;
        
    }
};