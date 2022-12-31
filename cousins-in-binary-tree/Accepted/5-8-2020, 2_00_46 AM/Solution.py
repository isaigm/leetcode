// https://leetcode.com/problems/cousins-in-binary-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def search(node : TreeNode, value : int, parent=None, k=0) -> int:
            if node == None: return None, -1
            if value == node.val: return parent, k
            r1, k1 = search(node.left, value, node, k + 1)
            if k1 != -1: return r1, k1
            return search(node.right, value, node, k + 1)
        r1, k1 = search(root, x)
        r2, k2 = search(root, y)
        if r1 != None and r2 != None:
            if r1.val != r2.val:
                return k1 == k2
        return False