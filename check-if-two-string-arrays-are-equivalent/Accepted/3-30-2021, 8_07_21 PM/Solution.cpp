// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        std::string s1, s2;
        for(const auto &s: word1)
        {
            s1 += s;
        }
        for(const auto &s: word2)
        {
            s2 += s;
        }
        return s1 == s2;
    }
};