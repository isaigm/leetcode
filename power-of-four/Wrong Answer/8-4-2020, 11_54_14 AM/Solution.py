// https://leetcode.com/problems/power-of-four

class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        k = 0
        while k**4 <= num:
            if k**4 == num:
                return True
            k += 1
        return False