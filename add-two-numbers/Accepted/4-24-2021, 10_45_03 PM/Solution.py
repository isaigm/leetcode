// https://leetcode.com/problems/add-two-numbers

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        n1 = 0;
        n2 = 0;
        cursor = l1;
        i = 0
        while cursor != None:
            n1 += cursor.val * pow(10, i)
            i += 1
            cursor = cursor.next;
        cursor = l2;
        i = 0
        while cursor != None:
            n2 += cursor.val * pow(10, i);
            i += 1
            cursor = cursor.next;
        cursor = ListNode()
        temp = cursor
        n1 += n2;
        while n1 > 0:
            cursor.val = n1 % 10
            n1 //= 10
            if n1 > 0:
                cursor.next = ListNode()
                cursor = cursor.next
        return temp