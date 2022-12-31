// https://leetcode.com/problems/power-of-four

class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        k = 0
        while 4**k <= num:
            if 4**k == num:
                return True
            k += 1
        return False