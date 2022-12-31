// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1[25] = {0};
        int s2[25] = {0};
        for(const auto &ch: s)
        {
            s1[ch - 'a']++;
        }
        for(const auto &ch: t)
        {
            s2[ch - 'a']++;
        }
        for(int i = 0; i < 25; i++)
        {
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
};