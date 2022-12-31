// https://leetcode.com/problems/word-break

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        large_string = ""
        for word in wordDict:
            large_string += word
        return s in large_string