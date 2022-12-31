// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 0) return 0;
        int i = 0; 
        int j = s.size() - 1;
        bool is_palindrome = true;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                is_palindrome = false;
                break;
            }
            i++;
            j--;
        }
        if(is_palindrome) return 1;
        return 2;
    }
};