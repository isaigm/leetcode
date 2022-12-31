// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
     std::map<char, int> c;
        if(s.size() == 1) return true;
    for(const auto &it: s){
        c[it]++;
    }
    int aux = -1;
    for(const auto &it: c){
        if(aux == -1){
            aux = it.second;
        }else if(aux != it.second) return false;
        else aux = it.second;
    }
    return true;
    }
};