// https://leetcode.com/problems/valid-parentheses

class Solution:
    def isValid(self, seq: str) -> bool:
        aux = []
        open_list = ['(', '{', '[']
        closed_list = [')', '}', ']']
        for ch in seq:
            if ch in open_list: aux.append(ch)
            elif ch in closed_list:
                if len(aux) == 0: return False
                last = open_list.index(aux[-1])
                curr = closed_list.index(ch)
                if last != curr: return False
                else: aux.pop()
        return len(aux) == 0