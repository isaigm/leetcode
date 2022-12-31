// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
   int orangesRotting(std::vector<std::vector<int>>& grid) {
    auto rows = grid.size();
    auto cols = grid[0].size();
    int fresh = 0, t = 0;
    std::queue<std::pair<int, int>> nodes;
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            if(grid[i][j] == 2) nodes.push({i, j});
            else if(grid[i][j] == 1) fresh++;
        }
    }
    while (!nodes.empty()) {
        for(size_t i = 0; i < nodes.size(); i++){
            size_t x = nodes.front().first;
            size_t y = nodes.front().second;
            nodes.pop();
            if(x > 0 && grid[x - 1][y] == 1){
                grid[x - 1][y] = 2;
                fresh--;
                nodes.push({x - 1, y});
            }
            if(y > 0 && grid[x][y - 1] == 1){
                grid[x][y - 1] = 2;
                fresh--;
                nodes.push({x, y - 1});
            }
            if(x < rows - 1 && grid[x + 1][y] == 1){
                grid[x + 1][y] = 2;
                fresh--;
                nodes.push({x + 1, y});
            }
            if(y < cols - 1 && grid[x][y + 1] == 1){
                grid[x][y + 1] = 2;
                fresh--;
                nodes.push({x, y + 1});
            }
        }
        if(!nodes.empty()) t++;
    }
    if(fresh == 0) return t;
    return -1;
}
};