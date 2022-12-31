// https://leetcode.com/problems/available-captures-for-rook

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook_row = -1;
        int rook_col = -1;
        int ans = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] == 'R')
                {
                    rook_row = i;
                    rook_col = j;
                    break;
                }
            }
            if(rook_row != -1 && rook_col != -1)
            {
                break;
            }
        }
        for(int i = rook_col; i < 8; i++)
        {
            if(board[rook_row][i] == 'B') {
                break;
            }else if(board[rook_row][i] == 'p')
            {
                ans++;
            }
            
        }
        for(int i = rook_col; i >= 0; i--)
        {
            if(board[rook_row][i] == 'B') {
                break;
            }else if(board[rook_row][i] == 'p')
            {
                ans++;
            }
            
        }
        for(int i = rook_row; i < 8; i++)
        {
            if(board[i][rook_col] == 'B') {
                break;
            }else if(board[i][rook_col] == 'p')
            {
                ans++;
            }
            
        }
         for(int i = rook_row; i >= 0; i--)
        {
            if(board[i][rook_col] == 'B') {
                break;
            }else if(board[i][rook_col] == 'p')
            {
                ans++;
            }
            
        }
        return ans;
    }
};