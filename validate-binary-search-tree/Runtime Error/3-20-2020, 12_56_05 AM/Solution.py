// https://leetcode.com/problems/validate-binary-search-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        left = root.left
        right = root.right
        if root == None : return True
        elif left == None and right == None : return True
        else:
            valid_left = False
            valid_right = False
            if left != None:
                if left.val > root.val:
                    return False
            valid_left = self.isValidBST(left)
            if right != None:
                if right.val < root.val:
                    return False
            valid_right = self.isValidBST(right)
            return valid_left and valid_right