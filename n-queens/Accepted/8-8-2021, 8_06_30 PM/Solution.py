// https://leetcode.com/problems/n-queens

def not_attacked(queens, q1, q2):
    flag = True
    flag = flag and (queens[q1] != queens[q2])
    flag = flag and abs(queens[q1] - queens[q2]) != abs(q1 - q2)
    return flag

def is_ok(queens, i):
    for idx in range(i):
        if not not_attacked(queens, i, idx):
            return False
    return True

def bt(solutions, queens, i, n):
    if i == n:
        solution = []
        for idx in range(n):
            s = "." * n
            s = s[:queens[idx]] + 'Q' + s[queens[idx] + 1:]
            solution.append(s)
        solutions.append(solution)
        return

    for j in range(n):
        queens[i] = j
        if is_ok(queens, i):
            bt(solutions, queens, i + 1, n)
        else:
            queens[i] = -1
            
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
     
    
        solutions = []
        bt(solutions, [-1 for _ in range(n)], 0, n)
        return solutions