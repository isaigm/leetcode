// https://leetcode.com/problems/ransom-note

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if ransomNote == "": return True
        for ch in ransomNote:
            idx = magazine.find(ch)
            if idx == -1: return False
            else: magazine = magazine[:idx] + magazine[idx + 1:]
        return True