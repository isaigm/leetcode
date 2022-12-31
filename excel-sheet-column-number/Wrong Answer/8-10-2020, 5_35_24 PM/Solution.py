// https://leetcode.com/problems/excel-sheet-column-number

def to_int(ch: chr):
    return ord(ch) - ord('A') + 1

class Solution:
    def titleToNumber(self, s: str) -> int:
        p = 0
        n = 0
        for ch in s:
            n += 26**p * to_int(ch)
            p += 1
        return n