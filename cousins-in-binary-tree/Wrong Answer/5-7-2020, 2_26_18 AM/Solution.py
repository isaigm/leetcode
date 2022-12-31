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
                if value == node.val: return k
                elif value < node.val: return search(node.left, value, k + 1)
                else: return search(node.right, value, k + 1)
            else: return -1
        return search(root, x) == search(root, y)