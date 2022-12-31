// https://leetcode.com/problems/shifting-letters

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        char abcd[26];
        int sum = 0;
        for(const auto &x: shifts)
        {
            sum += x;
        }
        for(int i = 0; i < 26; i++)
        {
            abcd[i] = 'a' + i;
        }
        S[0] =  abcd[(S[0] - 'a' + sum) % 26];
        for(int i = 1; i < S.size(); i++)
        {
            sum -= shifts[i - 1];
            S[i] = abcd[(S[i] - 'a' + sum) % 26];
        }
        return S;
    }
};
