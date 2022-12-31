// https://leetcode.com/problems/length-of-last-word

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = re.findall(r'[^\s]+', s)
        if len(s) == 0 or len(words) == 0: return 0
        return len(words[-1])