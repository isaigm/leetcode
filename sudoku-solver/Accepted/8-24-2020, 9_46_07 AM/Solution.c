// https://leetcode.com/problems/sudoku-solver

bool is_valid(int num, int row, int col, char **board)
{
    int r = row - (row % 3), c = col - (col % 3);
    for (int i = r; i < r + 3; i++)
    {
        for (int j = c; j < c + 3; j++)
        {
            if ((board[i][j] - '0') == num)
            {
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        int d1 = board[row][i] - '0';
        int d2 = board[i][col] - '0';
        if (d1 == num || d2 == num)
            return false;
    }
    return true;
}
void backtracking(int row, int col, int *total, bool *flag, char **board)
{
    if (*total == 81)
    {
        *flag = true;
        return;
    }
    while (board[row][col] != '.')
    {
        col++;
        if (col >= 9)
        {
            col = 0;
            row++;
            if (row >= 9)
            {
                *flag = true;
                return;
            }
        }
    }
 
    for (int i = 1; i <= 9; i++)
    {
        if (is_valid(i, row, col, board))
        {
            board[row][col] = i + '0';
            int temp_c = col;
            int temp_r = row;
            temp_c++;
            if (temp_c >= 9)
            {
                temp_r++;
                temp_c = 0;
            }
            *total = *total + 1;
            if(temp_r >= 9){
                *flag = true;
                return;
            }
            backtracking(temp_r, temp_c, total, flag, board);
            if (*flag)
                return;
            *total = *total - 1;
            board[row][col] = '.';
        }
    }
    *flag = false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int total = 0;
    bool flag = false;
    backtracking(0, 0, &total, &flag, board);
}