// https://leetcode.com/problems/word-search

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(is_valid(board, word, i, j)) return true;
            }
        }
        return false;
    }
    bool is_valid(vector<vector<char>>& board, std::string &word, int i, int j)
    {
        int idx = 0;
        bool valid = false;
        if(board[i][j] == word[0] && word.size() == 1) return true;
        std::map<std::pair<int,int>, bool> seen;
        while(idx < word.size() - 1 && board[i][j] == word[idx])
        { 
            valid = false;
            seen[{i, j}] = true;
            if(i + 1 < board.size() && !valid && !seen[{i + 1, j}])
            {
                if(board[i + 1][j] == word[idx + 1])
                {
                    i++;
                    valid = true;
                }
            }
            if(i - 1 >= 0 && !valid && !seen[{i - 1, j}])
            {
                if(board[i - 1][j] == word[idx + 1])
                {
                    i--;
                    valid = true;
                }
            }
            if(j + 1 < board[0].size() && !valid && !seen[{i, j + 1}])
            {
                if(board[i][j + 1] == word[idx + 1])
                {
                    j++;
                    valid = true;
                }
            }
            if(j - 1 >= 0 && !valid && !seen[{i, j - 1}])
            {
                if(board[i][j - 1] == word[idx + 1])
                {
                    j--;
                    valid = true;
                }
            }
            idx++;
            if(!valid) return false;

        }

        return valid;
        
    }
};