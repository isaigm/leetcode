// https://leetcode.com/problems/truncate-sentence

class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        words = s.split(' ')
        if k > len(words): return ''
        return ' '.join(words[:k])