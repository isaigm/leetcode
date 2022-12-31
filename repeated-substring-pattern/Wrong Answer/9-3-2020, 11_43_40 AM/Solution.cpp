// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        std::map<char, int> c;
    for(const auto &it: s){
        c[it]++;
    }
    for(const auto &it: c){
        if(it.second % 2 != 0) return false;
    }
    return true;
    }
};