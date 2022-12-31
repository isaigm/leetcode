// https://leetcode.com/problems/valid-number

class Solution {
    public boolean isNumber(String s) {
                s = s.trim();

         if(s.compareTo(".") == 0) return false;
        return s.matches("^\\s*[\\+-]?((\\d+)|(\\d*\\.\\d*)|(\\d+e[\\+-]?\\d+)|(\\d+\\.\\d+e[\\+-]?\\d+))\\s*$");
    }
}