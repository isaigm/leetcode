// https://leetcode.com/problems/combinations

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(itertools.combinations([i for i in range(1, n+1)], k))