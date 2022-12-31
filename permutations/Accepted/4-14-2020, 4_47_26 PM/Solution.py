// https://leetcode.com/problems/permutations

import itertools
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        perms = itertools.permutations(nums)
        return list(perms)