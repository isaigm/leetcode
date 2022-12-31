// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution:
    def firstUniqChar(self, s: str) -> int:
        uniques = []
        for idx in range(len(s)):
            if s[idx] not in uniques:
                if s.count(s[idx]) == 1: return idx
                uniques.append(s[idx])
        return -1