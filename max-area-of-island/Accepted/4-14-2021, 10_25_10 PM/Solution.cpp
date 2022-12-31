// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        std::map<std::pair<int, int>, bool> seen;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                max_area = std::max(max_area, area(seen, grid, i, j));
            }
        }
        return max_area;
    }
    int area(std::map<std::pair<int, int>, bool> &seen, vector<vector<int>>& grid, int i, int j)
    {
        int res = 0;
        if(!seen[{i, j}] && grid[i][j] == 1)
        {
            seen[{i, j}] = true;
            res++;
            if(i - 1 >= 0)
            {
                res += area(seen, grid, i - 1, j);
            }
            if(i + 1 < grid.size())
            {
                res += area(seen, grid, i + 1, j);
            }
            if(j - 1 >= 0)
            {
                res += area(seen, grid, i, j - 1);
            }
            if(j + 1 < grid[0].size())
            {
                res += area(seen, grid, i, j + 1);
            }
        }
        return res;
    }
};