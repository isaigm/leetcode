// https://leetcode.com/problems/search-insert-position

class Solution:
    def partition(self, nums, target, left, right):
        if left == right : return left
        mid = (left + right) // 2
        pivot = nums[mid]
        if target == pivot : return mid
        else:
            if target < pivot:
                return partition(nums, target, left, mid) 
            elif target > pivot:
                return partition(nums, target, mid + 1, right)
    def searchInsert(self, nums, target):
        return partition(nums, target, 0, len(nums))