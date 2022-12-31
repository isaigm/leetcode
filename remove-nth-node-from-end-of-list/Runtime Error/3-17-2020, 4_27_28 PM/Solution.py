// https://leetcode.com/problems/remove-nth-node-from-end-of-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        size = 0
        ptr = head
        while ptr.next != None:
            ptr = ptr.next
            size += 1
        idx = 0
        if size == 1 : return None
        if size == n:
            next_node = head.next
            head = None
            head = next_node
            return head
        else:    
            ptr = head
            prev = None
            while idx < (size - n) + 1:
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