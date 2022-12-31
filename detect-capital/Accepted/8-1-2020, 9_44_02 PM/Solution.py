// https://leetcode.com/problems/detect-capital

class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        count = 0
        for ch in word:
            if ch.isupper():
                count += 1
        return count == len(word) or count == 0 or (count == 1 and word[0].isupper())