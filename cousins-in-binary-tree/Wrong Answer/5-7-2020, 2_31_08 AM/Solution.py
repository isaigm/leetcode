// https://leetcode.com/problems/cousins-in-binary-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def search(node : TreeNode, value : int, k=0) -> int:
            if node != None:
                if value == node.val: return node, k
                elif value < node.val: return search(node.left, value, k + 1)
                else: return search(node.right, value, k + 1)
            else: return None, -1
        r1, k1 = search(root, x)
        r2, k2 = search(root, y)
        if r1 != None and r2 != None:
            if r1.val != r2.val:
                return k1 == k2
        return False