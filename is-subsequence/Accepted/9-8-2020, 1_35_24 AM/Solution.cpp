// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        int idx = 0;
        for(int i = 0; i < t.size() && idx < s.size(); i++){
            if(t[i] == s[idx]){
                idx++;
            }
        }
        return idx == s.size();
    }
};