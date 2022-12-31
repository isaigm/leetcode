// https://leetcode.com/problems/length-of-last-word

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(re.findall(r'[^\s]+', s)[-1])