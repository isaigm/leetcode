// https://leetcode.com/problems/alphabet-board-path

class Solution {
public:
    string alphabetBoardPath(string target) {
        std::string s;
        std::vector<std::string> board {"abcde", "fghij", "klmno", "pqrst", "uvwxy",                "z0000"};
        std::map<char, std::pair<int, int>> m;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] != '0')
                {
                    m[board[i][j]] = {j, i};
                }
            }
        }
        int idx = 0;
        int curr_x = 0, curr_y = 0;
        auto get_next_dir = [&board](int curr_x, int curr_y, int next_x, int next_y)
        {
            std::vector<std::pair<int, char>> neighbours;
            if(curr_x - 1 >= 0 && board[curr_y][curr_x - 1] != '0')
            {
                auto md = std::abs(curr_x - 1 - next_x) + std::abs(curr_y - next_y);
                neighbours.push_back({md, 'L'});
            }
            if(curr_x + 1 < board[0].size() && board[curr_y][curr_x + 1] != '0')
            {
                auto md = std::abs(curr_x + 1 - next_x) + std::abs(curr_y - next_y);
                neighbours.push_back({md, 'R'});
            }
            if(curr_y - 1 >= 0 && board[curr_y - 1][curr_x] != '0')
            {
                auto md = std::abs(curr_x - next_x) + std::abs(curr_y - 1 - next_y);
                neighbours.push_back({md, 'U'});
            }
            if(curr_y + 1 < board.size() && board[curr_y + 1][curr_x] != '0')
            {
                auto md = std::abs(curr_x - next_x) + std::abs(curr_y + 1 - next_y);
                neighbours.push_back({md, 'D'});
            }
            std::sort(neighbours.begin(), neighbours.end(), [](const auto &p1, const auto &p2)             {
                return p1.first < p2.first;
            });
            return neighbours[0].second;
        };
        for(;idx < target.size();)
        {
            auto next_letter = m[target[idx]];
            if(curr_x == next_letter.first && curr_y == next_letter.second)
            {
                s.push_back('!');
                idx++;
                continue;
            }
            char next_dir = get_next_dir(curr_x, curr_y, next_letter.first,                                     next_letter.second);
            switch(next_dir)
            {
                case 'L':
                    curr_x--;
                    break;
                case 'R':
                    curr_x++;
                    break;
                case 'U':
                    curr_y--;
                    break;
                case 'D':
                    curr_y++;
                    break;
            }
            s.push_back(next_dir);
           
            if(curr_x == next_letter.first && curr_y == next_letter.second)
            {
                s.push_back('!');
                idx++;
            }
        }
        return s;
    }
};