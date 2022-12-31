// https://leetcode.com/problems/sorting-the-sentence

class Solution:
    def sortSentence(self, s: str) -> str:
        ans = ""
        words = s.split(' ')
        words.sort(key=lambda x: int(x[-1]))
        for w in words:
            ans += w[:-1] + " "
        return ans[:-1]