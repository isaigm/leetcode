// https://leetcode.com/problems/number-complement

class Solution:
    def findComplement(self, num: int) -> int:
        res = 0
        i = 0
        while num > 0:
            bit = num & 1
            res |= ((not bit) << i)
            num >>= 1
            i += 1
        return res