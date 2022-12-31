// https://leetcode.com/problems/word-pattern

class Solution:
    def wordPattern(self, pattern: str, strr: str) -> bool:
        words = strr.split(' ')
        l1 = len(pattern)
        for i in range(l1 - 1):
            if pattern[i] == pattern[i + 1]:
                if words[i] != words[i + 1]: return False
            else:
                if words[i] == words[i + 1]: return False
        return True