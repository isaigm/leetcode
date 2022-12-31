// https://leetcode.com/problems/count-the-number-of-consistent-strings

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        bool tab[26];
        for(int i  = 0; i < 26; i++)
        {
            tab[i] = false;
        }
        for(const auto &ch: allowed)
        {
            tab[ch - 'a'] = true;
        }
        auto is_consistent = [=](const std::string &s)
        {
            for(const auto &ch: s)
            {
                if(!tab[ch - 'a']) return false;
            }
            return true;
        };
        for(const auto &s: words)
        {
            if(is_consistent(s)) ans++;
        }
        return ans;
    }
};