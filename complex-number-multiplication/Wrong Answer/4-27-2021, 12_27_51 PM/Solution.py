// https://leetcode.com/problems/complex-number-multiplication

class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        num1 = num1.replace('i', 'j')
        num2 = num2.replace('i', 'j')
        x = eval(num1)
        y = eval(num2)
        z = x * y
        res = z.__str__()
        if z.real == 0:
            res = "0+" + res
        res = res.replace('(', '')
        res = res.replace(')', '')
        return res
        