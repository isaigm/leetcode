// https://leetcode.com/problems/sort-colors

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        min_e = min(nums)
        max_e = max(nums)
        vect = [0 for _ in range(max_e - min_e + 1)]
        for e in nums:
            vect[e - min_e] += 1
        idx = 0
        j = 0
        while idx < len(vect):
            for _ in range(vect[idx]):
                nums[j] = idx + min_e
                j += 1
            idx += 1
        