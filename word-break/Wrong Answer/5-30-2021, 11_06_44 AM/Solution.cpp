// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int start = 0;
        int end = s.size() - 1;
        std::set<std::string> words;
        for (const auto &w : wordDict)
        {
            words.insert(w);
        }
        while (true)
        {
            bool exit = true;
            for (int i = start; i <= end; i++)
            {
                auto substr = s.substr(start, i - start + 1);
                if (words.find(substr) != words.end())
                {
                 
                    exit = false;
                    start = i + 1;
                    break;
                }
            }
            if(exit) return false;
            if(start >= end) return true;
        }
        return true;
    }
};