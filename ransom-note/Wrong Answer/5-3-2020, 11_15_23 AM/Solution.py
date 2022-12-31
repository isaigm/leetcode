// https://leetcode.com/problems/ransom-note

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if ransomNote == "": return True
        return len(re.findall(ransomNote, magazine)) == 1