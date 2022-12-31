// https://leetcode.com/problems/valid-perfect-square

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        n = num
        while(i * i<= n): 
          
            # If (i * i = n) 
            if ((n % i == 0) and (n / i == i)): 
                return True
              
            i = i + 1
        return False