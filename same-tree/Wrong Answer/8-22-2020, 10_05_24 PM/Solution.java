// https://leetcode.com/problems/same-tree

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode s, TreeNode t) {
         if(s != null && t != null){
            if(s.val == t.val){
                return isSameTree(s.left, t.left) && isSameTree(s.right, t.right);
            }else return false;
        }
        return true;
    }
}