// https://leetcode.com/problems/valid-palindrome

class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_s = ''
        for ch in s:
            lower = ch.lower()
            if lower >= 'a' and lower <= 'z':
                new_s += lower
        return new_s[::-1] == new_s