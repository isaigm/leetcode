// https://leetcode.com/problems/subsets

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subs = []
        for n in range(1, len(nums) + 1):
            for comb in itertools.combinations(nums, n):
                subs.append(list(comb))
        return subs