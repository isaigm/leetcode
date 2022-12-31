// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::map<char, char> mapp;
        for(size_t i = 0; i < s.size(); i++)
        {
            if(mapp.find(s[i]) == mapp.end())
            {
                mapp[s[i]] = t[i];
            }else if(mapp[s[i]] != t[i]) return false;
        }
        return true;
    }
};