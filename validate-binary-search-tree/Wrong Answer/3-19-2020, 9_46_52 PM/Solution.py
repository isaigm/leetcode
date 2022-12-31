// https://leetcode.com/problems/validate-binary-search-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
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