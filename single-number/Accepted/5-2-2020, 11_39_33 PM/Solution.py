// https://leetcode.com/problems/single-number

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        aux = set(nums)
        for n in aux:
            if(nums.count(n) == 1): return n