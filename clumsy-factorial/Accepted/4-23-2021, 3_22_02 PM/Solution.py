// https://leetcode.com/problems/clumsy-factorial

class Solution:
    def clumsy(self, N: int) -> int:
        operators = ["*", "//", "+", "-"]
        to_eval = ""
        idx = 0
        for i in range(N, 0, -1):
            to_eval += str(i)
            if idx > 3:
                idx = 0
            if i > 1:
                to_eval += operators[idx]
            idx += 1
        return eval(to_eval)