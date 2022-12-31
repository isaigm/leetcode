// https://leetcode.com/problems/reverse-integer

import math
class Solution:
    p = 0
    def reverse(self, x: int) -> int:
        rev = 0
        if x > 0:
            rev += self.reverse(x//10) + 10**self.p * (x % 10)
            self.p += 1
        return rev