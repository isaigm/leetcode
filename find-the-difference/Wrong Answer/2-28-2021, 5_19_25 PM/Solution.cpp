// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        std::map<char, bool> m;
        for(const auto &ch: s)
        {
            m[ch] = true;
        }
        for(const auto &ch: t)
        {
            if(m.find(ch) == m.end())
            {
                return ch;
            }
        }
        return '\0';
    }
};