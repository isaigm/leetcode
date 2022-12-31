// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int frq[26] = {0};
        for(const auto &x: sentence){
            frq[x - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(frq[i] == 0) return false;
        }
        return true;
    }
};