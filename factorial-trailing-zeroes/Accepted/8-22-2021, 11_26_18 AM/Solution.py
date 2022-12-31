// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution:
    def trailingZeroes(self, n: int) -> int:
        product = 1
        for i in range(1, n + 1):
            product *= i
        strr = str(product)
        ans = 0
        idx = len(strr) - 1
        while idx >= 0 and strr[idx] == '0':
            ans += 1
            idx -= 1
            
        
        return ans