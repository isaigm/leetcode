// https://leetcode.com/problems/search-insert-position

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for idx in range(len(nums)):
            if nums[idx] >= target : return idx
        return idx