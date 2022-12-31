// https://leetcode.com/problems/reverse-integer

import math
class Solution:
    def reverse(self, x: int):
        self.p = 0
        def auxiliar(y: int):
            rev = 0
            if y > 0:
                rev += auxiliar(y//10) + 10**self.p * (y % 10)
                self.p += 1
            return rev
        if x < 0:
            return -auxiliar(-x)
        return auxiliar(x)