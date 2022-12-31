// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        std::map<char, int> ss;
        std::map<char, int> tt;
        for(const auto &ch: s)
        {
            ss[ch]++;
        }
        for(const auto &ch: t)
        {
            tt[ch]++;
        }
        for(const auto &p: tt)
        {
            if(ss.find(p.first) == ss.end()){
                return p.first;
            }else if(ss[p.first] + 1 == p.second){
                return p.first;
            }
        }
        return '\0';
    }
};