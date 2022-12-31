// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
 void helper(TreeNode root, AtomicInteger sum, StringBuilder n){
        if(root != null){
            n.append(String.valueOf(root.val));

            if(root.left == null && root.right == null){
                int k = Integer.parseInt(n.toString());
                sum.set(sum.addAndGet(k));
            }else{
                helper(root.left, sum, n);
                helper(root.right, sum, n);
            }
            if (n.length() > 0) {
                n.setLength(n.length() - 1);
            }

        }
    }
    int sumNumbers(TreeNode root) {
        AtomicInteger sum = new AtomicInteger();
        sum.set(0);
        StringBuilder n = new StringBuilder();
        helper(root, sum, n);
        return sum.get();
    }
}