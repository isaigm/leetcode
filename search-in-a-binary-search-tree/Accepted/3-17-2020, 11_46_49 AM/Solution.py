// https://leetcode.com/problems/search-in-a-binary-search-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root == None : return None
        elif root.val == val : return root
        else:
            if val < root.val : return self.searchBST(root.left, val)
            elif val > root.val : return self.searchBST(root.right, val) 