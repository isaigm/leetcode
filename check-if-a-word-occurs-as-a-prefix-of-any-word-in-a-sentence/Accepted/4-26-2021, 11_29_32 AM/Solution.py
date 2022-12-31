// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(' ')
        idx = 1
        for w in words:
            if w.startswith(searchWord):
                return idx
            idx += 1
        return -1