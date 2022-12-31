// https://leetcode.com/problems/maximum-subarray

class Solution:
    def maxSubArray(self, arr: List[int]) -> int:
        max_so_far = arr[0]
        max_ending_here = 0
        for i in range(1, len(arr)):
            max_ending_here += arr[i]
            if max_so_far < max_ending_here:
                max_so_far = max_ending_here
            if max_ending_here < 0:
                max_ending_here = 0
        return max_so_far
