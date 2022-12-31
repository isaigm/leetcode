// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution:
    def rangeBitwiseAnd(self, start: int, end: int) -> int:
        if start == end:
            return start
        len_bits = 0
        temp_start = start
        while temp_start > 0:
            len_bits += 1
            temp_start >>= 1
        if end > (1 << len_bits) - 1:
            return 0

        bit = start & (1 << (len_bits - 1 ))
        res = 0
        i = 1
        while bit != 0 and i < len_bits:
            res += bit
            bit = start & (1 << (len_bits - 1 - i))
            i += 1

        return res  