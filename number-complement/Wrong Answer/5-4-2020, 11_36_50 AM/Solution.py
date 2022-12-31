// https://leetcode.com/problems/number-complement

class Solution:
    def findComplement(self, num: int) -> int:
        res = 0
        while num > 0:
            bit = num & 1
            res |= not bit
            num >>= 1
            res <<= 1
        res >>= 1
        return res