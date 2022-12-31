// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
   bool isValidSudoku(std::vector<std::vector<char>>& board) {
    bool used_r[9];
    bool used_c[9];
     for(auto &it: used_r) it = false;
        for(auto &it: used_c) it = false;
    for(size_t i = 0; i < 9; i++){
        for(size_t j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                int digit = board[i][j] - '0';
                if(used_r[digit - 1]) return false;
                used_r[digit - 1] = true;
            }
            if(board[j][i] != '.'){
                int digit = board[j][i] - '0';
                if(used_c[digit - 1]) return false;
                used_c[digit - 1] = true;
            }
        }
        for(auto &it: used_r) it = false;
        for(auto &it: used_c) it = false;

    }
    int row = 0;
    int col = 0;
    for(auto &it: used_r) it = false;
    for(size_t k = 0; k < 9; k++){
        for(size_t i = 0; i < 3; i++){
            for(size_t j = 0; j < 3; j++){
                auto ch = board[row][col + j];
                if(ch != '.'){
                    int digit = ch - '0';
                    if(used_r[digit - 1]) return false;
                    used_r[digit - 1] = true;
                }
            }

            row++;
        }
        for(auto &it: used_r) it = false;
        if(row >= 9){
            row = 0;
            col += 3;
        }
    }
    return true;
}
};