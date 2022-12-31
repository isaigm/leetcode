// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        std::map<int, int> c_cols;
        std::map<int, int> c_rows;
        int ans = 0;
        auto count_neighbours = [](vector<vector<int>>& grid, int i, int j)
        {
            int n = 0;
            if(i - 1 >= 0) n += grid[i - 1][j];
            if(i + 1 < grid.size()) n += grid[i + 1][j];
            if(j - 1 >= 0) n += grid[i][j - 1];
            if(j + 1 < grid[0].size()) n += grid[i][j + 1];
            return n;
        };
        int isolated = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j])
                {
                    if(count_neighbours(grid, i, j) == 0) isolated++;
                    ans++;
                }
            }
        }
      
        return ans - isolated;
        
    }
};