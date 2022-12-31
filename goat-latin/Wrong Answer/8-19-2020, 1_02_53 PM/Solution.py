// https://leetcode.com/problems/goat-latin

class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split()
        vowels = ('a','e','i','o','u','A','E','I','O','U')
        idx = 1
        res = ""
        for w in words:
            if w.startswith(vowels):
                w += 'ma'
            else:
                w = w[1:] + w[0] + 'ma'
            w += 'a' * idx + ' '
            res += w
            idx += 1
        return res