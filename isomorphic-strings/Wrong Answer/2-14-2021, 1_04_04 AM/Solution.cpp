// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::vector<int> l1(26, 0);
        std::vector<int> l2(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            l1[s[i] - 'a']++;
            l2[t[i] - 'a']++;
        }
        std::sort(l1.begin(), l1.end());
        std::sort(l2.begin(), l2.end());
        for(int i = 0; i < 26; i++)
        {
            if(l1[i] != l2[i]) return false;
        }
        return true;
    }
};