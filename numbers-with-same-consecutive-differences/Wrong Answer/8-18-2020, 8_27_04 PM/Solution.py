// https://leetcode.com/problems/numbers-with-same-consecutive-differences

class Solution:
    def numsSameConsecDiff(self, N: int, K: int) -> List[int]:
        def getPositiveRoots(x):
            roots = []
            b = -2*x
            c = x**2 - K**2
            d = b**2 - 4*c
            if d >= 0:
                x1 = (-b + math.sqrt(d)) / 2
                x2 = (-b - math.sqrt(d)) / 2
                if x1.is_integer() and x1 >= 0 and math.floor(x1) <= 9:
                    roots.append(math.floor(x1))
                if x2.is_integer() and x2 >= 0 and math.floor(x2) <= 9:
                    roots.append(math.floor(x2))
                return roots
            else:
                return []

        def gen(curr, aux):
            res = str(curr)
            l = len(res)
            if l == N:
                aux.append(curr)
                return
            roots = getPositiveRoots(int(res[l - 1]))
            if len(roots) == 1:
                gen(int(res + str(roots[0])), aux)
            elif len(roots) == 2:
                gen(int(res + str(roots[0])), aux)
                gen(int(res + str(roots[1])), aux)
            else: return
        res = []
        for i in range(0, 10):
            gen(i, res)
        return res
