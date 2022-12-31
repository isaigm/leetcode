// https://leetcode.com/problems/subtree-of-another-tree

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
   public boolean areEquals(TreeNode s, TreeNode t){
        if ((s == null && t != null) || (s != null && t == null)){
            return false;
        }
        if (s == null && t == null){
            return true;
        }
        else if(s != null && t != null){
            if(s.val == t.val){
                return areEquals(s.left, t.left) && areEquals(s.right, t.right);
            }else return false;
        }
        return false;
    }
    public boolean dfs(TreeNode s, TreeNode t){
        if(s != null && t != null){
            boolean flag = false;
            if(s.val == t.val){
                flag = areEquals(s, t);
                if(flag) return true;
            }
            return dfs(s.left, t) || dfs(s.right, t);

        }
        return false;
    }
    public boolean isSubtree(TreeNode s, TreeNode t) {
        return dfs(s, t);
    }
}