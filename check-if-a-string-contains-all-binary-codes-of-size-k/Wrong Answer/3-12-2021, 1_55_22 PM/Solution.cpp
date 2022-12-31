// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        std::set<std::string> ss;
        for(int i = 0; i < s.size(); i++)
        {
            if(i + k < s.size())
            {
                ss.insert(s.substr(i, k));
            }
        }
        return ss.size() == std::pow(2, k);
    }
};