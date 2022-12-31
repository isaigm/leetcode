// https://leetcode.com/problems/queens-that-can-attack-the-king

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        std::vector<std::vector<int>> ans;
        auto make_vec = [](int r, int c)
        {
            std::vector<int> vec;
            vec.push_back(r);
            vec.push_back(c);
            return vec;
        };
        int board[8][8] = {{0}};
        int row = king[0];
        int col = king[1];
        for(const auto &q: queens)
        {
            board[q[0]][q[1]] = 1;
        }
        for(int i = col; i < 8; i++)
        {
            if(board[row][i] == 1)
            {
                ans.push_back(std::move(make_vec(row, i)));
                break;
            }
        }
        for(int i = col; i >= 0; i--)
        {
            if(board[row][i] == 1)
            {
                ans.push_back(std::move(make_vec(row, i)));
                break;
            }
        }
        for(int i = row; i < 8; i++)
        {
            if(board[i][col] == 1)
            {
                ans.push_back(std::move(make_vec(i, col)));
                break;
            }
        }
        for(int i = row; i >= 0; i--)
        {
            if(board[i][col] == 1)
            {
                ans.push_back(std::move(make_vec(i, col)));
                break;
            }
        }
        for (int i = row, j = col; i < 8 && j < 8; i++, j++)
        {
           if(board[i][j] == 1)
           {
               ans.push_back(std::move(make_vec(i, j)));
               break;
           }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
           if(board[i][j] == 1)
           {
               ans.push_back(std::move(make_vec(i, j)));
               break;
           }
        }
        for (int i = row, j = col; i >= 0 && j < 8; i--, j++)
        {
          if(board[i][j] == 1)
           {
               ans.push_back(std::move(make_vec(i, j)));
               break;
           }
        }
        for (int i = row, j = col; i < 8 && j >= 0; i++, j--)
        {
           if(board[i][j] == 1)
           {
               ans.push_back(std::move(make_vec(i, j)));
               break;
           }
        }
        return ans;
    }
};