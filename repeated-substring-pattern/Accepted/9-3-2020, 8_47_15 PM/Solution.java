// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
    public boolean repeatedSubstringPattern(String s) {
       return s.matches("^([a-z]+)\\1+$");
    }
}