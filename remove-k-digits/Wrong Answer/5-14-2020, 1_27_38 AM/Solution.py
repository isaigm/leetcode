// https://leetcode.com/problems/remove-k-digits

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if len(num) == k: return "0"
        result = ""
        idx = 0
        numlen = len(num)
        eliminated = 0
        while idx < numlen - 1 and eliminated < k and len(result) < numlen - k:
            if int(num[idx]) <= int(num[idx + 1]):
                result += num[idx]
            else: eliminated += 1
            idx += 1
        if len(result) < numlen - k:
            result += num[-(numlen-idx):]
        idx = 0
        while result[idx] == '0' and len(result) > 1:
            result = result[1:]
        return result