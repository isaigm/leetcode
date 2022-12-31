// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int frq1[26] = {0};
        for(const auto &ch: s1)
        {
            frq1[ch - 'a']++;
        }
        for(int i = 0; i <= s2.size() - s1.size(); i++)
        {
            int frq2[26] = {0};
            for(int j = i; j < i + s1.size(); j++)
            {
                frq2[s2[j] - 'a']++;
            }
            bool flag = false;
            for(int i = 0; i < 26; i++)
            {
                if(frq2[i] != frq1[i]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return true; 
        }
        return false;
    }
};