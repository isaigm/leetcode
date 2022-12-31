// https://leetcode.com/problems/majority-element

import math
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        uniques = []
        for idx in range(len(nums)):
            if nums[idx] not in uniques:
                if nums.count(nums[idx]) > math.floor(len(nums)/2): return idx
                uniques.append(nums[idx])
        return -1