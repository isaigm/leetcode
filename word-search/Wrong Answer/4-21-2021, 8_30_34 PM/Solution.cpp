// https://leetcode.com/problems/word-search

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                bool valid = false;
                std::map<std::pair<int, int>, bool> seen;
                is_valid(seen, board, word, valid, i, j, 0);
                if(valid) return true;
            }
        }
        return false;
    }
    void is_valid(std::map<std::pair<int,int>, bool> &seen,
vector<vector<char>>& board, std::string &word, bool &valid, int i, int j, int idx)
    {
   
        if(word.size() == 1)
        {
            valid = board[i][j] == word[0];
            return;
        }
        if(idx == word.size() - 1)
        {
            valid = true;
            return;
        }
        if(idx < word.size() - 1 && board[i][j] == word[idx])
        { 
            seen[{i, j}] = true;
            if(i + 1 < board.size() && !valid && !seen[{i + 1, j}])
            {
                if(board[i + 1][j] == word[idx + 1])
                {
                    is_valid(seen, board, word, valid, i + 1, j, idx + 1);
                    if(valid) return;
                }
            }
            if(i - 1 >= 0 && !valid && !seen[{i - 1, j}])
            {
                if(board[i - 1][j] == word[idx + 1])
                {
                    is_valid(seen, board, word, valid, i - 1, j, idx + 1);
                    if(valid) return;
                }
            }
            if(j + 1 < board[0].size() && !valid && !seen[{i, j + 1}])
            {
                if(board[i][j + 1] == word[idx + 1])
                {
                    is_valid(seen, board, word, valid, i, j + 1, idx + 1);
                    if(valid) return;
                }
            }
            if(j - 1 >= 0 && !valid && !seen[{i, j - 1}])
            {
                if(board[i][j - 1] == word[idx + 1])
                {
                    is_valid(seen, board, word, valid, i, j - 1, idx + 1);
                    if(valid) return;
                }
            }
        }       
    }
};