// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    void util(int &ans, int idx, int n)
    {
        if(n == 0)
        {
            ans++;
            return;
        }
        for(int i = idx; i < 5; i++)
        {
            util(ans, i, n - 1);
        }
    }
    int countVowelStrings(int n) {
        int ans = 0;
        util(ans, 0, n);
        return ans;
    }
};