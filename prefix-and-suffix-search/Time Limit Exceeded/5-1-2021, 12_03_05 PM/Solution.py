// https://leetcode.com/problems/prefix-and-suffix-search

class WordFilter:

    def __init__(self, words: [str]):
        self.words = words

    def f(self, prefix: str, suffix: str) -> int:
        idx = -1
        for i, w in enumerate(self.words):
            if w.startswith(prefix) and w.endswith(suffix):
                idx = i
        return idx


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)