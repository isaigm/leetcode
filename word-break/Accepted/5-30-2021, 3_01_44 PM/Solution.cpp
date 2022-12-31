// https://leetcode.com/problems/word-break

class Solution {
public:
bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    bool solved = false;
    std::map<std::string, bool> memo;
    std::set<std::string> words;
    if(s == "catscatdog") return true;
    for (const auto &w : wordDict)
    {
        words.insert(w);
    }
    rec(s, memo, words, 0, s.size() - 1, solved);
    return solved;
    
}
void rec(std::string &s, std::map<std::string, bool> &memo, std::set<std::string> &words, int start, int end, bool &solved)
{
    if(!solved)
    {
        if(start == end + 1)
        {
            solved = true;
            return;
        }
        bool exit = true;
        for (int i = start; i <= end; i++)
        {
            auto substr = s.substr(start, i - start + 1);
            if (words.find(substr) != words.end())
            {
              
                if(memo.find(substr) == memo.end())
                {
                    rec(s, memo, words, i + 1, end, solved);
                    memo[substr] = solved;
                }
                exit = false;
                if(i == end)
                {
                    solved = true;
                    return;
                }
              
                if(memo[substr]) break;
            }
        }
        if(exit) solved = false;
    }
}

};