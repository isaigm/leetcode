// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
       size_t idx = 0;
      for(size_t i = 0; i < t.size() && idx < s.size(); i++){
          if(t[i] == s[idx]){
              idx++;
          }
      }
      return idx == s.size();
    }
};