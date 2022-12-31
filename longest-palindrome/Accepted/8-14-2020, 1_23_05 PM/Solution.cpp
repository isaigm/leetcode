// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> c;
        int res = 0;
        bool flag = false;
        
        for(char &c2: s){
            c[c2]++;
        }
        for(const auto &it: c){
            if(it.second % 2 == 0){
                res += it.second;
            }else{
                res += it.second - 1;
                flag = true;
            }
        }
        if(flag) res++;
        
        return res;
    }
};