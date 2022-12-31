// https://leetcode.com/problems/plus-one

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res = []
        if digits[-1] + 1 > 9:
            res.insert(0, (digits[-1] + 1) % 10)
            carry = 1
            for idx in range(len(digits) - 2, -1, -1):
                if digits[idx] + carry > 9:
                    res.insert(0, (digits[idx] + carry) % 10)
                    carry = 1
                else:
                    res.insert(0, digits[idx] + carry)
                    carry = 0
            if carry == 1:
                res.insert(0, (digits[0] + carry) // 10)
        else:
            res = digits[:]
            res[-1] += 1
        return res