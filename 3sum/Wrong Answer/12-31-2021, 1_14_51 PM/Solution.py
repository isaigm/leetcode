// https://leetcode.com/problems/3sum

import collections
class Solution:
    def threeSum(self, nums:list):
        cnt = collections.Counter(nums)

        solutions = set()
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                s = nums[i] + nums[j]
                if s == 0:
                    continue
                rem = cnt.get(-s)
                if rem != None and rem >= 0:
                    cnt[nums[i]] -= 1
                    cnt[nums[j]] -= 1
                    cnt[-s] -= 1
                    solution = [nums[i], nums[j], -s]
                    solution.sort()

                    solutions.add(tuple(solution))
        return [list(s) for s in solutions]
        
