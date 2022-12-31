// https://leetcode.com/problems/sudoku-solver

bool is_valid(int num, int sub, int row, int col, char **board)
{
    int r = 0, c = 0;
    switch (sub)
    {
    case 1:
        break;
    case 2:
        c = 3;
        break;
    case 3:
        c = 6;
        break;
    case 4:
        r = 3;
        c = 0;
        break;
    case 5:
        r = 3;
        c = 3;
        break;
    case 6:
        r = 3;
        c = 6;
        break;
    case 7:
        r = 6;
        c = 0;
        break;
    case 8:
        r = 6;
        c = 3;
        break;
    case 9:
        r = 6;
        c = 6;
        break;
    default:
        break;
    }
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
    int sub;
    if (row >= 0 && row <= 2)
    {
        if (col >= 0 && col <= 2)
        {
            sub = 1;
        }
        if (col >= 3 && col <= 5)
        {
            sub = 2;
        }
        if (col >= 6 && col <= 8)
        {
            sub = 3;
        }
    }
    else if (row >= 3 && row <= 5)
    {
        if (col >= 0 && col <= 2)
        {
            sub = 4;
        }
        if (col >= 3 && col <= 5)
        {
            sub = 5;
        }
        if (col >= 6 && col <= 8)
        {
            sub = 6;
        }
    }
    else if (row >= 6 && row <= 8)
    {
        if (col >= 0 && col <= 2)
        {
            sub = 7;
        }
        if (col >= 3 && col <= 5)
        {
            sub = 8;
        }
        if (col >= 6 && col <= 8)
        {
            sub = 9;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        if (is_valid(i, sub, row, col, board))
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
    backtracking(0, 0, &total, &flag, board);}