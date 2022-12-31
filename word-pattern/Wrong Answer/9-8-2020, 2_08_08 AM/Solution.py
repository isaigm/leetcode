// https://leetcode.com/problems/word-pattern

class Solution:
    def wordPattern(self, pattern: str, strr: str) -> bool:
        words = strr.split(' ')
        aux = dict()
        l1 = len(pattern)
        for i in range(l1):
            if not pattern[i] in aux:
                aux[pattern[i]] = words[i]
            elif aux[pattern[i]] != words[i]: return False
        return True