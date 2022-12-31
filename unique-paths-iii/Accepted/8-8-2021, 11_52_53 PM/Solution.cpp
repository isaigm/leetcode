// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:
   //cr -> current row
//cc -> current column
//er -> ending row
//ec -> ending column
void back(std::vector<std::vector<int>> &grid, int &ans, int &path_len, int empty_cells, int cr, int cc)

{
 
    //x, y                                   down     up       right   left
    std::vector<std::vector<int>> neighbours{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (const auto &n : neighbours)
    {
        int c = cc + n[0];
        int r = cr + n[1];
        if (r < grid.size() && r >= 0 && c < grid[0].size() && c >= 0)
        {
            if(grid[r][c] == 2 && path_len == empty_cells )
            {
               
                ans++;
                return;
               
            }
            else if (grid[r][c] == 0)
            {
                  
                grid[r][c] = -1;
                path_len++;
                back(grid, ans, path_len, empty_cells, r, c);
                grid[r][c] = 0;
                path_len--;
            }
        }
    }
}
int uniquePathsIII(std::vector<std::vector<int>> &grid)
{
    int empty_cells = 0;
    int sr, sc;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 0)
            {
                empty_cells++;
            }else if(grid[i][j] == 1)
            {
                sr = i;
                sc = j;
            }
        }
    }
    
    int ans = 0;
    int path_len = 0;
    back(grid, ans, path_len, empty_cells, sr, sc);
    return ans;
}
};