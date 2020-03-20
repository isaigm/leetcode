import math
import itertools
import time
import random

def get_execution_time(func, *args):
    start_time = time.time()
    print(func(*args))
    print(time.time() - start_time, end=" s\n")

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if (p == None and q != None) or (p != None and q == None):
            return False
        elif p == None and q == None:
           return True
        else:
            if p.val == q.val:
                return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
            return False

    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root == None:
            return None
        elif root.val == val:
           return root
        else:
            if val < root.val:
                return self.searchBST(root.left, val)
            elif val > root.val:
               return self.searchBST(root.right, val)

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        size = 0
        ptr = head
        while ptr != None:
            ptr = ptr.next
            size += 1
        idx = 0
        if size == n:
            next_node = head.next
            head = None
            head = next_node
            return head
        else:    
            ptr = head
            prev = None
            while idx < (size - n):
                prev = ptr
                ptr = ptr.next
                idx += 1
            if ptr.next == None:
                prev.next = None
                ptr = None
            else:
                prev.next = ptr.next
                ptr = None
        return head
    def isValidBST(self, root: TreeNode) -> bool:
        if root == None : return True
        else:
            valid_left = False
            valid_right = False
            left = root.left
            right = root.right
            if left == None and right == None : return True
            if left != None:
                if left.val < root.val:
                    valid_left = self.isValidBST(left)
                else : return False
            else : valid_left = True
            if right != None:
                if right.val > root.val:
                    valid_right = self.isValidBST(right)
                else : return False
            else : valid_right = True
            return valid_left and valid_right
def subsets(nums):
    subs = []
    subs.append([])
    for n in range(1, len(nums) + 1):
        for comb in itertools.combinations(nums, n):
            subs.append(list(comb))
    return subs

def isPalindrome(x: int) -> bool:
    if x < 0:
        return False
    else:
       return str(x) == str(x)[::-1]

def searchInsert(nums, target: int) -> int:
    for idx in range(len(nums)):
        if nums[idx] >= target:
            return idx
    return idx + 1

def partition(nums, target, left, right) -> int:
    if left == right:
        return left
    mid = (left + right) // 2
    pivot = nums[mid]
    if target == pivot:
        return mid
    else:
        if target < pivot:
            return partition(nums, target, left, mid)
        elif target > pivot:
            return partition(nums, target, mid + 1, right)

def binarySearch(nums, target):
    return partition(nums, target, 0, len(nums))

def countingSort(nums: list):
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
    print(nums)

def plusOne(digits : [int]) -> [int]:
    res = []
    if digits[-1] + 1 > 9:
        res.insert(0, (digits[-1] + 1) % 10)
        carry = 1
        for idx in range(len(digits) - 2, -1, -1):
            if digits[idx] + carry > 9:
                res.insert(0, (digits[idx] + carry) % 10)
                carry = 1
            else:
                res.insert(0, digits[idx] + carry)
                carry = 0
        if carry == 1:
            res.insert(0, (digits[0] + carry) // 10)
    else:
        res = digits[:]
        res[-1] += 1
    return res

get_execution_time(plusOne, [1, 9, 9, 9])
