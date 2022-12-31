// https://leetcode.com/problems/number-of-islands

class Solution {
public:
void helper(bool *visited, std::vector<std::vector<char>> &grid, int r1, int c1, int &r, int &c, int &total){
    if(!visited[r1 * c + c1] && grid[r1][c1] == '1'){
        visited[r1 * c + c1] = true;
        total--;
        if(r1 + 1 < r && grid[r1 + 1][c1] == '1'){
            helper(visited, grid, r1 + 1, c1, r, c, total);
        }
        if(r1 - 1 >= 0 && grid[r1 - 1][c1] == '1'){
            helper(visited, grid, r1 - 1, c1, r, c, total);
        }
        if(c1 + 1 < c && grid[r1][c1 + 1] == '1'){

            helper(visited, grid, r1, c1 + 1, r, c, total);

        }
        if(c1 - 1 >= 0 && grid[r1][c1 - 1] == '1'){
            helper(visited, grid, r1, c1 - 1, r, c, total);
        }
    }
}
int numIslands(std::vector<std::vector<char>>& grid) {
    bool *visited = new bool[grid.size() * grid[0].size()];
    int r = grid.size();
    int c = grid[0].size();
    int total = 0;
    int res = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            visited[i * c + j] = false;
            if(grid[i][j] == '1') total++;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!visited[i * c + j] && grid[i][j] != '0'){
                helper(visited, grid, i, j, r, c, total);
                res++;
            }
            if(total <= 0){
                delete [] visited;
                return res;
            }

        }
    }
    delete [] visited;
    return res;
}
};