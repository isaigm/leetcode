// https://leetcode.com/problems/set-matrix-zeroes

class Solution{
   public:
void setZeroes(std::vector<std::vector<int>>& matrix) {
    auto r = matrix.size();
    auto c = matrix[0].size();
    std::set<int> rows;
    std::set<int> cols;
    for(size_t i = 0; i < r; i++){
        for(size_t j = 0; j < c; j++){
            if(matrix[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for(const auto &it: rows){
        for(size_t i = 0; i < c; i++){
            matrix[it][i] = 0;
        }
    }
    for(const auto &it: cols){
        for(size_t i = 0; i < r; i++){
            matrix[i][it] = 0;
        }
    }
   
}
    
};