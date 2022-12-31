// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::map<char, char> m1;
        std::map<char, char> m2;
        for(size_t i = 0; i < s.size(); i++)
        {
            if(m2.find(s[i]) == m2.end())
            {
                m2[t[i]] = s[i];
            }else if(m2[t[i]] != s[i]) return false;
            if(m1.find(s[i]) == m1.end())
            {
                m1[s[i]] = t[i];
            }else if(m1[s[i]] != t[i]) return false;
        }
        return true;
    }
};