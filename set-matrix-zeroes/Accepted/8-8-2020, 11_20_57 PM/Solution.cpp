// https://leetcode.com/problems/set-matrix-zeroes

class Solution{
   public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
    auto r = matrix.size();
    auto c = matrix[0].size();
    std::vector<std::pair<int, int>> zeroes;
    std::unordered_map<int, int> rows;
    std::unordered_map<int, int> cols;
    for(size_t i = 0; i < r; i++){
        for(size_t j = 0; j < c; j++){
            if(matrix[i][j] == 0) zeroes.push_back({i, j});
        }
    }
    for(const auto &it: zeroes){
        auto [row, col] = it;
        if(rows[row] == 0){
            for(size_t i = 0; i < c; i++){
                matrix[row][i] = 0;
            }
            rows[row]++;
        }
        if(cols[col] == 0){
            for(size_t i = 0; i < r; i++){
                matrix[i][col] = 0;
            }
            cols[col]++;
        }
    }
}
    
    
    
};