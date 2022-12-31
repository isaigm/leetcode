// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        int steps = 0;
        int frq1[26] = {0};
        int frq2[26] = {0};
        for(int i = 0; i < s.size(); i++)
        {
            frq1[s[i] - 'a']++;
            frq2[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(frq2[i] < frq1[i])
            {
                steps += frq1[i] - frq2[i];
            }
        }
        return steps;
    }
};